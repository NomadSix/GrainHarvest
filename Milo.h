// File Name: Milo.h
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#ifndef MILO_H_
#define MILO_H_

#include "Grain.h"

class Milo: public Grain
{
public:
	Milo();
	Milo(double, double);
	virtual ~Milo();

	virtual Grain* clone() const;

	//return a string representing the calling object’s grain type
	virtual const std::string getType() const;

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual const double getAverageTestWeight() const;

	// Accessor to return grain's ideal moisture level (percent)
	virtual const double getIdealMoistureLevel() const;
};

#endif /* MILO_H_ */
