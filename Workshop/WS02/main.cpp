/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

//
// Created by Beomgu Jeon on 2024-05-23.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#include "Employee.h"
using namespace seneca;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}