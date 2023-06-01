#include <iostream>
#include <windows.h>
#include "PhoneBook.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    PhoneBook phoneBook;
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
