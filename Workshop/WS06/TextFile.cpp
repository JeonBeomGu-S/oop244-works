//
// Created by Beomgu Jeon on 2024-06-29.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;
namespace seneca {
    Line::operator const char *() const {
        return (const char *) m_value;
    }

    Line &Line::operator=(const char *lineValue) {
        if (m_value != nullptr) {
            delete[] m_value;
        }
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    Line::Line() {
        m_value = nullptr;
    }

    Line::~Line() {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    /*
     * deletes the m_textLines dynamic array and sets is to nullptr
     * deletes the m_filename dynamic Cstring and sets is to nullptr
     * sets m_noOfLines attribute to zero.
     */
    void TextFile::setEmpty() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfLines = 0;
    }

    /*
     * If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it.
     * If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
     */
    void TextFile::setFilename(const char *fname, bool isCopy) {
        if (!isCopy) {
            m_filename = new char[strlen(fname) + 1];
            m_filename = strcpy(m_filename, fname);
        } else {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        }
    }

    /*
     * Counts the number of lines in the file:
     * Creates a local ifstream object to open the file with the name held in m_filename.
     * Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
     * In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
     * If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)
     */
    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        if (file.is_open()) {
            while (!file.eof()) {
                if (file.get() == '\n')
                    m_noOfLines++;
            }
            m_noOfLines++;
            file.close();
        }
        if (m_noOfLines == 0) {
            setEmpty();
        }
    }

    /*
     * Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
     * If the m_filename is null, this function does nothing.
     *
     * If the m_filename is not null (TextFile is not in a safe empty state ), loadText() will dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
     *
     * Make sure m_textLine is deleted before this to prevent memory leak.
     *
     * Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
     *
     * Since the length of each line is unknown, read the line using a local C++ string object and the getline helper function.
     * (note: this is the HELPER getline function and not a method of istream).
     *
     * In a loop reads each line into the string object and then sets the m_textLines array elements
     * to the values returned by the c_str() method of the string object until the reading fails (end of file reached).
     *
     * After all the lines are read, make sure to update the value of m_noOfline
     * to the actual number of lines read (This covers the possibility of one extra empty line at the end of the file)
     */
    void TextFile::loadText() {
        if (m_filename == nullptr)
            return;

        // To prevent memory leak
        if (m_textLines != nullptr)
            delete[] m_textLines;

        m_textLines = new Line[m_noOfLines];

        ifstream file(m_filename);
        if (file.is_open()) {
            string str;
            int index = 0;
            while (getline(file, str)) {
                m_textLines[index] = str.c_str();
                index++;
            }
            m_noOfLines = index + 1;
            file.close();
        }
    }

    /*
     * Saves the content of the TextFile under a new name.
     * Use a local ofstream object to open a new file using the name kept in the argument filename.
     * Then loop through the elements of the m_textLines array and write them in the opened file adding a new line to the end of each line.
     */
    void TextFile::saveAs(const char *fileName) const {
        ofstream file(fileName);

        if (file.is_open()) {
            int i = 0;
            for (i = 0; i < m_noOfLines - 1; i++) {
                file << m_textLines[i].m_value << '\n';
            }
            file.close();
        }
    }
    /*
     * Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
     */
    TextFile::TextFile(unsigned int pageSize) {
        setEmpty();
        m_pageSize = pageSize;
    }

    /*
     * Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero.
     * Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
     */
    TextFile::TextFile(const char *filename, unsigned int pageSize) {
        m_pageSize = pageSize;
        setEmpty();
        if (filename != nullptr && filename[0] != '\0') {
            setFilename(filename, false);
            setNoOfLines();
            loadText();
        }
    }

    /*
     * Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero.
     * If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely:
     *
     * Sets the file-name to the name of the incoming TextFile object (isCopy set to true) See setFilename()
     * Saves the content of the incoming TextFile under the file name of the current TextFile
     * set the number of lines
     * loads the Text
     */
    TextFile::TextFile(const TextFile &textFile) {
        if (!textFile)
            return;

        setEmpty();
        m_pageSize = textFile.m_pageSize;

        // Set file to copy
        setFilename(textFile.name());
        setNoOfLines();
        loadText();

        // Set file to be copied
        setFilename(textFile.name(), true);
        saveAs(m_filename);
        setNoOfLines();
        loadText();
    }

