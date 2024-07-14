//
// Created by Beomgu Jeon on 2024-07-12.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Rectangle.h"

using namespace std;

namespace seneca {
    Rectangle::Rectangle() :LblShape() {
        m_width = 0;
        m_height = 0;
    }

    Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label) {
        if (LblShape::label() == nullptr || height < 3 || width < (int) strlen(LblShape::label()) + 2) {
            m_width = 0;
            m_height = 0;
        } else {
            m_width = width;
            m_height = height;
        }
    }

    void Rectangle::getSpecs(istream &is) {
        LblShape::getSpecs(is);
        char separator;
        is >> m_width >> separator >> m_height;
        is.ignore(1000, '\n');
    }

    void Rectangle::draw(ostream &os) const {
        if (m_width > 0 && m_height > 0 && LblShape::label() != nullptr) {
            int i = 0;
            int j = 0;

            // first line
            os << '+';
            for (i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+' << endl;

            // second line
            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << left << LblShape::label();
            os << '|' << endl;

            // third to m_height - 3
            for (i = 0; i < m_height - 3; i++) {
                os << '|';
                for (j = 0; j < m_width - 2; j++) {
                    os << ' ';
                }
                os << '|' << endl;
            }

            // last line
            os << '+';
            for (i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+';
        }
    }
}