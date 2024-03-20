#include <iostream>

int Factorial(int x)
{
	if( x == 1 || x == 0 )
	{
		return 1;
	}
	return x * Factorial(x - 1);
}

bool ValidateFactorialInput( int num )
{
	if( num < 0 )
	{
		std::cout << "Invalid Input!\n";
		return false;
	}
	return true;
}

int main()
{
	int num;
	std::cout << "Enter a num: ";
	std::cin >> num;
	if( ValidateFactorialInput( num ) )
	{
		std::cout << "Factorial of " << num << ": " << Factorial( num ) << '\n';
	}

	return 0;
}