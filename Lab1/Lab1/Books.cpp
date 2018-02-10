//X00119321 Jason Domican Lab 1

#include "Books.h"

Books::Books(double price):Product(price)
{

}

double Books::getGrossPrice()
{
	return netPrice;
}
