//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Streamable.h"

using namespace std;

namespace seneca {
    std::ostream &operator<<(std::ostream &os, const Streamable& streamable) {
        if (!streamable)
            return os;
        return streamable.write(os);
    }
    std::istream &operator>>(std::istream &is, Streamable& streamable) {
        return streamable.read(is);
    }
}
