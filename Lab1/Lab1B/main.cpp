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

	personPtr = new Person("Jason");
	personPtr->printname();

	personPtr = new Employee("James", 30000);
	personPtr->printname();

	personPtr = new Customer("Philip");
	personPtr->printname();


	cout << "\n\n";
	system("pause");
	return 0;
}
