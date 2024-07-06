//
// Created by Beomgu Jeon on 2024-07-05.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace seneca {
    class Truck : public MotorVehicle {
        double capacity;
        double currentCargo;

    public:
        Truck(const char *licensePlateNumber, int builtYear, double capacity, const char *address);

        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);
}


#endif //SENECA_TRUCK_H
