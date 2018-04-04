
// File Name: Input.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <iostream>
#include "Input.h"

using namespace std;


//Function (readInt, readDouble, and readString) are used for inline functions input calls
int readInt(istream& in, string output);

//Function (readInt, readDouble, and readString) are used for inline functions input calls
double readDouble(istream& in, string output);

//Function (readInt, readDouble, and readString) are used for inline functions input calls
string readString(istream& in, string output);

// Return list of tickets (prompt user for tickets, adding each to list of tickets)
void Input::inputTickets(Tickets& tickets)
{
	while (true) {
		Ticket curTicket;
		cout << "\nTicket number " << tickets.size() + 1 << " (alphanumeric): ";
		string number = readString(cin, "");
		//Checks if the user inputed anything
		if (number.length() == 0) break;
		//Gets the input for the Current Ticket
		int grossWeight = readInt(cin, "Gross Weight (lbs): ");
		double tareWeight = readDouble(cin, "Tare Weight (lbs): ");

		Grain * sample;

		double mL = readDouble(cin, "Moisture Weight (%): ");
		double fM = readDouble(cin, "Foreign Material (%): ");
		string grainType = readString(cin, "Grain type (w)heat, (s)oybean, (g)rain sorghum: ");
		if (grainType == "w") {
			sample = new Wheat(mL, fM);
		} else if (grainType == "s") {
			sample = new Soybean(mL, fM);
		} else {
			sample = new Milo(mL, fM);
		}
		curTicket = Ticket(number, grossWeight, tareWeight, sample);
		delete sample;
		// check for duplicate tickets
		int count = 0;
		for (int i = 0; i < tickets.size(); i++) {
			if (curTicket == tickets[i] ) {
				count++;
				cout << "\n" << "Error: Duplicate ticket encountered, ticket ignored!\n";
			}
		}
		if (count == 0) {
			tickets.add(curTicket);
		}
	}
}

int readInt(istream& in, string output)
{
    int i;
    cout << output;
    cin >> i;
    cin.ignore(256, '\n');
    return i;
}

double readDouble(istream& in, string output)
{
    double i;
    cout << output;
    cin >> i;
    cin.ignore(256, '\n');
    return i;
}

string readString(istream& in, string output)
{
    string i;
    cout << output;
    getline(in, i);
    return i;
}

