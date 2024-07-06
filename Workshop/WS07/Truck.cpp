//
// Created by Beomgu Jeon on 2024-07-05.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Truck.h"

using namespace std;

namespace seneca {
    Truck::Truck(const char *licensePlateNumber, int builtYear, double capacity, const char *address)
                 : MotorVehicle(licensePlateNumber, builtYear) {
        this->capacity = capacity;
        this->currentCargo = 0;
        this->moveTo(address);
    }

    bool Truck::addCargo(double cargo) {
        if (this->capacity == this->currentCargo || cargo == 0) {
            return false;
        }
        if (this->capacity < this->currentCargo + cargo) {
            this->currentCargo = this->capacity;
            return true;
        } else {
            this->currentCargo += cargo;
            return true;
        }
    }

    bool Truck::unloadCargo() {
        if (this->currentCargo == 0)
            return false;
        else {
            this->currentCargo = 0;
            return true;
        }
    }

    ostream &Truck::write(ostream &os) const {
        MotorVehicle::write(os);
        os <<  " | " << this->currentCargo << "/" << this->capacity;
        return os;
    }

    istream &Truck::read(istream &in) {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> this->capacity;
        cout << "Cargo: ";
        in >> this->currentCargo;
        return in;
    }

    ostream& operator<<(ostream& os, const Truck& truck) {
        return truck.write(os);
    }
    istream& operator>>(istream& in, Truck& truck) {
        return truck.read(in);
    }
}