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

	//return a string representing the calling object’s grain type
	virtual std::string getType() const;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const;

	// Accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const;

	Wheat* clone() const;
};

#endif /* WHEAT_H_ */
