//
// Created by Beomgu Jeon on 2024-07-04.
// Name: Beomgu Jeon
// Email: bgjeon@myseneca.ca
// Student ID: 126428234

//

#include "LibApp.h"
#include "Utils.h"

using namespace std;

namespace seneca {
    LibApp::LibApp() {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_pubTypeMenu << "Book" << "Publication";

        m_noOfLoadedPubs = 0;
        m_lastLibRefNum = 0;

        load();
    }

    LibApp::LibApp(const char* fileName) {
        m_changed = false;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        m_pubTypeMenu << "Book" << "Publication";

        strcpy(m_fileName, fileName);
        m_noOfLoadedPubs = 0;
        m_lastLibRefNum = 0;
        
        load();
    }

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
        ifstream file(m_fileName);
        char type;

        if (file.is_open()) {
            while (file) {
                file >> type;
                file.ignore();
                if (file) {
                    if (type == 'P')
                        m_pubs[m_noOfLoadedPubs] = new Publication();
                    else if (type == 'B')
                        m_pubs[m_noOfLoadedPubs] = new Book();
                    if (m_pubs[m_noOfLoadedPubs] != nullptr) {
                        file >> *m_pubs[m_noOfLoadedPubs];
                        m_lastLibRefNum = m_pubs[m_noOfLoadedPubs]->getRef();
                        m_noOfLoadedPubs++;
                    }
                }
            }

            file.close();
        }
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
        ofstream file(m_fileName);
        int i = 0;
        for (i = 0; i < m_noOfLoadedPubs; i++) {
            if (m_pubs[i]->getRef() != 0)
                file << *m_pubs[i] << endl;
        }
    }

    int LibApp::search(int searchOption) {
        PublicationSelector selector("Select one of the following found matches:");
        char type = getPubTypeFromNumber((int) m_pubTypeMenu.run());
        if (type == 'X') {
            cout << "Aborted!" << endl;
            return -2;
        }

        char title[257];
        cout << "Publication Title: ";
        cin >> title;

        int i = 0;
        for (i = 0; i < m_noOfLoadedPubs; i++) {
            // ToDo: Refactoring the code
            if (m_pubs[i] != nullptr && m_pubs[i]->type() == type && *m_pubs[i] == title) {
                if (searchOption == SENECA_SEARCH_ALL)
                    selector << m_pubs[i];
                else if (searchOption == SENECA_SEARCH_CHECKOUT && m_pubs[i]->onLoan())
                    selector << m_pubs[i];
                else if (searchOption == SENECA_SEARCH_AVAILABLE && !m_pubs[i]->onLoan())
                    selector << m_pubs[i];
            }
        }

        int libRef = -2;
        if (selector) {
            selector.sort();
            libRef = selector.run();
            selector.reset();
        } else {
            cout << "No matches found!" << endl;
        }

        return libRef;
    }

    Publication* LibApp::getPub(int libRef) {
        int i = 0;
        for (i = 0; i < m_noOfLoadedPubs; i++) {
            if (m_pubs[i]->getRef() == libRef)
                return m_pubs[i];
        }

        // if not found, return nullptr
        return nullptr;
    }

    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int libRef = search(SENECA_SEARCH_CHECKOUT);
        Publication* p = getPub(libRef);
        if (p != nullptr) {
            cout << *p << endl;
            if (confirm("Return Publication?")) {
                Date today;
                int days = today - p->checkoutDate();
                if (days > 15) {
                    cout << "Please pay $";
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << 0.5 * (days - 15) << " penalty for being " << (days - 15) << " days late!" << endl;
                }
                p->set(0);
                cout << "Publication returned" << endl;
                m_changed = true;
            }
        }
    }

    void LibApp::newPublication() {
        if (m_noOfLoadedPubs == SENECA_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
            return;
        }

        cout << "Adding new publication to the library" << endl;
        char type = getPubTypeFromNumber((int) m_pubTypeMenu.run());

        if (type == 'X') {
            cout << "Aborted!" << endl;
            return;
        }

        Publication* publication;
        if (type == 'B') {
            publication = new Book();
            publication->read(cin);
        } else if (type == 'P') {
            publication = new Publication();
            publication->read(cin);
        }

        if (cin.fail()) {
            cout << "Aborted!" << endl;
            cin.ignore(1000, '\n');
            return;
        } else if (confirm("Add this publication to the library?")) {
            if (publication) {
                m_lastLibRefNum++;
                publication->setRef(m_lastLibRefNum);
                m_pubs[m_noOfLoadedPubs] = publication;
                m_noOfLoadedPubs++;
                m_changed = true;
                cout << "Publication added" << endl;
            } else {
                cout << "Failed to add publication!" << endl;
                delete[] publication;
            }
        } else {
            cout << "Aborted!" << endl;
            return;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int libRef = search(SENECA_SEARCH_ALL);
        Publication* p = getPub(libRef);
        if (p != nullptr) {
            cout << *p << endl;

            if (confirm("Remove this publication from the library?")) {
                p->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int libRef = search(SENECA_SEARCH_AVAILABLE);
        Publication* p = getPub(libRef);
        if (p != nullptr) {
            cout << *p << endl;

            if (confirm("Check out publication?")) {
                int membership;
                cout << "Enter Membership number: ";
                cin >> membership;
                while (membership < 10000 || membership >= 100000) {
                    cout << "Invalid membership number, try again: " << endl;
                    cin >> membership;
                }
                p->set(membership);
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
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
            if (!done)
                cout << endl;
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}
