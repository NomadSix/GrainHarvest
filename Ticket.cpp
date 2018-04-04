
// File Name: Ticket.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Ticket.h"
#include <ctime>
#include <sstream>
#include <string>
#include <ostream>
#include <iomanip>
#include <iostream>
#include <string>

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Ticket::Ticket(const std::string& num, const int grossW, const int tareW, Grain* sam)
{
	timestamp = time(NULL);
	number = num;
	grossWeight = grossW;
	tareWeight = tareW;
	if (sam) {
		sample = sam->clone();
	} else {
		sample = NULL;
	}
}

// Constructor default
Ticket::Ticket()
{
	timestamp = time(NULL);
	grossWeight = 0;
	tareWeight = 0;
	sample = NULL;
}

// DeConstructor
Ticket::~Ticket()
{
	if (sample)
		delete sample;
}

// copy constructor
Ticket::Ticket(const Ticket &obj)
{
	timestamp = time(NULL);
	number = obj.number;
	grossWeight = obj.grossWeight;
	tareWeight = obj.tareWeight;
	sample = obj.getSample();
}

// Accessor to return sample
Grain* Ticket::getSample() const
{
	if (!sample)
			return NULL;
	return sample->clone();
}

// Accessor to return time stamp
std::time_t Ticket::getTimestamp() const
{
	return timestamp;
}

// Accessor to return number
std::string Ticket::getNumber() const
{
	return number;
}

// Accessor to return gross weight
int Ticket::getGrossWeight() const
{
	return grossWeight;
}

// Accessor to return tare weight
int Ticket::getTareWeight() const
{
	return tareWeight;
}

// Function to return net weight
int Ticket::getNetWeight() const
{
	return grossWeight - tareWeight;
}

// Function to return gross bushels
double Ticket::getGrossBushels() const
{
	if (!sample)
		return 0.0;
	return getNetWeight() / sample->getAverageTestWeight();
}

// Function to return moisture level dockage
double Ticket::getMoistureLevelDockage() const
{
    //foreignDoc = foreignMaterial * grossBushels;
    if (!sample)
    	return 0;
    double moistureDoc = 0.0;
    if (sample->getMoistureLevel() > sample->getIdealMoistureLevel()) {
    	moistureDoc = sample->getMoistureLevel() - sample->getIdealMoistureLevel();
    	moistureDoc *= getGrossBushels() / 100;
    } else {
    	moistureDoc = 0;
    }
    return moistureDoc;
}

// Function to return foreign material dockage
double Ticket::getForeignMaterialDockage() const
{
	if (!sample)
		return 0.0;
	return sample->getForeignMaterial() * getGrossBushels() / 100;
}

// Function to return net bushels (lbs)
double Ticket::getNetBushels() const
{
	// return getGrossBushels() - getMoistureWeight() - getForeignMaterial();
	return getGrossBushels() - getMoistureLevelDockage() - getForeignMaterialDockage();
}

// Returns a string representing ticket's attributes (in form of a receipt)
std::string Ticket::toString() const
{
	int WIDTH = 10;
	char outTime[20];
    std::ostringstream os;

    os << std::fixed << std::setprecision(2);
    os << sample->toString() << " Ticket " << getNumber() << " – ";
    if (strftime(outTime, sizeof(outTime), "%D %T", localtime(&timestamp))) {
    	os << outTime << ":\n";
    }
    os.width(WIDTH);
    os << std::right << getGrossWeight() << std::left << " Gross Weight" << "\n";
    os.width(WIDTH);
    os << std::right << getTareWeight() << std::left << " Tare Weight" << "\n";
    os.width(WIDTH);
    os << std::right << getNetWeight() << std::left << " Net Weight" << "\n\n";
    os.width(WIDTH);
    os << std::right << getGrossBushels() << std::left << " Gross Bushels" << "\n";
    os.width(WIDTH);
    os << std::right << getMoistureLevelDockage() << std::left << " Moisture Level (" << sample->getMoistureLevel() << "%)" << "\n";
    os.width(WIDTH);
    os << std::right << getForeignMaterialDockage() << std::left << " Foreign Material (" << sample->getForeignMaterial() << "%)" << "\n";
    os.width(WIDTH);
    os << std::right << getNetBushels() << std::left << " Net Bushels" << "\n";

    return os.str();
}

// Overloaded equality operator ==
bool Ticket::operator ==(const Ticket& ticket) const
{
	return number == ticket.number;
}

// Overloaded equal operator =
Ticket& Ticket::operator =(const Ticket& ticket)
{
	if (this == &ticket)
		return *this;
	timestamp = ticket.timestamp;
	number = ticket.number;
	grossWeight = ticket.grossWeight;
	tareWeight = ticket.tareWeight;
	if (sample)
		delete sample;
	sample = ticket.getSample();
	return *this;
}

// Overloaded insertion operator <<
std::ostream& operator <<(std::ostream& os, Ticket& tickets)
{
    os << tickets.toString();
    return os;
}






