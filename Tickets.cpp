
// File Name: Tickets.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <string.h>
#include "Tickets.h"

// Copy constructor
Tickets::Tickets(const Tickets& tickets)
{
	ticketArrayCapacity = tickets.ticketArrayCapacity;
	ticketArraySize = tickets.size();
	for (unsigned int i = 0; i < tickets.ticketArrayCapacity; i++)
	{
		ticketArray[i] = tickets.ticketArray[i];
	}
}

// Constructor default
Tickets::Tickets()
{
	ticketArray = {};
	ticketArrayCapacity = 0;
	ticketArraySize = 0;
}

// Destructor
Tickets::~Tickets()
{
	delete[] ticketArray;
}

// Add a ticket to the array of tickets
void Tickets::add(const Ticket& ticket)
{
	if (ticketArrayCapacity == size()) {
		// make space
		if (ticketArrayCapacity != 0) {
			ticketArrayCapacity += arrayinc;
		} else {
			ticketArrayCapacity = 1;
		}

		// allocate and move
		Ticket* temp = ticketArray;
		ticketArray = new Ticket[ticketArrayCapacity];
		ticketArray[0] = ticket;
		for (unsigned int i = 0; i < ticketArraySize; i++) {
			ticketArray[i + 1] = temp[i];
		}
	}
	ticketArraySize++;
}

// Return size of array of tickets (number of tickets in array)
int Tickets::size() const
{
	return ticketArraySize;
}

// Overloaded assignment operator =
const Tickets& Tickets::operator =(const Tickets& tickets)
{
//	ticketArray = tickets.ticketArray;
	ticketArrayCapacity = tickets.ticketArrayCapacity;
	ticketArraySize = tickets.size();
	for (unsigned int i = 0; i < tickets.ticketArrayCapacity; i++)
	{
		ticketArray[i] = tickets.ticketArray[i];
	}

}

// Overloaded array operator []
Ticket Tickets::operator [](unsigned int index) const
{
	return ticketArray[index];
}
