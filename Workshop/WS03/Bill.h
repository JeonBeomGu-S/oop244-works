//
// Created by Beomgu Jeon on 2024-05-30.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"
#define MAX_TITLE_LEN 36
namespace seneca {
   class Bill {
      char m_title[MAX_TITLE_LEN + 1];
      Item* m_items;
      int m_noOfItems;
      int m_itemsAdded;
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
