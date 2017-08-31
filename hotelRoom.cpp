#include "hotelRoom.h"


hotelRoom::hotelRoom() {
    roomNumber = 0;
    roomStatus = 0;
    roomCategory = 0;
}

int hotelRoom::get_roomNumber() {
    return roomNumber;
}
int hotelRoom::get_roomStatus() {
    return roomStatus;
}
int hotelRoom::get_roomCategory() {
    return roomCategory;
}

void hotelRoom::set_roomNumber(int a) {
    roomNumber = a;
}
void hotelRoom::set_roomStatus(int a) {
    roomStatus = a;
}
void hotelRoom::set_roomCategory(int a) {
    roomCategory = a;
}

void hotelRoom::createRoom() {
    cout << "CREATE ROOM\n\n";
    cout << "Room Number (1001, 1002, ...): ";
    cin >> roomNumber;
    cout << "Room status (0 = Empty, 1 = Booked): ";
    cin >> roomStatus;
    cout << "Room Category (1, ..., 5): ";
    cin >> roomCategory;
    return;
}

void hotelRoom::showRoom() {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Room Status: " << roomStatus << endl;
    cout << "Room Category: " << roomCategory << endl;
}

void hotelRoom::reportRoom() {
    cout << left << setw(15)
         << roomNumber << setw(15)
         << roomStatus
         << roomCategory << endl;
}

void hotelRoom::modifyRoom() {
    cout << "Room number: " << roomNumber << endl;
    cout << "Room Status (" << roomStatus << "): ";
    cin >> roomStatus;
    cout << "Room Category (" << roomCategory << "): ";
    cin >> roomCategory;
}

