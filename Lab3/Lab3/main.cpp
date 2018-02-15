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

//The recursive merge sort function
void mergeSort(int arrayToSort[], int startIndex, int endIndex)
{
	int midIndex;

	//Check for base case
	if (startIndex >= endIndex)
	{
		return;
	}

	//First, divide in half
	midIndex = (startIndex + endIndex) / 2;

	//First recursive call
	mergeSort(arrayToSort, startIndex, midIndex);
	//Second recursive call
	mergeSort(arrayToSort, midIndex + 1, endIndex);
	//The merge function
	merge(arrayToSort, startIndex, endIndex);

}


//Quicksort
int quickSortDivide(int *theArray, int size) 
{

	//return the final position of the pivot in the array	
}




int main()
{
	int array[10] = { 2,4,3,5,7,2,8,3,6,10 };

	mergeSort(array, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}

	system("pause");
	return 0;
}