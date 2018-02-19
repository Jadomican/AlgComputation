#include <iostream>
#include "Person.h"
using namespace std;

int const arraySize = 8;

template <class T>
void printArray(T array[])
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
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
	int i = (first - 1);

	for (int j = first; j <= last - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			printArray(array);
			swap(&array[i], &array[j]);
			printArray(array);
		}
	}

	printArray(array);
	swap(&array[i + 1], &array[last]);	//pivot should be at i + 1
	printArray(array);
	return (i + 1);
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

	//int numbers[]{ 4, 6, 2, 8, 2, 10, 6, 5 };
	double numbers[]{ 4.5, 6.2, 2.1, 8.3, 2.8, 10.2, 6.2, 5.2 };

	cout << endl;
	printArray(numbers);

	cout << "\n\n";

 	quickSort(numbers, 0, arraySize - 1);

	cout << "\n\n";
	printArray(numbers);


	system("pause");
	return 0;
}