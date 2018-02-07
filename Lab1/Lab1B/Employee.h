//X00119321 Jason Domican Lab 1B ALC

#ifndef Employee_h
#define Employee_h

#include <iostream>
#include <cstdlib>
#include "Person.h"

using namespace std;

class Employee : public Person
{
public:
	Employee(string, double);
	void printname();
private:
	double salary;
};


#endif