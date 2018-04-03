
// File Name: Tickets.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <string.h>
#include "Tickets.h"

namespace {
	const int ARRAY_INC = 5;
}


// Copy constructor
Tickets::Tickets(const Tickets& tickets)
{
	ticketArrayCapacity = tickets.ticketArrayCapacity;
	ticketArraySize = tickets.ticketArraySize;
	ticketArray = new Ticket[ticketArrayCapacity];
	for (unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		ticketArray[i] = tickets.ticketArray[i];
	}
}

// Constructor default
Tickets::Tickets()
{
	ticketArrayCapacity = 0;
	ticketArraySize = 0;
	ticketArray = new Ticket[0];
}

// Destructor
Tickets::~Tickets()
{
	delete[] ticketArray;
}

// Add a ticket to the array of tickets
void Tickets::add(const Ticket& ticket)
{
	if (ticketArrayCapacity == ticketArraySize) {
		// make space
		ticketArrayCapacity += ARRAY_INC;

		// allocate and move
		Ticket* temp = ticketArray;
		ticketArray = new Ticket[ticketArrayCapacity];
		for (unsigned int i = 0; i < ticketArraySize; i++) {
			ticketArray[i] = temp[i];
		}
		delete[] temp;
	}
	ticketArray[ticketArraySize++] = ticket;
}

// Return size of array of tickets (number of tickets in array)
int Tickets::size() const
{
	return ticketArraySize;
}

// Overloaded assignment operator =
const Tickets& Tickets::operator =(const Tickets& tickets)
{
	if (this != &tickets)
		return *this;
	delete[] ticketArray;
	ticketArrayCapacity = tickets.ticketArrayCapacity;
	ticketArraySize = tickets.ticketArraySize;
	ticketArray = new Ticket[ticketArrayCapacity];
	for (unsigned int i = 0; i < tickets.ticketArraySize; i++) {
		ticketArray[i] = tickets.ticketArray[i];
	}
	return *this;
}

// Overloaded array operator []
Ticket Tickets::operator [](unsigned int index) const
{
	return ticketArray[index];
}
