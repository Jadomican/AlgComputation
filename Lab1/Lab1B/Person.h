//X00119321 Jason Domican Lab 1B ALC

#ifndef Person_h
#define Person_h

#include <iostream>
#include <cstdlib>

using namespace std;

class Person 
{
public:
	Person(string); // initialise the name 
	virtual void printname();
	/*
	* Without the 'virtual' keyword here the output for all 3 object types (Person, Customer and Employee)
	* will use the base class version of printname() and display "My name is <name>" without regard
	* for the alternative definitions given for printname() in Customer and Employee
	*/

protected:
	string name;
};


#endif