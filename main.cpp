#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree contacts;
    int option;
    string surname, givenName, contactInfo;

    cout << "Welcome to the Phone Book Manager!\n";

    do {
        cout << "\nMenu:\n";
        cout << "1) Add a Contact\n";
        cout << "2) Find a Contact\n";
        cout << "3) Delete a Contact\n";
        cout << "4) Print All Contacts\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter Surname: ";
            cin >> surname;
            cout << "Enter Given Name: ";
            cin >> givenName;
            cout << "Enter Contact Info: ";
            cin >> contactInfo;
            contacts.addContact(surname, givenName, contactInfo);
            cout << "Contact added.\n";
            break;
        case 2:
            cout << "Enter Surname: ";
            cin >> surname;
            cout << "Enter Given Name: ";
            cin >> givenName;
            if (TreeNode* result = contacts.findContact(surname, givenName)) {
                cout << "Contact Found: " << result->surname << ", " << result->givenName << ": " << result->contactInfo << "\n";
            } else {
                cout << "Contact not found.\n";
            }
            break;
        case 3:
            cout << "Enter Surname: ";
            cin >> surname;
            cout << "Enter Given Name: ";
            cin >> givenName;
            contacts.removeContact(surname, givenName);
            cout << "Contact deleted (if it existed).\n";
            break;
        case 4:
            cout << "Phone Book:\n";
            contacts.printContacts();
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (option != 0);

    return 0;
}
