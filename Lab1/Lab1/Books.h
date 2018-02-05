//X00119321 Jason Domican Lab 1 ALC

#ifndef Books_h
#define Books_h

#include <iostream>
#include <cstdlib>
#include "Product.h"

using namespace std;

class Books : public Product
{
public:
	Books(double);
	double getGrossPrice();
private:

};


#endif