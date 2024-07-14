//
// Created by Beomgu Jeon on 2024-07-12.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Line.h"

using namespace std;

namespace seneca {
    Line::Line() : LblShape() {
        m_length = 0;
    }

    Line::Line(const char *label, int length) : LblShape(label) {
        m_length = length;
    }

    void Line::getSpecs(istream &is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream &os) const {
        if (m_length > 0 && LblShape::label() != nullptr) {
            os << LblShape::label() << endl;
            int i = 0;
            for (i = 0; i < m_length; i++) {
                os << '=';
            }
        }
    }
}