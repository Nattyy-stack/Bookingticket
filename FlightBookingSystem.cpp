#include <iostream>   // For input and output
#include <iomanip>    // For making output look nice

using namespace std;

// Structure to store flight information
struct Flight {
    int number;          // Flight number
    string destination;  // Where the flight goes
    float price;        // Ticket price
    int seats;          // Available seats
};

// Structure to store booking information
struct Booking {
    int id;             // Booking ID
    int flightNumber;   // Which flight was booked
    string name;        // Passenger name
    int seats;          // How many seats booked
    float total;        // Total price
};

int main() {
    // Create arrays to store flights and bookings
    Flight flights[5];      // Array of 5 flights
    Booking bookings[10];   // Array of 10 bookings
    
    // Let's add some flights to our system
    flights[0] = {101, "ASOSA", 2500.50, 50};
    flights[1] = {102, "BAHIRDAR", 1000.75, 40};
    flights[2] = {103, "DEBRE MARKOS",860.00, 30};
    flights[3] = {104, "GAMBELA", 3000, 20};
    flights[4] = {105, "MEKELE", 1500.98, 35};
    
  int totalFlights = 5;      // We have 5 flights
  int totalBookings = 0;     // No bookings yet
  int bookingId = 1001;      // Starting booking ID
    
   int choice;                // To store user's menu choice
    
    cout <<  setw(60) << string(30,'*')<<endl;
   
    cout <<  setw(31) << string(1,'*') <<"   FLIGHT BOOKING SYSTEM    "<<string(1,'*')<<endl;
    
     cout <<  setw(60) << string(30,'*')<<endl;
    
do {
        // Display menu
        cout << setw(38) << string(8,'=')<< " MAIN MENU "<< string(15,'=')<<endl;
        cout << setw(50) << "1. View All Flights\n";
        cout << setw(47) <<  "2. Book a Ticket\n";
        cout << setw(50) << "3. View My Bookings\n";
        cout << setw(48) <<  "4. Cancel Booking\n";
        cout <<  setw(38) << "5. Exit\n";
        cout << setw(65)<<string(35,'=')<<endl;
        cout << setw(50) <<  "Enter your choice: ";
        cin >> choice;
        cout<< endl;
        
        // Menu options using switch statement
switch(choice) {
            
    case 1: // View all flights
                cout << setw(40)<< string(10,'-')<< " ALL FLIGHTS"<<string(10,'-')<<endl;
                cout<<endl;
                cout << setw(30)<<"Flight No."<<setw(20)<<    " Destination "<<setw(20)<<      "Price(BIRR)"<<setw(20)<<"Seats;"<<endl;
                cout << "                    ----------------------------------------------------------------------\n";
                
for(int i = 0; i < totalFlights; i++) {
              cout << setw(25)      << flights[i].number;
               cout << setw(24)   << flights[i].destination;
               cout << setw(19) << flights[i].price;
            cout << setw(20) << flights[i].seats << endl;
               cout<<endl;
                }
                break;
                
 case 2: // Book a ticket
                {
            cout <<  setw(40)<< string(10,'-')<< " BOOK A TICKET " << string(10,'-') <<endl;
                   
                // Show available flights
            cout << setw(58)<< "Available Flights:\n";
              cout<<endl;                                                             
for(int i = 0; i < totalFlights; i++) {
            cout << setw(31)<< i+1 << ". Flight " << flights[i].number 
                             << " to " << flights[i].destination 
                             << " (" << flights[i].price 
                             << " BIRR) - " << flights[i].seats << " seats left\n"<<endl;
                    }
                    
             // Ask which flight to book
         int flightChoice;
            cout << setw(60) << "Enter flight number to book: " ;
             cin >> flightChoice;
                cout<<endl;
                    
          // Check if flight exists
             bool found = false;
            int flightIndex = -1;
for(int i = 0; i <totalFlights; i++) { 
        if(flights[i].number == flightChoice) 
               found = true;
               flightIndex = i;
                 break;
                        }
                    }
                    
      if(!found) {
         cout << setw(60)<< "Sorry, flight not found!"<<endl;
                break;
               cout<<endl;
                    }
                    
        // Check if seats are available
    if(flights[flightIndex].seats == 0) {
      cout << setw(57)<< "Sorry, this flight is full!" <<endl;
           cout<<endl;
                 break;
                    }
                    
    // Ask for passenger details
        string passengerName;
           cout << setw(53) << "Enter passenger name: ";
        cin.ignore();  // Clear input buffer
          getline(cin, passengerName);
            cout<<endl;
                    
     // Ask how many seats
     int seatCount;
             cout << setw(53) << "How many seats? (Max " << flights[flightIndex].seats << "): ";
             cin >> seatCount;
            cout<<endl;
    // Check if enough seats
  if(seatCount > flights[flightIndex].seats || seatCount <= 0) {
           cout <<setw(58)<< "nInvalid number of seats!"<<endl;
        cout<<endl;
             break;
                    }
                    
     // Calculate total price
  float totalPrice = seatCount * flights[flightIndex].price;
                    
     // Create booking
        bookings[totalBookings].id = bookingId;
       bookings[totalBookings].flightNumber = flightChoice;
       bookings[totalBookings].name = passengerName;         
       bookings[totalBookings].seats = seatCount;
      bookings[totalBookings].total = totalPrice;
                
     // Update flight seats
         flights[flightIndex].seats -= seatCount;
                    
     // Show confirmation
          cout << setw(43) << string(15,'-') << "BOOKING CONFIRMED" << string(15,'-')<< endl;
           cout << setw(42) << "Booking ID: " << bookingId << endl;
           cout << setw(41) << "Passenger: " << passengerName << endl;
          cout << setw(38) << "Flight: " << flightChoice << " to " 
                         << flights[flightIndex].destination << endl;
     cout << setw(37) << "Seats: " << seatCount << endl;
       cout << setw(36) << "Total:" << totalPrice <<" BIRR" <<endl;
                    cout <<endl;
         // Update counters
           totalBookings++;
           bookingId++;
         }
             break;
case 3: // View bookings
    cout << setw(40)<< string(10,'~')<< " MY BOOKINGS" << string(12,'~')<<endl;
                cout <<endl;
                
      if(totalBookings == 0) {
                    cout << setw(55)<< "No bookings found" <<endl;
                    cout <<endl;
                } else {
                    cout << setw(32) << "ID" <<  setw(12) <<"Flight" << setw(14) <<"Passenger" << setw(14) << "Seats"<< setw(16)<<"Total(BIRR)"<<endl;
                    cout << "                              ----------------------------------------------------------" <<endl;
                    
for(int i = 0; i < totalBookings; i++) {
                        cout << setw(34) << bookings[i].id;
                       cout << setw(8) << bookings[i].flightNumber;
                        cout << setw(14) << bookings[i].name;
                        cout << setw(14) << bookings[i].seats;
                        cout <setw(12) << bookings[i].total << endl;
                    cout<<endl;
                    }
                }
                break;
                
case 4: // Cancel booking
                {
                    cout << setw(40) <<  string(10,'-')<<  "CANCEL BOOKING " << string(10,'-')<<endl;
                    cout<<endl;
                    
     if(totalBookings == 0) {
                        cout << setw(57) << "No bookings to cancel." <<endl;
                        cout<<endl;
break;
                    }
                    
                    // Show all bookings
                    cout << setw(55)<< "Your bookings:" <<endl;
for(int i = 0; i < totalBookings; i++) {
                        cout << setw(31)<< i+1 << ". Booking ID: " << bookings[i].id 
                             << " - Flight: " << bookings[i].flightNumber
                             << " - " << bookings[i].name << endl;
                             cout<<endl;
                    }
                    
       // Ask which booking to cancel
       int cancelId;
        cout << setw(59)<< "Enter booking ID to cancel: ";
         cin >> cancelId;
         cout<< endl;
         // Find the booking
     bool bookingFound = false;
           int bookingIndex = -1;
                    
for(int i = 0; i < totalBookings; i++) {
      if(bookings[i].id == cancelId) {
           bookingFound = true;
           bookingIndex = i;
                       break;
                        }
                    }
                    
         if(!bookingFound) {
                  cout << setw(59)<< "Booking ID not found!" <<endl;
                  cout<<endl;
            break;
                    }
                    
     // Find the flight to return seats
     for(int i = 0; i < totalFlights; i++) {
         if(flights[i].number == bookings[bookingIndex].flightNumber) {
                            flights[i].seats += bookings[bookingIndex].seats;
                            break;
                        }
                    }
                    
                    // Remove booking by shifting
  for(int i = bookingIndex; i < totalBookings - 1; i++) {
                        bookings[i] = bookings[i + 1];
                    }
                    
                    totalBookings--;
                    cout << setw(63)<< "Booking cancelled successfully!"<<endl;
                    cout<<endl;
       }
                break;
                
case 5: // Exit
                cout <<  setw(77)<< "Thank you for using our Flight Booking System!" <<endl;
                cout<<endl;
                cout <<  setw(50)<< "Goodbye!"<<endl;
                break;
                
default:
                cout <<  setw(54)<< "Please choose 1-5 only!"<<endl;
                cout<<endl;
        }
        
    } while(choice != 5);  // Repeat until user chooses exit
    
    return 0;
}               
