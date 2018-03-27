
// File Name: Input.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <iostream>
#include "Input.h"

using namespace std;

//Function (readInt, readDouble, and readString) are used for inline functions input calls
int readInt(istream& in, string output)
{
    int i;
    cout << output;
    cin >> i;
    cin.ignore(256, '\n');
    return i;
}

//Function (readInt, readDouble, and readString) are used for inline functions input calls
double readDouble(istream& in, string output)
{
    double i;
    cout << output;
    cin >> i;
    cin.ignore(256, '\n');
    return i;
}

//Function (readInt, readDouble, and readString) are used for inline functions input calls
string readString(istream& in, string output)
{
    string i;
    cout << output;
    getline(in, i);
    return i;
}

// Return list of tickets (prompt user for tickets, adding each to list of tickets)
void Input::inputTickets(Tickets& tickets)
{
	int i = 1;
	while (true) {
		Ticket curTicket;
		cout << "\nTicket number " << i << " (alphanumeric): ";
		string number = readString(cin, "");
		//Checks if the user inputed anything
		if (number.length() == 0) break;
		//Gets the input for the Current Ticket
		int grossWeight = readInt(cin, "Gross Weight (lbs): ");
		double tareWeight = readDouble(cin, "Tare Weight (lbs): ");
		//double moistureLevel = readDouble(cin, "Moisture Weight (%): ");
		//double foreignMaterial = readDouble(cin, "Foreign Material (%): ");

		Wheat * wheat = new Wheat;
		Soybean * soy = new Soybean;
		Milo * milo = new Milo;

		double mL = readDouble(cin, "Moisture Weight (%): ");
		double fM = readDouble(cin, "Foreign Material (%): ");
		string grainType = readString(cin, "Grain type (w)heat, (s)oybean, (g)rain sorghum: ");
		if (grainType == "w") {
			wheat->setMoistureLevel(mL);
			wheat->setForeignMaterial(fM);
			curTicket = Ticket(number, grossWeight, tareWeight, *wheat);
		} else if (grainType == "s") {
			soy->setMoistureLevel(mL);
			soy->setForeignMaterial(fM);
			curTicket = Ticket(number, grossWeight, tareWeight, *soy);
		} else {
			milo->setMoistureLevel(mL);
			milo->setForeignMaterial(fM);
			curTicket = Ticket(number, grossWeight, tareWeight, *milo);
		}

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
			i += 1;
		}
	}
}
