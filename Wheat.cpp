// File Name: Wheat.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Wheat.h"

using namespace std;

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
	const std::string GRAIN_TYPE = "Wheat";
}

Wheat::Wheat() : Grain() {}

Wheat::Wheat(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial) {}

Wheat::~Wheat() {}

//return a string representing the calling object’s grain type
const std::string Wheat::getType() const
{
	return GRAIN_TYPE;
}

const double Wheat::getAverageTestWeight() const
{
	return AVERAGE_TEST_WEIGHT;
}

const double Wheat::getIdealMoistureLevel() const
{
	return IDEAL_MOISTURE_LEVEL;
}

Grain* Wheat::clone() const
{
	return new Wheat(*this);
}
