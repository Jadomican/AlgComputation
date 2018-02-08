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


template <class WhatKind> void multiples(WhatKind& sum, WhatKind x, int n)
{
	sum = 1;

	for (int i = 0; i <= n; i++)
	{
		sum += (i * x);
	}
}


template <class T1, class T2>
T1 init(T1 num1, T1 num2, T2& start)
{
	start = T2(1);
	return num1 + num2;
}


template <typename T>
T* quicksort(T* array, int start, int end)
{
	if start < end;

}


int main()
{
	//Question 1
	int a = 5;
	float b = 10;
	swap(&a, &b);
	std::cout << "\na: " << a << "\nb: " << b;


	//Question 2
	int sumTotal;
	multiples(sumTotal, 2, 3);
	std::cout << "\n\n" << sumTotal;


	//Question 3
	int num1 = 2;
	int num2 = 3;
	double start = 2.2;

	std::cout << "\n\n" << init(num1, num2, start) << std::endl;
	std::cout << start;


	std::cout << "\n\n";
	system("pause");
	return 0;
}
