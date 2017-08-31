#include "hotelBooking.h"


hotelBooking::hotelBooking() {
    bookingID = 0;
    roomNumber = 0;
    customerID = 0;
    strcpy(customerArrival, "1970-01-01T00:00:00Z");
    strcpy(customerDeparture, "1970-01-01T00:00:00Z");
}

int hotelBooking::get_bookingID() {
    return bookingID;
}
int hotelBooking::get_RoomNumber() {
    return roomNumber;
}
int hotelBooking::get_customerID() {
    return customerID;
}
string hotelBooking::get_customerArrival() {
    return customerArrival;
}
string hotelBooking::get_customerDeparture() {
    return customerDeparture;
}

void hotelBooking::set_bookingID(int a) {
    bookingID = a;
}
void hotelBooking::set_RoomNumber(int a) {
    roomNumber = a;
}
void hotelBooking::set_customerID(int a) {
    customerID = a;
}
void hotelBooking::set_customerArrival(string a) {
    strcpy(customerArrival, a.c_str());
}
void hotelBooking::set_customerDeparture(string a) {
    strcpy(customerDeparture, a.c_str());
}

void hotelBooking::bookRoom() {
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

void hotelBooking::showBooking() {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Customer Arrival: " << customerArrival << endl;
    cout << "Customer Departure: " << customerDeparture << endl;
}

void hotelBooking::reportBooking() {
    cout << left << setw(15)
         << bookingID << setw(15)
         << roomNumber << setw(25)
         << customerArrival << setw(25)
         << customerDeparture << endl;
}

void hotelBooking::modifyBooking() {
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
