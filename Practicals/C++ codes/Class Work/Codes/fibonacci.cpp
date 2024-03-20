#include <iostream>

int Fibonacci( int x )
{
	if( x == 1 || x == 2 )
	{
		return 1;
	}
	return Fibonacci( x - 1 ) + Fibonacci( x - 2 );
}

int main()
{
	std::cout << Fibonacci( 50 ) << '\n';
	return 0;
}