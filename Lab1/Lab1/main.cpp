//X00119321 Jason Domican Lab 7B

#include <iostream>
#include <algorithm>

#include "Product.h"
#include "Software.h"
#include "Books.h"
using namespace std;

int main()
{
	int const arraySize = 8;

	Product* pointers[8];

	Books* book;

	Software* software;

	double price;
	cout << "Enter book price: ";
	cin >> price;
	book = new Books(price);

	cout << "Enter software price: ";
	cin >> price;
	software = new Software(price);

	cout << "\n\n";
	cout << book->getGrossPrice();

	cout << "\n\n";
	cout << software->getGrossPrice();

	pointers[0] = book;
	pointers[1] = software;

	for (int i = 2; i < arraySize; i++)
	{
		cout << "Enter price of item: " << (i + 1);
		cin >> price;

		char type;
		cout << "Book or Software? Type s or b: ";
		cin >> type;

		if (type == 's')
		{
			pointers[i] = new Software(price);
		}
		if (type == 'b')
		{
			pointers[i] = new Books(price);
		}

	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << "\n\n" << pointers[i]->getGrossPrice();
	}


	//Now we call the sort function
	//http://www.cplusplus.com/articles/NhA0RXSz/
	sort(pointers, pointers + arraySize);

	cout << "Sorted Array looks like this." << endl;
	for (size_t i = 0; i != arraySize; ++i)
		cout << pointers[i]->getGrossPrice() << " ";




	cout << "\n\n";
	system("pause");
	return 0;
}