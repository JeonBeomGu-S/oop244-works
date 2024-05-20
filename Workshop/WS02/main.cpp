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
#include "Employee.h"
using namespace seneca;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}