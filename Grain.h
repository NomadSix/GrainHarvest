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
protected:
	virtual Grain* cloneCst() const = 0;

public:
	// Constructor default
	Grain();

	// Constructor allowing caller to specify sample's moisture level (%) and foreign material (%)
	Grain(double moistureLevel, double foreignMaterial);

	// copy constructor
	Grain* clone() const
	{
		return cloneCst();
	}

	// Destructor
	virtual ~Grain();

	//return a string representing the calling object’s grain type
	virtual std::string getType() = 0;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual double getAverageTestWeight() = 0;

	// Accessor to return grain's ideal moisture level (percent)
	virtual double getIdealMoistureLevel() = 0;

	// Accessor to return sample's moisture level (percent)
	double getMoistureLevel() const;

	// Accessor to return sample's foreign material (percent)
	double getForeignMaterial() const;

	// setter to set the sample's moisture level
	void setMoistureLevel(double);

	// setter to set the foreignMaterial
	void setForeignMaterial(double);

private:
	// Member variables
	double moistureLevel;
	double foreignMaterial;
};

#endif /* GRAIN_H_ */
