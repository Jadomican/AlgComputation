//X00119321 Jason Domican Lab 1B ALC

#ifndef Person_h
#define Person_h

#include <iostream>
#include <cstdlib>

using namespace std;

/***************************************************************************************
*    Usage: modified
*    Title: Interfaces in C++ (Abstract Classes)
*    Date: 09/02/2018
*    Availability: https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
***************************************************************************************/

class Person 
{
public:
	Person(string);					// initialise the name 
	virtual void printname() = 0;	// Make class abstract using pure virtual function

	/*
	* Without the 'virtual' keyword here the output for all 3 object types (Person, Customer and Employee)
	* will use the base class version of printname() and display "My name is <name>" without regard
	* for the alternative definitions given for printname() in Customer and Employee
	*/

	bool operator<(const Person& p);
protected:
	string name;
};

#endif