    /*
     * If the current and the incoming TextFiles are valid it will first delete the current text
     * and then overwrites the current file and data by the content of the incoming TextFile.
     *
     * deallocate the dynamic array of Text and sets the pointer to null
     * Saves the content of the incoming TextFile under the current filename
     * Sets the number of lines
     * loads the Text
     */
    TextFile &TextFile::operator=(const TextFile &textFile) {
        if (*this && textFile) {
            char *originalFileName = new char[strlen(m_filename) + 1];
            strcpy(originalFileName, m_filename);

            setEmpty();
            m_pageSize = textFile.m_pageSize;

            // set file to copy
            setFilename(textFile.name());
            setNoOfLines();
            loadText();

            // Set file to be copied
            setFilename(originalFileName);
            saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    /*
     * Deletes all the dynamic data.
     */
    TextFile::~TextFile() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }

    }

    /*
     * returns m_noOfLines;
     */
    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    /*
     *
     * Prints the filename and then the content of the file "m_pageSize" lines at a time.
     *
     * print the file name
     * underline the file name with '=' character
     * loops through the lines and print them one by line
     * pauses after printing "m_pageSize" lines and prompts the user Hit ENTER to continue... and waits for the user to press enter and repeats until all lines are printed.
     *
     * The function performs no action if the TextFile is in an empty state.
     * This function receives and returns an instance of istream and uses the instance for printouts.
     */
    std::ostream &TextFile::view(ostream &ostr) const {
        if (!(*this))
            return ostr;

        ostr << m_filename << endl;
        ostr << "==========" << endl;

        int i = 0;
        int page = 0;
        bool isFinish = false;

        while (page < (m_noOfLines / m_pageSize) + 1) {
            if (!isFinish) {
                for (i = 0; i < m_pageSize; i++) {
                    if (i + (page * m_pageSize) >= m_noOfLines - 1) {
                        isFinish = true;
                        break;
                    }

                    ostr << m_textLines[i + (page * m_pageSize)].m_value << endl;
                }

                if (!isFinish) {
                    ostr << "Hit ENTER to continue...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    string input;
                    getline(cin, input);
                }
            }
            ++page;
        }
        return ostr;
    }

    /*
     * Receives a filename from istr to set the file name of the TextFile.
     * Then sets the number of lines and loads the Text. When done it will return the istr;
     */
    std::istream &TextFile::getFile(istream &istr) {
        setEmpty();
        char buffer[100];
        istr >> buffer;
        setFilename(buffer);
        setNoOfLines();
        loadText();
        return istr;
    }

    /*
     * Returns the element in the m_textLine array corresponding to the index argument.
     * If the TextFile is in an empty state, it will return null.
     * If the index exceeds the size of the array it should loop back to the beginning.
     * For example, if the number of lines is 10, the last index should be 9 and index 10 should return the first element and index 11 should return the second element.
     */
    const char *TextFile::operator[](unsigned int index) const {
        return !(*this) ? nullptr : m_textLines[index % (m_noOfLines - 1)].m_value;
    }

    /*
     * Returns true if the TextFile is not in an empty state and returns false if it is.
     */
    TextFile::operator bool() const {
        return m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0;
    }

    /*
     * Returns the filename.
     */
    const char *TextFile::name() const {
        return m_filename;
    }

    /*
     * uses the view() method to print the TextFile
     */
    std::ostream &operator<<(std::ostream &ostr, const TextFile &text) {
        return text.view(ostr);
    }

    /*
     * uses the getFile() method to get the file name from console and load the content from the file
     */
    std::istream &operator>>(std::istream &istr, TextFile &text) {
        return text.getFile(istr);
    }
}