#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {
    MenuItem::MenuItem() {
        name = nullptr;
    }

    MenuItem::MenuItem(const char *str) {
        int len = strlen(str);
        name = new char[len + 1];
        strncpy(name, str, len);
        name[len] = '\0';
    }

    MenuItem::~MenuItem() {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
    }

    MenuItem::operator bool() const {
        return name != nullptr && name[0] != '\0';
    }

    MenuItem::operator const char *() const {
        return (const char *) name;
    }

    void MenuItem::display() const {
        if (name != nullptr && name[0] != '\0')
            cout << name;
    }


    Menu::Menu() {
        title = nullptr;
        noOfItems = 0;
    }

    Menu::Menu(const char *str) {
        int len = strlen(str);
        title = new char[len + 1];
        strncpy(title, str, len);
        title[len] = '\0';
        noOfItems = 0;
    }

    Menu::~Menu() {
        unsigned int i = 0;
        for (i = 0; i < noOfItems; i++) {
            if (menuItems[i] != nullptr)
                delete menuItems[i];
        }
        delete[] title;
    }

    void Menu::display() const {
        if (title != nullptr && title[0] != '\0') {
            cout << title << ":" << endl;
        }
        unsigned int i = 0;
        for (i = 0; i < noOfItems; i++) {
            cout.width(2);
            cout.fill(' ');
            cout << right << (i + 1);
            cout << "- " << (const char*) *menuItems[i] << endl;
        }
        cout << " 0- Exit" << endl << "> ";
    }


    unsigned int Menu::run() {
        display();
        unsigned int menuNum = getIntMM(0, (int) noOfItems);

        return menuNum;
    }

    unsigned int Menu::operator~() {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (noOfItems < MAX_MENU_ITEMS && noOfItems >= 0) {
            menuItems[noOfItems] = new MenuItem(menuItemContent);
            noOfItems++;
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        if (menu.title != nullptr && menu.title[0] != '\0')
            os << menu.title;
        return os;
    }

    Menu::operator int() const {
        return (int) noOfItems;
    }

    Menu::operator unsigned int() const {
        return noOfItems;
    }

    Menu::operator bool() const {
        return noOfItems > 0;
    }

    const char* Menu::operator[](unsigned int index) const {
        return (const char*) *menuItems[index % MAX_MENU_ITEMS];
    }
}