#include "HtmlText.h"

namespace seneca {
    HtmlText::HtmlText(const char *filename, const char *title) : Text(filename) {
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    HtmlText::~HtmlText() {
        if (m_title != nullptr)
            delete[] m_title;
    }

    HtmlText::HtmlText(const HtmlText & htmlText) : Text(htmlText) {
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }

        if (htmlText.m_title != nullptr) {
            m_title = new char[strlen(htmlText.m_title) + 1];
            strcpy(m_title, htmlText.m_title);
        }
    }

    HtmlText &HtmlText::operator=(const HtmlText & htmlText) {
        if (this != &htmlText) {
            if (m_title != nullptr) {
                delete[] m_title;
                m_title = nullptr;
            }

            if (htmlText.m_title != nullptr) {
                m_title = new char[strlen(htmlText.m_title) + 1];
                strcpy(m_title, htmlText.m_title);
            }
            Text::operator=(htmlText);
        }
        return *this;
    }

    void HtmlText::write(std::ostream &os) const {
        bool multipleSpaces = false;
        os << "<html><head><title>";
        os << (m_title == nullptr ? "No Title" : m_title);
        os << "</title></head>\n<body>\n";
        os << "<h1>" << (m_title == nullptr ? "No Title" : m_title) << "</h1>\n";
        int i = 0;
        while ((*this)[i]) {
            switch ((*this)[i]) {
                case ' ':
                    if (multipleSpaces) {
                        os << "&nbsp;";
                    } else {
                        multipleSpaces = true;
                        os << ' ';
                    }
                    break;
                case '<':
                    os << "&lt;";
                    multipleSpaces = false;
                    break;
                case '>':
                    os << "&gt;";
                    multipleSpaces = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    multipleSpaces = false;
                    break;
                default:
                    os << (*this)[i];
                    multipleSpaces = false;
                    break;
            }
            i++;
        }

        os << "</body>\n</html>";
    }
}