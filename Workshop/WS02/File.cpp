//
// Created by Beomgu Jeon on 2024-05-23.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "File.h"

namespace seneca {
    FILE *fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // TODO: read functions go here
    bool read(const char *name) {
        int result = fscanf(fptr, "%[^\n]\n", name);
        return result == 1;
    }

    bool read(int *empNo) {
        int result = fscanf(fptr, "%d,", empNo);
        return result == 1;
    }

    bool read(double *salary) {
        int result = fscanf(fptr, "%lf,", salary);
        return result == 1;
    }
}