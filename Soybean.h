// File Name: Soybean.h
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#ifndef SOYBEAN_H_
#define SOYBEAN_H_

#include "Grain.h"

class Soybean: public Grain
{
public:
	Soybean();
	Soybean(double, double);
	virtual ~Soybean();

	Grain* cloneCst() const
	{
		return new Soybean(*this);
	}

	//return a string representing the calling object’s grain type
	virtual std::string getType();

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual double getAverageTestWeight()
	{
		return 60.0;
	}

	// Accessor to return grain's ideal moisture level (percent)
	virtual double getIdealMoistureLevel()
	{
		return 13.0;
	}

	Soybean* clone() const
	{
		return static_cast<Soybean*>(cloneCst());
	}
};

#endif /* SOYBEAN_H_ */
