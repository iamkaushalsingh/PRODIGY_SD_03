#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact(string name, string phone, string email)
        : name(name), phone(phone), email(email) {}
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phone, const string& email) {
        contacts.push_back(Contact(name, phone, email));
    }

    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts found.\n";
        } else {
            for (size_t i = 0; i < contacts.size(); ++i) {
                cout << i + 1 << ". " << contacts[i].name << ", Phone: " << contacts[i].phone << ", Email: " << contacts[i].email << "\n";
            }
        }
    }

    void editContact(int index, const string& name, const string& phone, const string& email) {
        if (index >= 0 && index < contacts.size()) {
            if (!name.empty()) contacts[index].name = name;
            if (!phone.empty()) contacts[index].phone = phone;
            if (!email.empty()) contacts[index].email = email;
        } else {
            cout << "Invalid contact index.\n";
        }
    }

    void deleteContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
        } else {
            cout << "Invalid contact index.\n";
        }
    }
};

int main() {
    ContactManager manager;
    int choice;
    
    while (true) {
        cout << "\nContact Manager\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character after the integer input

        if (choice == 1) {
            string name, phone, email;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter email address: ";
            getline(cin, email);
            manager.addContact(name, phone, email);
        } else if (choice == 2) {
            manager.viewContacts();
        } else if (choice == 3) {
            manager.viewContacts();
            int index;
            cout << "Enter the contact number to edit: ";
            cin >> index;
            cin.ignore();
            string name, phone, email;
            cout << "Enter new name (leave blank to keep unchanged): ";
            getline(cin, name);
            cout << "Enter new phone number (leave blank to keep unchanged): ";
            getline(cin, phone);
            cout << "Enter new email address (leave blank to keep unchanged): ";
            getline(cin, email);
            manager.editContact(index - 1, name, phone, email);
        } else if (choice == 4) {
            manager.viewContacts();
            int index;
            cout << "Enter the contact number to delete: ";
            cin >> index;
            cin.ignore();
            manager.deleteContact(index - 1);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}