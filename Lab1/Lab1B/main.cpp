//X00119321 Jason Domican Lab 1B

#include <iostream>
#include <algorithm>

#include "Person.h"
#include "Customer.h"
#include "Employee.h"
using namespace std;

int main()
{
	// Base class pointer
	Person* personPtr;

	//Cannot initialise Person object when class is made abstract
	//personPtr = new Person("Jason");
	//personPtr->printname();

	personPtr = new Employee("James", 30000);
	personPtr->printname();

	personPtr = new Customer("Philip");
	personPtr->printname();
	cout << "\n";

	int const arraySize = 3;
	Person* arrayPeople[arraySize];

	Person* personPtr1 = new Customer("Steve");

	Person* personPtr2 = new Employee("Karl", 20000);

	Person* personPtr3 = new Employee("Ricky", 80000);

	arrayPeople[0] = personPtr1;
	arrayPeople[1] = personPtr2;
	arrayPeople[2] = personPtr3;


	// Print pointer array name values in original order
	for (int i = 0; i < arraySize; i++)
	{
		arrayPeople[i]->printname();
	}

	/***************************************************************************************
	*    Usage: modified
	*    Title: Sorting Array of Pointers in C++
	*    Date: 09/02/2018
	*    Availability: https://stackoverflow.com/questions/18052204/sorting-array-of-pointers-in-c
	***************************************************************************************/

	// Sorting the array of pointers (using the overloaded < operator)
	std::sort(begin(arrayPeople), end(arrayPeople), [](Person* a, Person* b) { return *a < *b; });
		
	cout << "\n\nSorted array of people by name (A-Z):\n";
	for (int i = 0; i < arraySize; i++)
	{
		arrayPeople[i]->printname();
	}

	cout << "\n\n";
	system("pause");
	return 0;
}
