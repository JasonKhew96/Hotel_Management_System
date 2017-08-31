#include "Customer.h"

Customer::Customer() {
    customerID = 0;
    strcpy(customerName, "John Doe");
    strcpy(customerAddress, "Main Street");
    strcpy(customerPhone, "601234567890");
}
int Customer::get_customerID() {
    return customerID;
}
string Customer::get_customerName() {
    return customerName;
}
string Customer::get_customerAddress() {
    return customerAddress;
}
string Customer::get_customerPhone() {
    return customerPhone;
}

void Customer::set_customerID(int a) {
    customerID = a;
}
void Customer::set_customerName(string a) {
    strcpy(customerName, a.c_str());
}
void Customer::set_customerAddress(string a) {
    strcpy(customerAddress, a.c_str());
}
void Customer::set_customerPhone(string a) {
    strcpy(customerPhone, a.c_str());
}

void Customer::createCustomer() {
    char inputstr[32];
    cout << "CREATE CUSTOMER\n\n"
         << "Customer Name: ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerName(inputstr);
    cin.clear();
    cout << "Customer Address: ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerAddress(inputstr);
    cin.clear();
    cout << "Customer Phone: ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerPhone(inputstr);
    cin.clear();
}

void Customer::showCustomer() {
    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Customer Address: " << customerAddress << endl;
    cout << "Customer Phone: " << customerPhone << endl;
}

void Customer::reportCustomer() {
    cout << left << setw(15)
         << customerID << setw(25)
         << customerName << setw(25)
         << customerAddress << setw(25)
         << customerPhone << endl;
}

void Customer::modifyCustomer() {
    char inputstr[32];
    cin.ignore();
    cout << "Customer Name (" << customerName << "): ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerName(inputstr);
    cin.clear();
    cout << "Customer Address (" << customerAddress << "): ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerAddress(inputstr);
    cin.clear();
    cout << "Customer Phone (" << customerPhone << "): ";
    cin.getline(inputstr, sizeof(inputstr));
    set_customerPhone(inputstr);
    cin.clear();
}
