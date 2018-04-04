
// File Name: Harvest.cpp
// Author: Devon Schimming
// Student ID: H863R773
// Assignment Number: 5

#include "Input.h"
#include "Output.h"
using namespace std;


int main()
{
	Tickets allTickets;
	//input data for ticket
	Input::inputTickets(allTickets);

	//output all the tickets in the heap array
	Output::outputTickets(allTickets);
	Output::outputSummary(allTickets);
	return 0;
}












