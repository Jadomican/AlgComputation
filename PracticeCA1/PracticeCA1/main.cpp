#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

int const arraySize = 8;

template <class T>
void printArray(T array[])
{
	for (int i = 0; i < arraySize; i++)
	{
		array[i]->printname();
		//cout << *(array[i]);
	}
	cout << "\n";
}

template <class T>
void swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}


// You return the final position of the pivot in the array.
// Pass in the index positions of the section of the array
// to be sorted

template <class T>
int quickSortDivide(T array[], int first, int last)
{
	T pivot = array[last];

	int i = first - 1;

	for (int j = first; j < last; j++)
	{
		if (*(array[j]) <= (*pivot))
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[last]);	//pivot should be at i + 1
	return i + 1;

}


// Recursive quicksort method 

template <class T>
void quickSort(T array[], int first, int last)
{
	if (first < last)
	{
		int pivotIndex = quickSortDivide(array, first, last);

		quickSort(array, first, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, last);

	}
}

int main()
{
	Person* arrayPeople[arraySize] = {

		new Customer("Steve"),
		new Employee("Aaron", 20000),
		new Customer("Topham"),
		new Employee("Michael", 30000),
		new Customer("Karl"),
		new Customer("Jason"),
		new Customer("Robert"),
		new Customer("Ricky")
	};
	
	printArray(arrayPeople);

	quickSort(arrayPeople, 0, arraySize - 1);

	cout << "\nQuickSorted:";
	printArray(arrayPeople);

	system("pause");
	return 0;
}


//int numbers[]{ 4, 6, 2, 8, 2, 10, 6, 5 };
//double numbers[]{ 4.5, 6.2, 2.1, 8.3, 2.8, 10.2, 6.2, 5.2 };
