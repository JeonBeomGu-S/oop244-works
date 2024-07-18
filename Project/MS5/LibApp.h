//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H

#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

namespace seneca {
    class LibApp {
        char m_fileName[257];
        Publication* m_pubs[SENECA_LIBRARY_CAPACITY];
        int m_noOfLoadedPubs;
        int m_lastLibRefNum;
        bool m_changed;

        Menu m_mainMenu {"Seneca Library Application"};
        Menu m_exitMenu {"Changes have been made to the data, what would you like to do?"};
        Menu m_pubTypeMenu {"Choose the type of publication:"};

        bool confirm(const char* message);
        void load();
        void save();
        int search(int searchOption);
        Publication* getPub(int libRef);

        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        LibApp(const char* fileName);
        ~LibApp();
        void run();
    };
}
#endif // !SENECA_LIBAPP_H



