// File Name: Soybean.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Soybean.h"

using namespace std;

namespace {
	const double AVERAGE_TEST_WEIGHT = 60.0;
	const double IDEAL_MOISTURE_LEVEL = 13.0;
	const std::string GRAIN_TYPE = "Soybean";
}

Soybean::Soybean() : Grain() {}

Soybean::Soybean(double moistureLevel, double foreignMaterial) : Grain(moistureLevel, foreignMaterial) {}

Soybean::~Soybean() {}

//return a string representing the calling object’s grain type
const std::string Soybean::getType() const
{
	return GRAIN_TYPE;
}

const double Soybean::getAverageTestWeight() const
{
	return AVERAGE_TEST_WEIGHT;
}

const double Soybean::getIdealMoistureLevel() const
{
	return IDEAL_MOISTURE_LEVEL;
}

Grain* Soybean::clone() const
{
	return new Soybean(*this);
}
