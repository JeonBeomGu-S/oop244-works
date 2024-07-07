//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include <iostream>
#include <cstring>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
#include "Utils.h"

namespace seneca {
    class Publication : public Streamable {
        char *m_title;
        char m_shelfId[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();

        // Rule of Three - Copy Constructor, Copy Assignment Overloading, and Destructor
        Publication(const Publication& p);
        Publication& operator=(const Publication& p);
        ~Publication();

        // Modifiers
        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system.

        // Queries
        virtual char type()const;
        //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;
        //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate()const;
        //Returns the date attribute
        bool operator==(const char* title)const;
        //Returns true if the argument title appears anywhere in the title of the
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;
        //Returns the title attribute
        int getRef()const;
        //Returns the libRef attirbute.

        // Streamable pure virtual function
        std::ostream &write(std::ostream &os) const override;
        std::istream &read(std::istream &is) override;
        bool conIO(std::ios &io) const override;
        operator bool() const override;
        std::ostream &operator<<(std::ostream &os) override;
        std::istream &operator>>(std::istream &is) override;
    };

    std::ostream &operator<<(std::ostream &os, const Publication& right);
    std::istream &operator>>(std::istream &is, Publication& right);
}


#endif //SENECA_PUBLICATION_H
