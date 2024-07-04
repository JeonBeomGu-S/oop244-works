#include "LibApp.h"
#include "Utils.h"

using namespace std;

namespace seneca {
    bool LibApp::confirm(const char *message) {
        Menu menu(message);
        menu << "Yes";
        if (menu.run() == 1)
            return true;
        else
            return false;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            m_mainMenu.display();
            int mainSelection = getIntMM(0, 4);
            if (mainSelection == 1) newPublication();
            else if (mainSelection == 2) removePublication();
            else if (mainSelection == 3) checkOutPub();
            else if (mainSelection == 4) returnPub();
            else if (m_changed) {
                m_exitMenu.display();
                int exitSelection = getIntMM(0, 2);
                if (exitSelection == 1) {
                    save();
                    done = true;
                }
                else if (exitSelection == 0) {
                    if (confirm("This will discard all the changes are you sure?"))
                        done = true;
                }
            } else {
                done = true;
            }
        }
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    LibApp::LibApp() {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }
}
