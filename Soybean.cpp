// File Name: Soybean.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Soybean.h"
#include <string>

using namespace std;

Soybean::Soybean() : Grain(0, 0)
{

}

Soybean::Soybean(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial)
{

}

Soybean::~Soybean()
{
}

//return a string representing the calling object’s grain type
std::string Soybean::getType()
{
	return "Soybean";
}
