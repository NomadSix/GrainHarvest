// File Name: Wheat.h
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#ifndef WHEAT_H_
#define WHEAT_H_

#include "Grain.h"

class Wheat: public Grain
{
public:
	Wheat();
	Wheat(double, double);
	virtual ~Wheat();

	Grain* cloneCst() const
	{
		return new Wheat(*this);
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
		return 13.5;
	}

	Wheat* clone() const
	{
		return static_cast<Wheat*>(cloneCst());
	}
};

#endif /* WHEAT_H_ */
