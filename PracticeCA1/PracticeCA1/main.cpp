#include <iostream>
using namespace std;

int const arraySize = 8;

void printArray(int array[])
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// You return the final position of the pivot in the array.
// Pass in the index positions of the section of the array
// to be sorted
int quickSortDivide(int array[], int first, int last)
{
	int pivot = array[last];
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
void quickSort(int array[], int first, int last)
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

	int numbers[]{ 4, 6, 2, 8, 2, 10, 6, 5 };
	cout << endl;
	printArray(numbers);

	cout << "\n\n";

 	quickSort(numbers, 0, arraySize - 1);

	cout << "\n\n";
	printArray(numbers);

	system("pause");
	return 0;
}