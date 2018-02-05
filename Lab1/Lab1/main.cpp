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



	cout << "\n\n";
	system("pause");
	return 0;
}