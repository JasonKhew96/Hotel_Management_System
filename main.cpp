#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


// CLASS hotelRoom start
class hotelRoom {
    int roomNumber; // 1234
    int roomStatus; // 0 / 1
    int roomCategory; // 1 / 2 / 3 / 4 / 5
  public:
    hotelRoom() {
        roomNumber = 0;
        roomStatus = 0;
        roomCategory = 0;
    }

    int get_roomNumber() {
        return roomNumber;
    }
    int get_roomStatus() {
        return roomStatus;
    }
    int get_roomCategory() {
        return roomCategory;
    }

    void set_roomNumber(int a) {
        roomNumber = a;
    }
    void set_roomStatus(int a) {
        roomStatus = a;
    }
    void set_roomCategory(int a) {
        roomCategory = a;
    }

    void createRoom() {
        cout << "CREATE ROOM\n\n";
        cout << "Room Number (1001, 1002, ...): ";
        cin >> roomNumber;
        cout << "Room status (0 = Empty, 1 = Booked): ";
        cin >> roomStatus;
        cout << "Room Category (1, ..., 5): ";
        cin >> roomCategory;
        return;
    }

    void showRoom() {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Room Status: " << roomStatus << endl;
        cout << "Room Category: " << roomCategory << endl;
    }

    void reportRoom() {
        cout << left << setw(15)
             << roomNumber << setw(15)
             << roomStatus
             << roomCategory << endl;
    }

    void modifyRoom() {
        cout << "Room number: " << roomNumber << endl;
        cout << "Room Status (" << roomStatus << "): ";
        cin >> roomStatus;
        cout << "Room Category (" << roomCategory << "): ";
        cin >> roomCategory;
    }

};
// CLASS hotelRoom end


// CLASS hotelBooking start
class hotelBooking {
    int bookingID;
    int roomNumber; // 1234
    int customerID;
    char customerArrival[32];
    char customerDeparture[32];

  public:
    hotelBooking() {
        bookingID = 0;
        roomNumber = 0;
        customerID = 0;
        strcpy(customerArrival, "1970-01-01T00:00:00Z");
        strcpy(customerDeparture, "1970-01-01T00:00:00Z");
    }

    int get_bookingID(){
        return bookingID;
    }
    int get_RoomNumber() {
        return roomNumber;
    }
    int get_customerID() {
        return customerID;
    }
    string get_customerArrival() {
        return customerArrival;
    }
    string get_customerDeparture() {
        return customerDeparture;
    }

    void set_bookingID(int a){
        bookingID = a;
    }
    void set_RoomNumber(int a) {
        roomNumber = a;
    }
    void set_customerID(int a){
        customerID = a;
    }
    void set_customerArrival(string a) {
        strcpy(customerArrival, a.c_str());
    }
    void set_customerDeparture(string a) {
        strcpy(customerDeparture, a.c_str());
    }

    void bookRoom() {
        char inputstr[32];
        cout << "\n\nBookRoom\n\n";
        cout << "Room Number (1001): ";
        cin >> roomNumber;
        cout << "Customer ID (123): ";
        cin >> customerID;
        cin.ignore();
        cout << "Customer Arrival (1970-01-01T00:00:00Z)(UTC): ";
        cin.getline(inputstr, sizeof(inputstr));
        set_customerArrival(inputstr);
        cin.clear();
        cout << "Customer Departure (1970-01-01T00:00:00Z)(UTC): ";
        cin.getline(inputstr, sizeof(inputstr));
        set_customerDeparture(inputstr);
        cin.clear();
    }

    void showBooking() {
        cout << "Booking ID: " << bookingID << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Customer Arrival: " << customerArrival << endl;
        cout << "Customer Departure: " << customerDeparture << endl;
    }

    void reportBooking() {
        cout << left << setw(15)
             << bookingID << setw(15)
             << roomNumber << setw(25)
             << customerArrival << setw(25)
             << customerDeparture << endl;
    }

    void modifyBooking() {
        char inputstr[21];
        cout << "Room number (" << roomNumber << "): ";
        cin >> roomNumber;
        cout << "Customer Arrival (" << customerArrival << "): ";
        cin.getline(inputstr, sizeof(inputstr));
        set_customerArrival(inputstr);
        cin.clear();
        cout << "Customer Departure (" << customerDeparture << "): ";
        cin.getline(inputstr, sizeof(inputstr));
        set_customerDeparture(inputstr);
        cin.clear();
    }
};
// CLASS hotelBooking end

// CLASS customer start
class Customer {
    int customerID;
    char customerName[32];
    char customerAddress[32];
    char customerPhone[32];
  public:
    Customer() {
        customerID = 0;
        strcpy(customerName, "John Doe");
        strcpy(customerAddress, "Main Street");
        strcpy(customerPhone, "601234567890");
    }
    int get_customerID(){
        return customerID;
    }
    string get_customerName() {
        return customerName;
    }
    string get_customerAddress() {
        return customerAddress;
    }
    string get_customerPhone() {
        return customerPhone;
    }

    void set_customerID(int a){
        customerID = a;
    }
    void set_customerName(string a) {
        strcpy(customerName, a.c_str());
    }
    void set_customerAddress(string a) {
        strcpy(customerAddress, a.c_str());
    }
    void set_customerPhone(string a) {
        strcpy(customerPhone, a.c_str());
    }

    void createCustomer() {
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

    void showCustomer() {
        cout << "Customer ID: " << customerID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << customerAddress << endl;
        cout << "Customer Phone: " << customerPhone << endl;
    }

    void reportCustomer() {
        cout << left << setw(15)
             << customerID << setw(25)
             << customerName << setw(25)
             << customerAddress << setw(25)
             << customerPhone << endl;
    }

    void modifyCustomer() {
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
};
// CLASS Customer end




// Custom functions, no use yet
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
        if (hb.get_RoomNumber() == n) {
            hb.showBooking();
            cout << "\n\nEnter new details.\n";
            hb.modifyBooking();
            int pos = (-1)*static_cast<int>(sizeof(hotelBooking));
            File.seekg(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
            cout << "\n\n\tRecord Updated!";
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
        if(hb.get_RoomNumber() != n) {
            outFile.write(reinterpret_cast<char *> (&hb), sizeof(hotelBooking));
        }
    }
    inFile.close();
    outFile.close();
    remove("booking.dat");
    rename("temp.dat","booking.dat");
    cout<<"\n\n\tRecord Deleted ..";
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
    cout<<"\n\n\tRecord Deleted...";
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
