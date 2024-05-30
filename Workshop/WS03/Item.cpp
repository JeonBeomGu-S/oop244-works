#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {

    void Item::setName(const char* name) {
        if (name[0] != '\0') {
            if (strlen(name) <= MAX_NAME_LEN)
                strcpy(m_itemName, name);
            else {
                strncpy(m_itemName, name, MAX_NAME_LEN);
                m_itemName[MAX_NAME_LEN] = '\0';
            }
        }
    }

    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = false;
    }
    void Item::set(const char* name, double price, bool taxed) {
        if (price <= 0 || name == nullptr) {
            setEmpty();
        } else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const {
        if (isValid()) {
            cout << "| ";
            cout.width(20);
            cout.fill('.');
            cout << left << m_itemName;
            cout << " | ";
            cout.width(7);
            cout.fill(' ');
            cout << fixed;
            cout.precision(2);
            cout << right << m_price;
            cout << " | ";
            cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
        } else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid() const {
        if (m_itemName[0] != '\0' && m_price > 0.0)
            return true;

        return false;
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        if (m_taxed)
            return m_price * TAX_RATE;
        else
            return 0.0;
    }
}