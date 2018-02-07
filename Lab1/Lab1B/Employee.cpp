#include "Employee.h"

Employee::Employee(string nameIn, double salaryIn):Person(nameIn), salary(salaryIn)
{

}

void Employee::printname()
{
	Person::printname();
	cout << " and my salary is " << salary;
}
