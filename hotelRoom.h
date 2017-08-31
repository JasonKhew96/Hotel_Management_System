#ifndef HOTELROOM_H_INCLUDED
#define HOTELROOM_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class hotelRoom {
    int roomNumber; // 1234
    int roomStatus; // 0 / 1
    int roomCategory; // 1 / 2 / 3 / 4 / 5
  public:
    hotelRoom();

    int get_roomNumber();
    int get_roomStatus();
    int get_roomCategory();

    void set_roomNumber(int a);
    void set_roomStatus(int a);
    void set_roomCategory(int a);

    void createRoom();
    void showRoom();
    void reportRoom();
    void modifyRoom();
};

#endif // HOTELROOM_H_INCLUDED
