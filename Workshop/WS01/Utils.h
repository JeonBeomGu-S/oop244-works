//
// Created by Beomgu Jeon on 2024-05-17.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>

namespace seneca {
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif
