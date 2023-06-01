#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Contact.h"

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void displayAllContacts() const;
    void addContact(const Contact& contact);
    void searchContactsByName(const string& name) const;
    void updateContact(int id, const Contact& newContact);
    void deleteContact(int id);
    int countContacts() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
