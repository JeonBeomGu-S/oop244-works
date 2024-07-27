//
// Created by Beomgu Jeon on 2024-07-27.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_

#include <iostream>

using namespace std;

namespace seneca {
    template<typename T, typename U>
    bool search(Collection<T> &ref, T array[], int size, U target) {
        bool result = false;
        int i = 0;
        for (i = 0; i < size; i++) {
            if (array[i] == target) {
                result = true;
                ref.add(array[i]);
            }
        }
        return result;
    }

    template<typename T>
    void listArrayElements(const char *title, const T array[], int size) {
        cout << title << endl;
        int i = 0;
        for (i = 0; i < size; i++) {
            cout << (i + 1) << ": " << array[i] << endl;
        }
    }

}

#endif