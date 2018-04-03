// File Name: Wheat.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Wheat.h"

using namespace std;

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.5;
}

Wheat::Wheat() : Grain() {}

Wheat::Wheat(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial) {}

Wheat::~Wheat() {}

//return a string representing the calling object’s grain type
std::string Wheat::getType() const
{
	return "Wheat";
}

const double Wheat::getAverageTestWeight() const
{
	return AVERAGE_TEST_WEIGHT;
}

const double Wheat::getIdealMoistureLevel() const
{
	return IDEAL_MOISTURE_LEVEL;
}

Wheat* Wheat::clone() const
{
	return new Wheat(*this);
}
