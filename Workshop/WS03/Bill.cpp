#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace seneca {

    double Bill::totalTax() const {
        int i = 0;
        double total = 0;
        for (i = 0; i < m_noOfItems; i++) {
            total += m_items[i].tax();
        }

        return total;
    }

    double Bill::totalPrice() const {
        int i = 0;
        double total = 0;
        for (i = 0; i < m_noOfItems; i++) {
            total += m_items[i].price();
        }

        return total;
    }

    void Bill::Title() const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.width(36);
            cout << left << m_title << " |" << endl;
        } else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << fixed;

            cout << "|                Total Tax: ";
            cout.width(10);
            cout << right << totalTax() << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout << right << totalPrice() << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << right << totalPrice() + totalTax() << " |" << endl;
        } else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }

    bool Bill::isValid() const {
        if (m_title[0] != '\0' && m_items != nullptr) {
            int i = 0;
            for (i = 0; i < m_noOfItems; i++) {
                if (!m_items[i].isValid())
                    return false;
            }
            return true;
        }

        return false;
    }

    void Bill::init(const char *title, int noOfItems) {
        m_items = nullptr;
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        } else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strncpy(m_title, title, MAX_TITLE_LEN);
            m_title[MAX_TITLE_LEN] = '\0';
            m_items = new Item[m_noOfItems];
            int i = 0;
            for (i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char *item_name, double price, bool taxed) {

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }

        return false;
    }

    void Bill::display() const {
        int i = 0;
        Title();
        if (m_items != nullptr) {
            for (i = 0; i < m_noOfItems; i++) {
                m_items[i].display();
            }
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }
}