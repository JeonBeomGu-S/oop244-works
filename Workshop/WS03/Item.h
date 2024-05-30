//
// Created by Beomgu Jeon on 2024-05-30.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
#define TAX_RATE 0.13
#define MAX_NAME_LEN 20
namespace seneca {
   class Item {
      char m_itemName[MAX_NAME_LEN + 1];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H
