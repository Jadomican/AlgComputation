//X00119321 Jason Domican Lab 1B ALC

#include <string>
#include <iostream>
#include "Customer.h"

Customer::Customer(string nameIn):Person(nameIn)
{

}

void Customer::printname()
{
	Person::printname();
	cout << " and I want to make a complaint";
}
