//X00119321 Jason Domican Lab 1 ALC

#ifndef Product_h
#define Product_h

#include <iostream>
#include <cstdlib>

using namespace std;

class Product
{
public:
	Product(double);
	virtual double getGrossPrice();

protected:
	double netPrice;

};

#endif