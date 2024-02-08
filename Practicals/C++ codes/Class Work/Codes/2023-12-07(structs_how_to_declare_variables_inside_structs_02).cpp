#include <iostream>

class SA
{
	char mA = 'a';
	long long mC = 20;
	char mB = 'b';
};

class SB
{
	long long mA = 20;
	char mArray[8];
};

class SC
{
	char mA = 'a';
	char mB = 'b';
	char mC = 'c';
	char mD = 'd';
	int mF = 0;
	double mE = 20;
};

/*
In a struct it is better to declare the largest variable 1st and go on in the decreasing order.
Cuz if the largest variable takes 40 bits, the stack is going to have plates of 40 bits.
So into the 1st plate, the 40 bits variable goes, in the next plate, 2 of 20 bits variables can be stored.
If you declare something other than the largest variable 1st, let's say you declare 2 bits, 4 bits, 8 bits, 20 bits and 40 bits variables respectively,
the compiler will insert 2 bits into a single plate and keep the rest empty which cannot be assigned others.
Remember, the struct will always be rectangular.
*/

int main()
{

	std::cout << "Size of SA: " << sizeof(SA) << '\n';
	std::cout << "Size of SB: " << sizeof(SB) << '\n';
	std::cout << "Size of SC: " << sizeof(SC) << '\n';
	

	return 0;

}