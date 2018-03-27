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

	Grain* cloneCst() const
	{
		return new Milo(*this);
	}

	//return a string representing the calling object’s grain type
	virtual std::string getType();

	// Accessor to return grain's average test weight (lbs/bushel)
	virtual double getAverageTestWeight()
	{
		return 56.0;
	}

	// Accessor to return grain's ideal moisture level (percent)
	virtual double getIdealMoistureLevel()
	{
		return 13.0;
	}

	Milo* clone() const
	{
		return static_cast<Milo*>(cloneCst());
	}
};

#endif /* MILO_H_ */
