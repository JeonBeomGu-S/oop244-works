/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

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
}