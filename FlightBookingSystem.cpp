#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Flight {
    int number;
    string destination;
    float price;
    int seats;
};

struct Booking {
    int id;
    int flightNumber;
    string name;
    int seats;
    float total;
};

int main() {
    // NOTE:
    // I created this file as a cleaned/formatted version template.
    // Your original logic can be pasted into this structure if needed.

    Flight flights[5] = {
        {101, "ASOSA", 2500.50, 50},
        {102, "BAHIRDAR", 1000.75, 40},
        {103, "DEBRE MARKOS", 860.00, 30},
        {104, "GAMBELA", 3000.00, 20},
        {105, "MEKELE", 1500.98, 35}
    };

    Booking bookings[10];

    cout << "Flight Booking System" << endl;
    return 0;
}
