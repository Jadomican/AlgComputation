//X00119321 Jason Domican Practice CA1

#ifndef Person_h
#define Person_h

#include <iostream>
#include <cstdlib>

using namespace std;

class Person
{
public:
	Person(string);					// initialise the name 
	virtual void printname() = 0;	// Make class abstract using pure virtual function
	string getname();

/*
* Without the 'virtual' keyword here the output for all 3 object types (Person, Customer and Employee)
* will use the base class version of printname() and display "My name is <name>" without regard
* for the alternative definitions given for printname() in Customer and Employee
*/

	bool operator<(const Person& p);
	bool operator<=(const Person& p);

protected:
	string name;
};


class Customer : public Person
{
public:
	Customer(string);
	void printname();


};

class Employee : public Person
{
public:
	Employee(string, double);
	void printname();
private:
	double salary;
};



#endif