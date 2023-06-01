#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Contact {
private:
    int id;
    string name;
    string phone;
    string email;
    string address;

public:
    Contact(int id, string name, string phone, string email, string address);
    string getName() const;
    void displayContact() const;
    int getID() const;
    void setID(int newID);
    string toString() const;
};

#endif
