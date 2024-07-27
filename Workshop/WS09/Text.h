#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__

#include <iostream>
#include <cstring>

namespace seneca {
    class Text {
        char *m_filename {nullptr};
        char *m_content {nullptr};
        int getFileLength() const;
    protected:
        const char &operator[](int index) const;
    public:
        Text(const char *filename = nullptr);

        // rule of three
        virtual ~Text();
        Text(const Text&);
        Text& operator=(const Text&);

        void read();
        virtual void write(std::ostream &os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SENECA_TEXT_H

