#include <iostream>
#include <string>

bool IsPrime( int num )
{
	if( num < 2 )
		return false;
	if( num == 2 )
		return true;
	for( int i = 2; i < num; i++ )
	{
		if( num % i == 0 )
			return false;
	}
	return true;
}

int main()
{
	std::string input = "";
	int inputNum = 0;
	std::cout << "Enter a number: ";
	std::getline(std::cin >> std::ws, input);
	inputNum = std::stoi(input);
	std::cout << '\n' << input << " is";
	if( !IsPrime(inputNum) )
		std::cout << " not";
	std::cout << " a prime number!";
	return 0;

}