// File Name: Grain.h
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include <string>

#ifndef GRAIN_H_
#define GRAIN_H_

/**
 * The Grain class identifies properties of a sample of grain
 */
class Grain
{
public:
	// Constructor default
	Grain();

	// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
	Grain(double moistureLevel, double foreignMaterial);

	// Destructor
	virtual ~Grain();

	//copys object
	virtual Grain* clone();

	//return a string representing the calling object’s grain type
	virtual std::string getType() const = 0;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const = 0;

	// Accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const = 0;

	std::string toString();

	// Accessor to return sample's moisture level (percent)
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material (percent)
	double getForeignMaterial() const;

	// setter to set the sample's moisture level
	void setMoistureLevel(double); //dont use

	// setter to set the foreignMaterial
	void setForeignMaterial(double); //dont use

private:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
