//
// Created by Beomgu Jeon on 2024-07-05.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "MotorVehicle.h"

using namespace std;

namespace seneca {
    MotorVehicle::MotorVehicle(const char *licensePlateNumber, int builtYear) {
        if (licensePlateNumber != nullptr && licensePlateNumber[0] != '\0')
            strcpy(this->licensePlateNumber, licensePlateNumber);
        this->builtYear = builtYear;
        strcpy(this->address, "Factory");
    }

    void MotorVehicle::moveTo(const char *address) {
        if (strcmp(this->address, address) != 0) {
            cout << "|";
            cout.width(8);
            cout << right << this->licensePlateNumber << "| |";
            cout.width(20);
            cout << right << this->address;
            cout << " ---> ";
            cout.width(20);
            cout << left << address;
            cout << "|" << endl;

            strcpy(this->address, address);
        }
    }

    ostream & MotorVehicle::write(ostream &os) const {
        os << "| " << this->builtYear << " | " << this->licensePlateNumber << " | " << this->address;
        return os;
    }

    std::istream &MotorVehicle::read(istream &in) {
        cout << "Built year: ";
        in >> this->builtYear;
        cout << "License plate: ";
        in >> this->licensePlateNumber;
        cout << "Current location: ";
        in >> this->address;
        return in;
    }

    ostream &operator<<(ostream &os, const MotorVehicle &motorVehicle) {
        return motorVehicle.write(os);
    }

    istream &operator>>(istream &in, MotorVehicle &motorVehicle) {
        return motorVehicle.read(in);
    }
}