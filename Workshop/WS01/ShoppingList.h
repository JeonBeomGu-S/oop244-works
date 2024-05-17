//
// Created by Beomgu Jeon on 2024-05-17.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H
#include <iostream>
#include "ShoppingRec.h"

namespace seneca {
    const int MAX_NO_OF_RECS = 15;
    extern ShoppingRec recs[MAX_NO_OF_RECS];
    extern int noOfRecs;

    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}

#endif