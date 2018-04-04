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

	virtual Grain* clone() const;

	//return a string representing the calling object’s grain type
	virtual const std::string getType() const;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const;

	// Accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const;
};

#endif /* WHEAT_H_ */
