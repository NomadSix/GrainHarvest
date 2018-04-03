
// File Name: Grain.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Grain.h"

// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
Grain::Grain(double mLevel, double fMaterial) : moistureLevel(mLevel), foreignMaterial(fMaterial) {}

// Constructor default
Grain::Grain() : Grain(0, 0) {}

// Destructor
Grain::~Grain() {}

std::string Grain::toString()
{
	return getType();
}

// Accessor to return sample's moisture level (percent)
double Grain::getMoistureLevel() const
{
	return moistureLevel;
}

// Accessor to return sample's foreign material (percent)
double Grain::getForeignMaterial() const
{
	return foreignMaterial;
}

// setter to set the sample's moisture level
void Grain::setMoistureLevel(double mL)
{
	moistureLevel = mL;
}

// setter to set the foreignMaterial
void Grain::setForeignMaterial(double fM)
{
	foreignMaterial = fM;
}
