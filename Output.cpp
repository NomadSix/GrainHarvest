
// File Name: Output.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <iostream>
#include <iomanip>
#include "Output.h"

using namespace std;

// Output list of tickets
void Output::outputTickets(const Tickets& tickets)
{
	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i].toString() << "\n";
	}
}

// Output summary of totals for list of tickets
void Output::outputSummary(const Tickets& tickets) {
	cout << std::fixed << std::setprecision(2);
	double gross = 0.0;
	double net = 0.0;
	for (int i = 0; i < tickets.size(); i++) {
		Ticket item = tickets[i];
		gross += item.getGrossBushels();
		net += (item.getGrossBushels() - item.getMoistureLevelDockage() - item.getForeignMaterialDockage());
	}
	//cout << allTickets[0].getNumber() << "\n";
	cout << "Harvest Summary Totals\n";
    cout.width(10); cout << right << gross << left << " Gross Bushels" << endl;
    cout.width(10); cout << right << net << left << " Net Bushels" << endl;
}
