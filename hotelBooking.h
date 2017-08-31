#ifndef HOTELBOOKING_H_INCLUDED
#define HOTELBOOKING_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class hotelBooking {
    int bookingID;
    int roomNumber; // 1234
    int customerID;
    char customerArrival[32];
    char customerDeparture[32];

  public:
    hotelBooking();

    int get_bookingID();
    int get_RoomNumber();
    int get_customerID();
    string get_customerArrival();
    string get_customerDeparture();

    void set_bookingID(int a);
    void set_RoomNumber(int a);
    void set_customerID(int a);
    void set_customerArrival(string a);
    void set_customerDeparture(string a);

    void bookRoom();
    void showBooking();
    void reportBooking();
    void modifyBooking();
};

#endif // HOTELBOOKING_H_INCLUDED
