//
// Created by Beomgu Jeon on 2024-07-06.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Book.h"

using namespace std;

namespace seneca {
    Book::Book() {
        m_authorName = nullptr;
    }

    Book::~Book() {
        if (m_authorName != nullptr) {
            delete[] m_authorName;
            m_authorName = nullptr;
        }
    }

    Book::Book(const Book &b) : Publication(b) {
        if (b.m_authorName != nullptr) {
            m_authorName = new char[strlen(b.m_authorName) + 1];
            strcpy(m_authorName, b.m_authorName);
        }
    }

    Book &Book::operator=(const Book &b) {
        if (this != &b && b.m_authorName != nullptr) {
            delete[] m_authorName;
            m_authorName = new char[strlen(b.m_authorName) + 1];
            strcpy(m_authorName, b.m_authorName);
            Publication::operator=(b);
        }
        return *this;
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream &Book::write(std::ostream &os) const {
        if (!(*this))
            return os;
        Publication::write(os);
        string authorName(m_authorName);

        if (Publication::conIO(os)) {
            os << ' ';
            os.width(SENECA_AUTHOR_WIDTH);
            os.fill(' ');
            if (authorName.length() > SENECA_AUTHOR_WIDTH)
                os << left << authorName.substr(0, SENECA_AUTHOR_WIDTH);
            else
                os << left << authorName;
            os << " |";
        } else {
            os << '\t' << authorName;
        }

        return os;
    }

    std::istream &Book::read(std::istream &is) {
        Publication::read(is);
        char buf[256];

        if (m_authorName != nullptr) {
            delete[] m_authorName;
            m_authorName = nullptr;
        }

        if (Publication::conIO(is)) {
            is.ignore(1000, '\n');
            cout << "Author: ";
            is.get(buf, 256, '\n');
        } else {
            is.ignore(1000, '\t');
            is.get(buf, 256, '\n');
        }

        if (!is.fail() && buf[0] != '\0') {
            m_authorName = new char[strlen(buf) + 1];
            strcpy(m_authorName, buf);
        }

        return is;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const {
        return m_authorName != nullptr && m_authorName[0] != '\0' && Publication::operator bool();
    }

    ostream &Book::operator<<(ostream &os) {
        return write(os);
    }
    istream &Book::operator>>(istream &is) {
        return read(is);
    }

    ostream &operator<<(ostream &os, const Book& right) {
        return right.write(os);
    }
    istream &operator>>(istream &is, Book& right) {
        return right.read(is);
    }
}