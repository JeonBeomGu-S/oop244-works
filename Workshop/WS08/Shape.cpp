//
// Created by Beomgu Jeon on 2024-07-12.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Shape.h"

namespace seneca {
    std::ostream& operator<<(std::ostream &os, Shape& shape) {
        shape.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream &is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}