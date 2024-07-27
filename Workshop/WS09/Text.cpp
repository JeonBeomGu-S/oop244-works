#include <fstream>
#include "Text.h"

using namespace std;
namespace seneca {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        fin.close();
        return len;
    }

    const char &Text::operator[](int index) const {
         return m_content[index];
    }

    Text::Text(const char *filename) {
        if (filename != nullptr) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    Text::~Text() {
        if (m_filename != nullptr) {
            delete[] m_filename;
        }

        if (m_content != nullptr) {
            delete[] m_content;
        }
    }
    Text::Text(const Text& right) {
        if (right.m_filename != nullptr) {
            m_filename = new char[strlen(right.m_filename) + 1];
            strcpy(m_filename, right.m_filename);
        }
        if (right.m_content != nullptr) {
            m_content = new char[strlen(right.m_content) + 1];
            strcpy(m_content, right.m_content);
        }
    }

    Text& Text::operator=(const Text& right) {
        if (this != &right) {
            if (m_filename != nullptr) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            if (m_content != nullptr) {
                delete[] m_content;
                m_content = nullptr;
            }

            if (right.m_filename != nullptr) {
                m_filename = new char[strlen(right.m_filename) + 1];
                strcpy(m_filename, right.m_filename);
            }
            if (right.m_content != nullptr) {
                m_content = new char[strlen(right.m_content) + 1];
                strcpy(m_content, right.m_content);
            }
        }

        return *this;
    }

    void Text::read() {
        int lenOfFile = getFileLength();
        m_content = new char[lenOfFile + 1];
        int index = 0;
        ifstream fin(m_filename);
        while (fin) {
            m_content[index] = fin.get();
            index++;
        }
        m_content[lenOfFile] = '\0';
        fin.close();
    }

    void Text::write(ostream &os) const {
        if (m_content != nullptr)
            os << m_content;
    }

    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}