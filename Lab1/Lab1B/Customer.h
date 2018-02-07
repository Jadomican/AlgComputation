//X00119321 Jason Domican Lab 1B ALC

#ifndef Customer_h
#define Customer_h

#include <iostream>
#include <cstdlib>
#include "Person.h"

using namespace std;

class Customer : public Person
{
public:
	Customer(string);
	void printname();


};


#endif