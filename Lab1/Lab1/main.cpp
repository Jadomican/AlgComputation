//X00119321 Jason Domican Lab 7B

#include <iostream>
#include "Product.h"
#include "Software.h"
#include "Books.h"
using namespace std;

int main()
{
	//Product* p = new Product(5);

	//cout << p->getGrossPrice();
	//cout << "\n\n";


	//Books* b = new Books(10);
	//cout << b->getGrossPrice();
	//cout << "\n\n";


	Product* pointers[8];

	Books* book;

	Software* software;

	double price;
	cout << "Enter book details";
	cin >> price;
	book = new Books(price);

	cout << "Enter software details";
	cin >> price;
	software = new Software(price);

	cout << "\n\n";
	cout << book->getGrossPrice();

	cout << "\n\n";
	cout << software->getGrossPrice();

	pointers[0] = book;
	pointers[1] = software;

	for (int i = 2; i < 8; i++)
	{
		cout << "Enter price of item " << i;
		cin >> price;

		char type;
		cout << "Book or Software? Type s or b";
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

	for (int i = 0; i < 8; i++)
	{
		cout << pointers[i]->getGrossPrice();
	}

	cout << "\n\n";
	system("pause");
	return 0;
}