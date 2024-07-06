//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Publication.h"

using namespace std;

namespace seneca {
    Publication::Publication() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
    }

    Publication::Publication(const Publication& p) {
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }

        if (p.m_title != nullptr) {
            m_title = new char[strlen(p.m_title) + 1];
            strcpy(m_title, p.m_title);
        }
        strcpy(m_shelfId, p.m_shelfId);
        m_membership = p.m_membership;
        m_libRef = p.m_libRef;
        m_date = p.m_date;
    }

    Publication &Publication::operator=(const Publication &p) {
        if (this != &p) {
            if (m_title != nullptr) {
                delete[] m_title;
                m_title = nullptr;
            }

            if (p.m_title != nullptr) {
                m_title = new char[strlen(p.m_title) + 1];
                strcpy(m_title, p.m_title);
            }
            strcpy(m_shelfId, p.m_shelfId);
            m_membership = p.m_membership;
            m_libRef = p.m_libRef;
            m_date = p.m_date;
        }

        return *this;
    }

    Publication::~Publication() {
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }
    }

    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char *title) const {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    ostream &Publication::write(ostream &os) const {
        if (!(*this) || !m_date)
            return os;

        if (conIO(os)) {
            os << "| ";
            os.width(SENECA_SHELF_ID_LEN);
            os << m_shelfId;
            os << " | ";
            os.width(SENECA_TITLE_WIDTH);
            os.fill('.');
            os << left << m_title;
            os << " | ";
            m_membership >= 10000 && m_membership < 100000 ?
                os << m_membership : os << " N/A ";
            os << " | ";
            os << m_date;
            os << " |";
        } else {
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
        }

        return os;
    }

    istream &Publication::read(istream &is) {
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        char buf[256];

        if (conIO(is)) {
            cout << "Shelf No: ";
            is >> m_shelfId;

            if (strlen(m_shelfId) != SENECA_SHELF_ID_LEN)
                is.setstate(std::ios::failbit);
            else
                is.ignore();
            cout << "Title: ";
            is.getline(buf, 256);
            if (buf[0] != '\0') {
                m_title = new char[strlen(buf) + 1];
                strcpy(m_title, buf);
            }
            cout << "Date: ";
            is >> m_date;
            if (!m_date)
                is.setstate(std::ios::failbit);
        } else {
            is >> m_libRef;
            is.ignore();
            is.getline(m_shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            is.getline(buf, 256, '\t');
            if (buf[0] != '\0') {
                m_title = new char[strlen(buf) + 1];
                strcpy(m_title, buf);
            }
            is >> m_membership;
            is.ignore();

            is >> m_date;
            if (!m_date)
                is.setstate(std::ios::failbit);
        }

        return is;
    }

    bool Publication::conIO(ios &io) const {
        return &io == &cin || &io == &cout;
    }

    Publication::operator bool() const {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    ostream &Publication::operator<<(ostream &os) {
        return write(os);
    }

    istream &Publication::operator>>(istream &is) {
        return read(is);
    }

    ostream &operator<<(ostream &os, const Publication& right) {
        return right.write(os);
    }
    istream &operator>>(istream &is, Publication& right) {
        return right.read(is);
    }
}