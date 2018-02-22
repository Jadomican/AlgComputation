//X00119321 Jason Domican Lab 1B ALC

#include <string>
#include <iostream>
#include "Person.h"

//Person
Person::Person(string nameIn)
{
	name = nameIn;
}

void Person::printname()
{
	cout << "\nMy name is " << name;
}

string Person::getname()
{
	return name;
}


bool Person::operator<(const Person& p)
{
	if (p.name.compare(name) < 0) {
		return false;
	}
	else
	{
		return true;
	}
}

bool Person::operator<=(const Person& p)
{
	if (p.name.compare(name) < 0) {
		return false;
	}
	else
	{
		return true;
	}
}

//Employee
Employee::Employee(string nameIn, double salaryIn) :Person(nameIn), salary(salaryIn)
{

}

void Employee::printname()
{
	Person::printname();
	cout << " and my salary is " << salary;
}

//Customer
Customer::Customer(string nameIn) :Person(nameIn)
{

}

void Customer::printname()
{
	Person::printname();
	cout << " and I want to make a complaint";
}
