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

	//return a string representing the calling object’s grain type
	virtual std::string getType() const;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const;

	// Accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const;
};

#endif /* SOYBEAN_H_ */
