//X00119321 Jason Domican Lab 2

#include <iostream>
#include <algorithm>

//using namespace std;

template <class T1, class T2> void swap(T1* lhs, T2* rhs)
{
	//T1 temp = lhs;
	//lhs = rhs;
	//rhs = temp;

	int temp;
	temp =	*rhs;
	*rhs = *lhs;
	*lhs = temp;

}

int main()
{

	int a = 5;
	float b = 10;

	swap(&a, &b);
	std::cout << "\na: " << a << "\nb: " << b;

	std::cout << "\n\n";
	system("pause");
	return 0;
}
