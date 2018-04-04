// File Name: Milo.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Milo.h"
#include <string>

using namespace std;

namespace {
	const double AVERAGE_TEST_WEIGHT = 56.0;
	const double IDEAL_MOISTURE_LEVEL = 13.0;
	const std::string GRAIN_TYPE = "Grain Sorghum";
}

// no arg constructor
Milo::Milo() : Grain(){}

// 2 arg constructor
Milo::Milo(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial){}

// deconstructor
Milo::~Milo(){}

// returns the type of grain as a string
const std::string Milo::getType() const
{
	return GRAIN_TYPE;
}

const double Milo::getAverageTestWeight() const
{
	return AVERAGE_TEST_WEIGHT;
}

const double Milo::getIdealMoistureLevel() const
{
	return IDEAL_MOISTURE_LEVEL;
}

Grain* Milo::clone() const
{
	return new Milo(*this);
}
