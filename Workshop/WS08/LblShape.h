//
// Created by Beomgu Jeon on 2024-07-12.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#ifndef WS08_LBLSHAPE_H
#define WS08_LBLSHAPE_H

#include <cstring>
#include "Shape.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label {nullptr};
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        virtual ~LblShape();
        LblShape(const LblShape& lblShape) = delete;
        LblShape& operator=(const LblShape& lblShape) = delete;
        void getSpecs(std::istream& is) override;
    };
}


#endif //WS08_LBLSHAPE_H
