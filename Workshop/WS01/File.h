//
// Created by Beomgu Jeon on 2024-05-17.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "ShoppingRec.h"
#include <cstdio>

namespace seneca {
    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
    extern FILE* sfptr;

    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
