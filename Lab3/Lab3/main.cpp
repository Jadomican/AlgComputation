//X00119321 Jason Domican Lab3

#include <iostream>

using namespace std;

void mergeSort(int arrayToSort[], int startIndex, int lengthToSort)
{
	if (startIndex < lengthToSort)
	{
		int m = startIndex + (lengthToSort - 1) / 2;

		mergeSort(arrayToSort, 1, m);
		mergeSort(arrayToSort, m + 1, lengthToSort);
		merge(arrayToSort, 1, lengthToSort);
	}
}

void merge(int arraySortedInTwoHalves[], int startIndex, int length)
{

}


int main()
{


	cout << "\n\n";
	system("pause");
	return 0;
}


//ca - quicksort