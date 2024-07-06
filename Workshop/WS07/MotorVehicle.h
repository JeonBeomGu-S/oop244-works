//
// Created by Beomgu Jeon on 2024-07-05.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>
#include <cstring>

namespace seneca {
    class MotorVehicle {
        char licensePlateNumber[9];
        char address[64];
        int builtYear;

    public:
        MotorVehicle(const char *licensePlateNumber, int builtYear);
        void moveTo(const char *address);
        std::ostream & write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };

    std::ostream &operator<<(std::ostream& os, const MotorVehicle& motorVehicle);
    std::istream &operator>>(std::istream& in, MotorVehicle& motorVehicle);
}

#endif //SENECA_MOTORVEHICLE_H
