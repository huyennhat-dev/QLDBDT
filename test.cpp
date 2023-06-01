#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<fcntl.h>
#include <windows.h>
#include<io.h>

using namespace std;

// Khai báo lớp Contact để lưu trữ thông tin của mỗi contact
class Contact {
private:
    int id;
    string name;
    string phone;
    string email;
    string address;

public:
    // Hàm tạo
    Contact(int id, string name, string phone, string email, string address)
        : id(id), name(name), phone(phone), email(email), address(address) {}

    string getName() const { return name; }

    // Phương thức hiển thị thông tin contact
    void displayContact() const {
        cout << "ID: " << id << endl;
        cout << "Tên: " << name << endl;
        cout << "Số điện thoại: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Địa chỉ: " << address << endl;
    }

    // Getter
    int getID() const {
        return id;
    }

    // Setter
    void setID(int newID) {
        id = newID;
    }


    // Hàm chuyển đổi contact sang chuỗi để lưu vào file
    string toString() const {
        stringstream ss;
        ss << id << " | " << name << " | " << phone << " | " << email << " | " << address;
        return ss.str();
    }
};

// Lớp quản lý danh bạ
class PhoneBook {
private:
    vector<Contact> contacts;

public:
    // Phương thức hiển thị toàn bộ danh bạ
    void displayAllContacts() const {
        for (const auto& contact : contacts) {
            contact.displayContact();
            cout << "-------------------" << endl;
        }
    }

    // Phương thức thêm contact vào danh bạ
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // Phương thức tìm contact theo tên
    void searchContactsByName(const string& name) const {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                contact.displayContact();
                cout << "-------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Không tìm thấy contact có tên '" << name << "'." << endl;
        }
    }

    // Phương thức thay đổi thông tin của contact trong danh bạ
    void updateContact(int id, const Contact& newContact) {
        for (auto& contact : contacts) {
            if (contact.getID() == id) {
                contact = newContact;
                return;
            }
        }
        cout << "Không tìm thấy contact có ID " << id << "." << endl;
    }

    // Phương thức xóa contact khỏi danh bạ
    void deleteContact(int id) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getID() == id) {
                contacts.erase(it);
                cout << "Đã xóa contact có ID " << id << "." << endl;
                return;
            }
        }
        cout << "Không tìm thấy contact có ID " << id << "." << endl;
    }

    // Phương thức thống kê số lượng contact trong danh bạ
    int countContacts() const {
        return contacts.size();
    }

    // Phương thức lưu danh bạ vào file
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.toString() << endl;
            }
            file.close();
            cout << "Dữ liệu đã được lưu vào file " << filename << "." << endl;
        }
        else {
            cout << "Không thể mở file " << filename << " để lưu dữ liệu." << endl;
        }
    }

    // Phương thức đọc danh bạ từ file
    void loadFromFile(const string& filename) {
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
            cout << "Dữ liệu đã được khôi phục từ file " << filename << "." << endl;
        }
        else {
            cout << "Không thể mở file " << filename << " để khôi phục dữ liệu." << endl;
        }
    }
};

// Hàm main
int main() {
    SetConsoleOutputCP(CP_UTF8);
    PhoneBook phoneBook;

    // Đọc dữ liệu từ file danhba.data (nếu có)
    phoneBook.loadFromFile("danhba.data");

    int choice;
    do {
        cout << "=======================" << endl;
        cout << "QUẢN LÝ DANH BẠ" << endl;
        cout << "=======================" << endl;
        cout << "1. Hiển thị toàn bộ danh bạ" << endl;
        cout << "2. Thêm contact" << endl;
        cout << "3. Tìm contact theo tên" << endl;
        cout << "4. Thay đổi thông tin contact" << endl;
        cout << "5. Xóa contact" << endl;
        cout << "6. Thống kê số lượng contact" << endl;
        cout << "7. Sao lưu dữ liệu" << endl;
        cout << "8. Khôi phục dữ liệu" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "DANH BẠ" << endl;
            phoneBook.displayAllContacts();
            break;
        }
        case 2: {
            int id;
            string name, phone, email, address;
            cout << "Nhập ID mới: ";
            cin >> id;
            cin.ignore(); // Đọc và bỏ qua ký tự '\n' trong input buffer
            cout << "Nhập tên: ";
            getline(cin, name);
            cout << "Nhập số điện thoại: ";
            getline(cin, phone);
            cout << "Nhập email: ";
            getline(cin, email);
            cout << "Nhập địa chỉ: ";
            getline(cin, address);
            Contact newContact(id, name, phone, email, address);
            phoneBook.addContact(newContact);
            cout << "Đã thêm contact vào danh bạ." << endl;
            break;
        }
        case 3: {
            string name;
            cout << "Nhập tên contact cần tìm: ";
            cin.ignore();
            getline(cin, name);
            phoneBook.searchContactsByName(name);
            break;
        }
        case 4: {
            int id;
            string name, phone, email, address;
            cout << "Nhập ID của contact cần thay đổi thông tin: ";
            cin >> id;
            cin.ignore(); // Đọc và bỏ qua ký tự '\n' trong input buffer
            cout << "Nhập tên mới: ";
            getline(cin, name);
            cout << "Nhập số điện thoại mới: ";
            getline(cin, phone);
            cout << "Nhập email mới: ";
            getline(cin, email);
            cout << "Nhập địa chỉ mới: ";
            getline(cin, address);
            Contact newContact(id, name, phone, email, address);
            phoneBook.updateContact(id, newContact);
            break;
        }
        case 5: {
            int id;
            cout << "Nhập ID của contact cần xóa: ";
            cin >> id;
            phoneBook.deleteContact(id);
            break;
        }
        case 6: {
            int count = phoneBook.countContacts();
            cout << "Số lượng contact trong danh bạ: " << count << endl;
            break;
        }
        case 7: {
            phoneBook.saveToFile("danhba.data");
            break;
        }
        case 8: {
            phoneBook.loadFromFile("danhba.data");
            break;
        }
        case 0: {
            cout << "Chương trình kết thúc." << endl;
            break;
        }
        default: {
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}