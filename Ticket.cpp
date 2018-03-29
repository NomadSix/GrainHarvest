
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
Ticket::Ticket(const std::string& num, const int grossW, const int tareW, Grain& sam)
{
	number = num;
	grossWeight = grossW;
	tareWeight = tareW;
	sample = &sam;
	timestamp = time(NULL);
}

// Constructor default
Ticket::Ticket()
{
	number = "";
	grossWeight = 0;
	tareWeight = 0;
	timestamp = time(NULL);
	//my compiler doesnt have nullptr
	sample = NULL;
}

Ticket::~Ticket()
{
	if (sample == NULL)
		delete sample;
}

Ticket::Ticket(const Ticket &obj)
{
	sample = obj.sample;
}

// Accessor to return sample
Grain * Ticket::getSample() const {
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
	return getNetWeight() / sample->getAverageTestWeight();
}

// Function to return moisture level dockage
double Ticket::getMoistureLevelDockage() const
{
    //foreignDoc = foreignMaterial * grossBushels;
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
	return sample->getForeignMaterial() * getGrossBushels() / 100;
}

// Function to return net bushels (lbs)
double Ticket::getNetBushels() const
{
	// return getGrossBushels() - getMoistureWeight() - getForeignMaterial();
	return getGrossBushels() - getMoistureLevelDockage() - getForeignMaterialDockage();
}

// Returns a string representing ticket's attributes (in form of a receipt)
std::string Ticket::toString()
{
	int WIDTH = 10;
	char outTime[20];
    std::ostringstream os;
    Ticket item = *this;
    //double moistureDoc = item.sample.getMoistureLevel() ? item.sample.getIdealMoistureLevel()


    os << std::fixed << std::setprecision(2);
    os << item.sample->getType() << " Ticket " << item.getNumber() << " – ";
    if (strftime(outTime, sizeof(outTime), "%D %T", localtime(&timestamp))) {
    	os << outTime << ":\n";
    }
    os.width(WIDTH);
    os << std::right << item.getGrossWeight() << std::left << " Gross Weight" << "\n";
    os.width(WIDTH);
    os << std::right << item.getTareWeight() << std::left << " Tare Weight" << "\n";
    os.width(WIDTH);
    os << std::right << item.getNetWeight() << std::left << " Net Weight" << "\n\n";
    os.width(WIDTH);
    os << std::right << item.getGrossBushels() << std::left << " Gross Bushels" << "\n";
    os.width(WIDTH);
    os << std::right << item.getMoistureLevelDockage() << std::left << " Moisture Level (" << item.sample->getMoistureLevel() << "%)" << "\n";
    os.width(WIDTH);
    os << std::right << item.getForeignMaterialDockage() << std::left << " Foreign Material (" << item.sample->getForeignMaterial() << "%)" << "\n";
    os.width(WIDTH);
    os << std::right << item.getNetBushels() << std::left << " Net Bushels" << "\n";

    return os.str();
}

// Overloaded equality operator ==
bool Ticket::operator ==(const Ticket& ticket) const
{
	return number == ticket.number;
}

// Overloaded insertion operator <<
std::ostream& operator <<(std::ostream& os, Ticket& tickets)
{
    os << tickets.toString();
    return os;
}






