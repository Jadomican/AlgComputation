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
