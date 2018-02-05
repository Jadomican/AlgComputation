//X00119321 Jason Domican Lab 1 ALC

#include "Product.h"

Product::Product(double price)
{
	netPrice = price;
}

double Product::getGrossPrice()
{
	return netPrice * 1.21;
}
