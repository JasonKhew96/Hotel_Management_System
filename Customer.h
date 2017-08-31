#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Customer {
    int customerID;
    char customerName[32];
    char customerAddress[32];
    char customerPhone[32];
  public:
    Customer();

    int get_customerID();
    string get_customerName();
    string get_customerAddress();
    string get_customerPhone();

    void set_customerID(int a);
    void set_customerName(string a);
    void set_customerAddress(string a);
    void set_customerPhone(string a);

    void createCustomer();
    void showCustomer();
    void reportCustomer();
    void modifyCustomer();
};

#endif // CUSTOMER_H_INCLUDED
