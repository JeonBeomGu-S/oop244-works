//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "Utils.h"

using namespace std;

namespace seneca {
    int getIntMM(int min, int max) {
        int input = -1;
        do {
            cin >> input;
            if (cin.fail() || input < min || input > max) {
                cout << "Invalid Selection, try again: ";
                input = -1;
            }

            cin.clear();
            // clear input buffer
            char ch = 'x';
            while (ch != '\n') {
                ch = cin.get();
            }
        } while (cin.fail() || input < min || input > max);

        return input;
    }

    char getPubTypeFromNumber(int number) {
        switch (number) {
            case 1:
                return 'B';
            case 2:
                return 'P';
            default:
                return 'X';
        }
    }
}