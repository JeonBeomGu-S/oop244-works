//
// Created by Beomgu Jeon on 2024-06-01.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#define _CRT_SECURE_NO_WARNINGS

#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

using namespace std;
namespace seneca {

    void Canister::setToDefault() {
        this->m_contentName = nullptr;
        this->m_height = 13.0;
        this->m_diameter = 10.0;
        this->m_contentVolume = 0.0;
        this->m_usable = true;
    }

    void Canister::setName(const char *Cstr) {
        if (Cstr != nullptr && this->m_usable) {
            if (this->m_contentName != nullptr) {
                delete[] this->m_contentName;
                this->m_contentName = nullptr;
            }
            this->m_contentName = new char[strlen(Cstr) + 1];
            strcpy(this->m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty() const {
        return this->m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister &C) const {
        if (C.m_contentName != nullptr && this->m_contentName != nullptr) {
            return strcmp(C.m_contentName, this->m_contentName) == 0;
        }
        return false;
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char *contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char *contentName) {
        setToDefault();
        if (height < MIN_HEIGHT || height > MAX_HEIGHT || diameter < MIN_DIAMETER ||
            diameter > MAX_DIAMETER)
            this->m_usable = false;
        else {
            this->m_height = height;
            this->m_diameter = diameter;
            setName(contentName);
        }
    }

    Canister::~Canister() {
        delete[] this->m_contentName;
        m_contentName = nullptr;
    }

    Canister &Canister::setContent(const char *contentName) {
        if (contentName == nullptr)
            this->m_usable = false;
        else if (this->isEmpty())
            this->setName(contentName);
        else if (!this->hasSameContent(contentName))
            this->m_usable = false;

        return *this;
    }

    Canister &Canister::pour(double quantity) {
        if (this->m_usable && quantity > 0 && quantity + this->volume() <= capacity())
            this->m_contentVolume += quantity;
        else
            this->m_usable = false;
        return *this;
    }

    Canister &Canister::pour(Canister &canister) {
        setContent(canister.m_contentName);
        if (canister.volume() > this->capacity() - this->volume()) {
            canister.m_contentVolume -= this->capacity() - this->volume();
            this->m_contentVolume = this->capacity();
        }
        else {
            pour(canister.volume());
            canister.m_contentVolume = 0.0;
        }
        return *this;
    }

    double Canister::volume() const {
        return this->m_contentVolume;
    }

    std::ostream &Canister::display() const {
        cout.width(7);
        cout << fixed;
        cout.precision(1);
        cout << capacity() << "cc (" << this->m_height << "x" << this->m_diameter  << ") Canister";
        if (!this->m_usable)
            cout << " of Unusable content, discard!";
        else if (this->m_contentName != nullptr){
            cout << " of ";
            cout.width(7);
            cout << this->volume() << "cc   " << this->m_contentName;
        }

        return cout;
    }

    double Canister::capacity() const {
        return PI * (this->m_height - 0.267) * (this->m_diameter / 2) * (this->m_diameter / 2);
    }

    void Canister::clear() {
        delete[] this->m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}