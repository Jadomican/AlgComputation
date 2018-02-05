#include "Books.h"

Books::Books(double price):Product(price)
{

}

double Books::getGrossPrice()
{
	return netPrice;
}
