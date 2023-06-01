#include "Contact.h"

Contact::Contact(int id, string name, string phone, string email, string address)
    : id(id), name(name), phone(phone), email(email), address(address) {}

string Contact::getName() const
{
    return name;
}

void Contact::displayContact() const
{
    cout << "ID: " << id << endl;
    cout << "Tên: " << name << endl;
    cout << "Số điện thoại: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Địa chỉ: " << address << endl;
}

int Contact::getID() const
{
    return id;
}

void Contact::setID(int newID)
{
    id = newID;
}

string Contact::toString() const
{
    stringstream ss;
    ss << id << " | " << name << " | " << phone << " | " << email << " | " << address;
    return ss.str();
}
