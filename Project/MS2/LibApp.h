//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H

#include "Menu.h"
#include <iostream>

namespace seneca {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu {"Seneca Library Application"};
        Menu m_exitMenu {"Changes have been made to the data, what would you like to do?"};

        bool confirm(const char* message);
        void load();
        void save();
        void search();
        void returnPub();

        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        void run();
    };
}
#endif // !SENECA_LIBAPP_H



