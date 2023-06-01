#include "PhoneBook.h"

void PhoneBook::displayAllContacts() const {
    for (const auto& contact : contacts) {
        contact.displayContact();
       cout << "-------------------" <<endl;
    }
}

void PhoneBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void PhoneBook::searchContactsByName(const string& name) const {
    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            contact.displayContact();
           cout << "-------------------" <<endl;
            found = true;
        }
    }
    if (!found) {
       cout << "Không tìm thấy contact có tên '" << name << "'." <<endl;
    }
}

void PhoneBook::updateContact(int id, const Contact& newContact) {
    for (auto& contact : contacts) {
        if (contact.getID() == id) {
            contact = newContact;
            return;
        }
    }
   cout << "Không tìm thấy contact có ID " << id << "." <<endl;
}

void PhoneBook::deleteContact(int id) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getID() == id) {
            contacts.erase(it);
           cout << "Đã xóa contact có ID " << id << "." <<endl;
            return;
        }
    }
   cout << "Không tìm thấy contact có ID " << id << "." <<endl;
}

int PhoneBook::countContacts() const {
    return contacts.size();
}

void PhoneBook::saveToFile(const string& filename) const {
   ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.toString() <<endl;
        }
        file.close();
       cout << "Dữ liệu đã được lưu vào file " << filename << "." <<endl;
    }
    else {
       cout << "Không thể mở file " << filename << " để lưu dữ liệu." <<endl;
    }
}

void PhoneBook::loadFromFile(const string& filename) {
    contacts.clear();
   ifstream file(filename);
    if (file.is_open()) {
       string line;
        while (getline(file, line)) {
           stringstream ss(line);
            int id;
           string name, phone, email, address;
            char separator;
            ss >> id >> separator;
            getline(ss, name, '|');
            getline(ss, phone, '|');
            getline(ss, email, '|');
            getline(ss, address, '|');
            contacts.emplace_back(id, name, phone, email, address);
        }
        file.close();
       cout << "Dữ liệu đã được khôi phục từ file " << filename << "." <<endl;
    }
    else {
       cout << "Không thể mở file " << filename << " để khôi phục dữ liệu." <<endl;
    }
}
