#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__

#include "Text.h"

namespace seneca {
    class HtmlText : public Text {
        char *m_title {nullptr};
    public:
        HtmlText(const char *filename = nullptr, const char *title = nullptr);

    public:
        // rule of three
        ~HtmlText();
        HtmlText(const HtmlText &);
        HtmlText &operator=(const HtmlText &);
        void write(std::ostream &os) const override;
    };
}
#endif // !SENECA_HTMLTEXT_H__
