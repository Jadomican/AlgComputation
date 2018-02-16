//X00119321 Jason Domican Lab3

/***************************************************************************************
*    Usage: modified
*    Title: Merge sort
*    Date: 14/02/2018
*    Availability: http://www.cplusplus.com/forum/general/166536/
***************************************************************************************/

#include <iostream>
using namespace std;

// Merge Sort
void merge(int arraySortedInTwoHalves[], int startIndex, int length)
{
	int size = (length - startIndex) + 1;
	int *b = new int[size]();

	int i = startIndex;
	int mid = (startIndex + length) / 2;
	int k = 0;
	int j = mid + 1;

	while (k < size)
	{
		if ((i <= mid) && (arraySortedInTwoHalves[i] < arraySortedInTwoHalves[j]))
		{
			b[k++] = arraySortedInTwoHalves[i++];
		}
		else
		{
			b[k++] = arraySortedInTwoHalves[j++];
		}

	}

	for (k = 0; k < size; k++)
	{
		arraySortedInTwoHalves[startIndex + k] = b[k];
	}
	delete[]b;
}

// The recursive merge sort function
void mergeSort(int arrayToSort[], int startIndex, int endIndex)
{
	int midIndex;

	// Check for base case
	if (startIndex >= endIndex)
	{
		return;
	}

	// First, divide in half
	midIndex = (startIndex + endIndex) / 2;
	// First recursive call
	mergeSort(arrayToSort, startIndex, midIndex);
	// Second recursive call
	mergeSort(arrayToSort, midIndex + 1, endIndex);
	// The merge function
	merge(arrayToSort, startIndex, endIndex);
}


//Quicksort

void swap(int* a, int* b)	// Function to allow swapping of pointers
{
	int t = *a;
	*a = *b;
	*b = t;
}

/***************************************************************************************
*    Usage: modified
*    Title: QuickSort
*    Date: 16/02/2018
*    Availability: https://www.geeksforgeeks.org/quick-sort/
***************************************************************************************/

int quickSortDivide(int theArray[], int first, int last)
{
	int pivot = theArray[last];    // pivot
	int i = (first - 1);  // Index of smaller element

	for (int j = first; j <= last - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (theArray[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&theArray[i], &theArray[j]);
		}
	}
	swap(&theArray[i + 1], &theArray[last]);
	return (i + 1);
}
	
void quickSort(int theArray[], int first, int last)
{
	if (first < last)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = quickSortDivide(theArray, first, last);

		// Separately sort elements before
		// partition and after partition
		quickSort(theArray, first, pi - 1);
		quickSort(theArray, pi + 1, last);
	}
}

void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int const arraySize = 10;
	int array1[arraySize] = { 2,4,3,5,7,2,6,3,6,10 };
	mergeSort(array1, 0, arraySize - 1);
	cout << "Merge sorted:\n";
	printArray(array1, arraySize);

	int array2[arraySize] = { 2,4,3,5,7,2,8,3,6,10 };
	quickSort(array2, 0, arraySize - 1);
	cout << "\n\nQuick sorted:\n";
	printArray(array2, arraySize);

	system("pause");
	return 0;
}