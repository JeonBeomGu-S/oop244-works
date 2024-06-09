//
// Created by Beomgu Jeon on 2024-06-08.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream &Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        } else if (~*this) {
            cout << "  NEW  |         0.00 ";
        } else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    /* Conversion operators */
    Account::operator bool() const {
        return 10000 <= this->m_number && this->m_number <= 99999 && this->m_balance >= 0;
    }

    Account::operator int() const {
        return this->m_number;
    }

    Account::operator double() const {
        return this->m_balance;
    }

    bool Account::operator~() const {
        return this->m_number == 0;
    }

    /* Binary member operators */
    // assignment operator - parameter is int
    Account& Account::operator=(const int accountNumber) {
        if (~(*this)) {
            if (10000 <= accountNumber && accountNumber <= 99999) {
                this->m_number = accountNumber;
            } else {
                setEmpty();
            }
        }
        return *this;
    }

    // assignment operator - parameter is account
    Account& Account::operator=(Account &account) {
        if (!(~(*this)) || !account)
            return *this;

        this->m_number = account.m_number;
        this->m_balance = account.m_balance;

        account.m_number = 0;
        account.m_balance = 0;

        return *this;
    }

    // += operator
    Account& Account::operator+=(const double balance) {
        if (*this && balance >= 0) {
            this->m_balance += balance;
        }

        return *this;
    }

    // -= operator
    Account& Account::operator-=(const double balance) {
        if (*this && balance >= 0 && this->m_balance >= balance) {
            this->m_balance -= balance;
        }

        return *this;
    }

    // left shift operator
    Account& Account::operator<<(Account &account) {
        if (&account != this && *this && account) {
            this->m_balance += account.m_balance;
            account.m_balance = 0;
        }

        return *this;
    }

    // right shift operator
    Account& Account::operator>>(Account &account) {
        if (&account != this && *this && account) {
            account.m_balance += this->m_balance;
            this->m_balance = 0;
        }

        return *this;
    }

    // + operator
    double operator+(const Account &left, const Account &right) {
        if (left && right)
            return (double)left + (double)right;

        return 0;
    }

    double& operator+=(double &left, const Account &right) {
        if (right) {
            left = left + (double)right;
        }

        return left;
    }
}