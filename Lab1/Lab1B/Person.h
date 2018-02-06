//X00119321 Jason Domican Lab 1B ALC

#ifndef Person_h
#define Person_h

#include <iostream>
#include <cstdlib>

using namespace std;

class
	Person
{
public:
	Person(string); // initialise the name 
	virtual void printname();

protected:
	string name;
};


#endif