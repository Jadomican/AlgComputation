//X00119321 Jason Domican Lab 1B ALC

#include <string>
#include <iostream>
#include "Person.h"

Person::Person(string nameIn)
{
	name = nameIn;
}

void Person::printname()
{
	cout << "\nMy name is " << name;
}

bool Person::operator<(const Person& p)
{
	if (p.name.compare(name) < 0)	{
		return false;
	}
	else
	{
		return true;
	}
}

