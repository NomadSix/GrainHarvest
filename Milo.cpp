// File Name: Milo.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Milo.h"
#include <string>

using namespace std;

// no arg constructor
Milo::Milo() : Grain(0, 0)
{
	// TODO Auto-generated constructor stub

}

// 2 arg constructor
Milo::Milo(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{
	// TODO Auto-generated constructor stub

}

Milo::~Milo()
{
	// TODO Auto-generated destructor stub
}

// returns the type of grain as a string
std::string Milo::getType()
{
	return "Grain Sorghum";
}
