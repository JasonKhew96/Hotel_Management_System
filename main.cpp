#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>

#include "hotelRoom.h"
#include "hotelBooking.h"
#include "Customer.h"

using namespace std;


// Custom functions, unuse
bool isNeedleInHaystack(string haystack, string needle) {
    transform(haystack.begin(), haystack.end(), haystack.begin(), ::tolower);
    transform(needle.begin(), needle.end(), needle.begin(), ::tolower);
    if (haystack.find(needle) != string::npos) {
        return true;
    }
    return false;
}


// Room Functions
bool hotel_checkRoomExist(int n) {
    bool found = false;
    hotelRoom hr;
    fstream File;
    File.open("room.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        return false;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
        if (hr.get_roomNumber() == n) {
            found = true;
        }
    }
    File.close();
    return found;
}

void hotel_newRoom() {
    system("cls");
    hotelRoom hr;
    hr.createRoom();
    if (hotel_checkRoomExist(hr.get_roomNumber())){
        cout << "\nRecord already here =)\n";
        return;
    }
    ofstream outFile;
    outFile.open("room.dat", ios::binary|ios::app);
    outFile.write(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
    outFile.close();
}

void hotel_displayRoom() {
    system("cls");
    int n;
    cout << "\nInput room number (exact): ";
    cin >> n;
    hotelRoom hr;
    bool flag = false;
    ifstream inFile;
    inFile.open("room.dat", ios::binary);
    if (!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    cout << "\n\tROOM DETAILS\n\n";
    while (inFile.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom))) {
        if (hr.get_roomNumber() == n) {
            hr.showRoom();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false) {
        cout << "Room " << n << " does not exist!\n";
    }

}

void hotel_modifyRoom() {
    system("cls");
    int n;
    cout << "\nInput room number (exact): ";
    cin >> n;
    bool found = false;
    hotelRoom hr;
    fstream File;
    File.open("room.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        cout << "\nFile could not open !!\n";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
        if (hr.get_roomNumber() == n) {
            hr.showRoom();
            cout << "\n\nEnter new details to room.\n";
            hr.modifyRoom();
            int pos = (-1)*static_cast<int>(sizeof(hotelRoom));
            File.seekg(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
            cout << "\n\n\tRecord Updated!\n";
            found = true;
        }
    }
    File.close();
    if (found == false) {
        cout << "\n\nRecord not found.\n";
    }
}

void hotel_deleteRoom() {
    system("cls");
    int n;
    cout << "\nInput room number (exact): ";
    cin >> n;
    hotelRoom hr;
    ifstream inFile;
    ofstream outFile;
    inFile.open("room.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom))) {
        if(hr.get_roomNumber() != n) {
            outFile.write(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
        }
    }
    inFile.close();
    outFile.close();
    remove("room.dat");
    rename("temp.dat","room.dat");
    cout<<"\n\n\tRecord Deleted...\n";
}

void hotel_displayAllRoom() {
    system("cls");
    hotelRoom hr;
    ifstream inFile;
    inFile.open("room.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not be open !!\n";
        return;
    }
    cout << "\n\n\t\tROOM LIST\n\n";
    cout << "====================================================\n";
    cout << left << setw(15) << "RoomNumber" << setw(15) << "RoomStatus" << "RoomCategory\n";
    cout << "====================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom))) {
        hr.reportRoom();
    }
    inFile.close();
}

// Booking functions
int hotel_getBookNo(){
    hotelBooking hb;
    int ID = 0;
    ifstream inFile;
    inFile.open("booking.dat", ios::binary);
    if (!inFile) {
        return 1;
    }
    while (inFile.read(reinterpret_cast<char *> (&hb), sizeof(hotelBooking))) {
        if (hb.get_bookingID() > ID) {
            ID = hb.get_bookingID();
        }
    }
    inFile.close();
    return (ID + 1);
}

bool hotel_bookRoomNStatus(int n){
    bool found = false;
    hotelRoom hr;
    fstream File;
    File.open("room.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        return false;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&hr), sizeof(hotelRoom));
        if ((hr.get_roomNumber() == n) && (hr.get_roomStatus() == 0)) {
            found = true;
        }
    }
    File.close();
    return found;
}

bool hotel_checkCustomerExist(int n){
    bool found = false;
    Customer cust;
    fstream File;
    File.open("customer.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        return false;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&cust), sizeof(Customer));
        if (cust.get_customerID() == n) {
            found = true;
        }
    }
    File.close();
    return found;
}

void hotel_bookRoom() {
    system("cls");
    hotelBooking hb;
    hb.bookRoom();
    if (!hotel_bookRoomNStatus(hb.get_RoomNumber())){
        cout << "\nRoom not available, sorry :( ...\n";
        return;
    }
    if (!hotel_checkCustomerExist(hb.get_customerID())){
        cout << "\nCustomer does not exist!\n";
        return;
    }
    hb.set_bookingID(hotel_getBookNo());
    ofstream outFile;
    outFile.open("booking.dat", ios::binary|ios::app);
    outFile.write(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
    outFile.close();
}

void hotel_displayBooking() {
    system("cls");
    hotelBooking hb;
    int n;
    cout << "Input booking ID: ";
    cin >> n;
    bool flag = false;
    ifstream inFile;
    inFile.open("booking.dat", ios::binary);
    if (!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    cout << "\n\tBOOKING DETAILS\n\n";
    while (inFile.read(reinterpret_cast<char *> (&hb), sizeof(hotelBooking))) {
        if (hb.get_bookingID() == n) {
            hb.showBooking();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false) {
        cout << "\nRoom " << n << " does not exist!\n";
    }

}

void hotel_modifyBooking() {
    system("cls");
    bool found = false;
    int n;
    cout << "Input Booking ID: ";
    cin >> n;
    hotelBooking hb;
    fstream File;
    File.open("booking.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        cout << "\nFile could not open !!\n";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
        if (hb.get_bookingID() == n) {
            hb.showBooking();
            cout << "\n\nEnter new details.\n";
            hb.modifyBooking();
            int pos = (-1)*static_cast<int>(sizeof(hotelBooking));
            File.seekg(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
            cout << "\n\n\tRecord Updated!\n";
            found = true;
        }
    }
    File.close();
    if (found == false) {
        cout << "\n\nRecord not found.";
    }
}

void hotel_deleteBooking() {
    system("cls");
    hotelBooking hb;
    int n;
    cout << "Input Booking ID: ";
    cin >> n;
    ifstream inFile;
    ofstream outFile;
    inFile.open("booking.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&hb), sizeof(hotelBooking))) {
        if(hb.get_bookingID() != n) {
            outFile.write(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
        }
    }
    inFile.close();
    outFile.close();
    remove("booking.dat");
    rename("temp.dat","booking.dat");
    cout<<"\n\n\tRecord Deleted ..\n";
}

void hotel_displayAllBooking() {
    system("cls");
    hotelBooking hb;
    ifstream inFile;
    inFile.open("booking.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not be open !!\n";
        return;
    }
    cout<<"\n\n\t\tBooking list\n\n";
    cout<<"=======================================================================================\n";
    cout<< left << setw(15) << "Booking ID" << setw(15) << "Room Number" << setw(25) << "Customer Arrival" << "Customer Departure\n";
    cout<<"=======================================================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&hb), sizeof(hotelBooking))) {
        hb.reportBooking();
    }
    inFile.close();
}


// Customer function
int hotel_getCustNo(){
    Customer cust;
    int ID = 0;
    ifstream inFile;
    inFile.open("customer.dat", ios::binary);
    if (!inFile) {
        return 1;
    }
    while (inFile.read(reinterpret_cast<char *> (&cust), sizeof(Customer))) {
        if (cust.get_customerID() > ID) {
            ID = cust.get_customerID();
        }
    }
    inFile.close();
    return (ID + 1);
}

void hotel_createCustomer() {
    system("cls");
    Customer cust;
    cust.createCustomer();
    cust.set_customerID(hotel_getCustNo());
    ofstream outFile;
    outFile.open("customer.dat", ios::binary|ios::app);
    outFile.write(reinterpret_cast<char *> (&cust), sizeof(Customer));
    outFile.close();
}

void hotel_displayCustomer() {
    system("cls");
    Customer cust;
    int n;
    bool flag = false;
    cout << "\nInput Customer ID: ";
    cin >> n;
    ifstream inFile;
    inFile.open("customer.dat", ios::binary);
    if (!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    cout << "\n\tCUSTOMER DETAILS\n\n";
    while (inFile.read(reinterpret_cast<char *> (&cust), sizeof(Customer))) {
        if (cust.get_customerID() == n) {
            cust.showCustomer();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false) {
        cout << "\nCustomer " << n << " does not exist!\n";
    }

}

void hotel_modifyCustomer() {
    system("cls");
    bool found = false;
    int n;
    Customer cust;
    cout << "Input Customer ID: ";
    cin >> n;
    fstream File;
    File.open("customer.dat", ios::binary|ios::in|ios::out);
    if (!File) {
        cout << "\nFile could not open !!\n";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&cust), sizeof(Customer));
        if (cust.get_customerID() == n) {
            cust.showCustomer();
            cout << "\n\nEnter new details.\n";
            cust.modifyCustomer();
            int pos = (-1)*static_cast<int>(sizeof(Customer));
            File.seekg(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&cust), sizeof(Customer));
            cout << "\n\n\tRecord Updated!\n";
            found = true;
        }
    }
    File.close();
    if (found == false) {
        cout << "\n\nRecord not found.\n";
    }
}

void hotel_deleteCustomer() {
    system("cls");
    Customer cust;
    int n;
    cout << "Input Customer ID: ";
    cin >> n;
    ifstream inFile;
    ofstream outFile;
    inFile.open("customer.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not open !!\n";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&cust), sizeof(Customer))) {
        if(cust.get_customerID() != n) {
            outFile.write(reinterpret_cast<char *> (&cust), sizeof(Customer));
        }
    }
    inFile.close();
    outFile.close();
    remove("customer.dat");
    rename("temp.dat","customer.dat");
    cout<<"\n\n\tRecord Deleted...\n";
}

void hotel_displayAllCustomer() {
    system("cls");
    Customer cust;
    ifstream inFile;
    inFile.open("customer.dat",ios::binary);
    if(!inFile) {
        cout << "\nFile could not be open !!\n";
        return;
    }
    cout<<"\n\n\t\tCustomer list\n\n";
    cout<<"=======================================================================================================\n";
    cout<< left << setw(15) << "Customer ID" << setw(25) << "Customer Name" << setw(25) << "Customer Address" << "Customer Phone\n";
    cout<<"=======================================================================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&cust), sizeof(Customer))) {
        cust.reportCustomer();
    }
    inFile.close();
}









void hotel_roomMenu() {
    char usr_sel;
    do {
        system("cls");
        cout << "===============================\n\n"
             << "\tHOTEL ROOM MENU\n\n"
             << "===============================\n\n"
             << "\t1. Create room\n"
             << "\t2. Search room details\n"
             << "\t3. Modify room details\n"
             << "\t4. Delete room\n"
             << "\t5. Display all room\n\n"
             << "\t0. Return to main menu\n\n"
             << "===============================\n\n"
             << "Please input your selection: ";

        cin >> usr_sel;
        cin.ignore();
        switch(usr_sel) {
        case '1':
            hotel_newRoom();
            system("PAUSE");
            break;
        case '2':
            hotel_displayRoom();
            system("PAUSE");
            break;
        case '3':
            hotel_modifyRoom();
            system("PAUSE");
            break;
        case '4':
            hotel_deleteRoom();
            system("PAUSE");
            break;
        case '5':
            hotel_displayAllRoom();
            system("PAUSE");
            break;
        case '0':
            break;
        default:
            cout << "Invalid input\n";
            system("PAUSE");
        }
    } while(usr_sel != '0');
    return;
}



void hotel_bookingMenu() {
    char usr_sel;
    do {
        system("cls");
        cout << "===============================\n\n"
             << "\tHOTEL BOOKING MENU\n\n"
             << "===============================\n\n"
             << "\t1. Book a room\n"
             << "\t2. Search booking details\n"
             << "\t3. Modify booking details\n"
             << "\t4. Delete booking\n"
             << "\t5. Display all booking\n\n"
             << "\t0. Return to main menu\n\n"
             << "===============================\n\n"
             << "Please input your selection: ";

        cin >> usr_sel;
        cin.ignore();
        switch(usr_sel) {
        case '1':
            hotel_bookRoom();
            system("PAUSE");
            break;
        case '2':
            hotel_displayBooking();
            system("PAUSE");
            break;
        case '3':
            hotel_modifyBooking();
            system("PAUSE");
            break;
        case '4':
            hotel_deleteBooking();
            system("PAUSE");
            break;
        case '5':
            hotel_displayAllBooking();
            system("PAUSE");
            break;
        case '0':
            break;
        default:
            cout << "Invalid input\n";
            system("PAUSE");
        }
    } while(usr_sel != '0');
    return;
}

void hotel_customerMenu() {
    char usr_sel;
    do {
        system("cls");
        cout << "===============================\n\n"
             << "\tHOTEL CUSTOMER MENU\n\n"
             << "===============================\n\n"
             << "\t1. Create customer\n"
             << "\t2. Search customer details\n"
             << "\t3. Modify customer details\n"
             << "\t4. Delete customer\n"
             << "\t5. Display all customer\n\n"
             << "\t0. Return to main menu\n\n"
             << "===============================\n\n"
             << "Please input your selection: ";

        cin >> usr_sel;
        cin.ignore();
        switch(usr_sel) {
        case '1':
            hotel_createCustomer();
            system("PAUSE");
            break;
        case '2':
            hotel_displayCustomer();
            system("PAUSE");
            break;
        case '3':
            hotel_modifyCustomer();
            system("PAUSE");
            break;
        case '4':
            hotel_deleteCustomer();
            system("PAUSE");
            break;
        case '5':
            hotel_displayAllCustomer();
            system("PAUSE");
            break;
        case '0':
            break;
        default:
            cout << "Invalid input\n";
            system("PAUSE");
        }
    } while(usr_sel != '0');
    return;
}


void hotel_MainMenu() {
    char usr_sel;
    do {
        system("cls");
        cout << "===============================\n\n"
             << "\tHOTEL MAIN MENU\n\n"
             << "===============================\n\n"
             << "\t1. Room\n"
             << "\t2. Booking\n"
             << "\t3. Customer\n\n"
             << "\t0. Return\n\n"
             << "===============================\n\n"
             << "\n\nPlease input your selection: ";

        cin >> usr_sel;
        cin.ignore();
        switch(usr_sel) {
        case '1':
            hotel_roomMenu();
            break;
        case '2':
            hotel_bookingMenu();
            break;
        case '3':
            hotel_customerMenu();
            break;
        case '0':
            break;
        default:
            cout << "Invalid input!\n";
            system("PAUSE");
        }
    } while(usr_sel != '0');
    return;
}

int main() {
    hotel_MainMenu();
    return 0;
}
