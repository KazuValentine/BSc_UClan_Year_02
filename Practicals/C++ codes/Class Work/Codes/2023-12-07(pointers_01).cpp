#include <iostream>

int main()
{

	int A = 5;
	int* pA = &A;
	int** ppA = &pA;
	int*** pppA = &ppA;
	int**** ppppA = &pppA;
	int***** pppppA = &ppppA;
	
	std::cout << *****pppppA << '\n';

	return 0;

}