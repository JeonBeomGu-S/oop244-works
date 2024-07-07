//
// Created by Beomgu Jeon on 2024-07-06.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "Publication.h"

namespace seneca {
    class Book : public Publication {
        char* m_authorName;

    public:
        Book();

        // Rule of Three
        ~Book();
        Book(const Book& b);
        Book& operator=(const Book& b);

        virtual char type() const override;

        std::ostream &write(std::ostream &os) const override;
        std::istream &read(std::istream &is) override;

        virtual void set(int member_id);
        operator bool() const override;

        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };

    std::ostream &operator<<(std::ostream &os, const Book& right);
    std::istream &operator>>(std::istream &is, Book& right);
}


#endif //SENECA_BOOK_H
