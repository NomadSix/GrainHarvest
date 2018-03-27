// File Name: Wheat.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Wheat.h"
#include <iostream>

using namespace std;

Wheat::Wheat() : Grain(0, 0)
{
}

Wheat::Wheat(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{

}

Wheat::~Wheat()
{
	// TODO Auto-generated destructor stub
}

//return a string representing the calling object’s grain type
std::string Wheat::getType()
{
	return "Wheat";
}

