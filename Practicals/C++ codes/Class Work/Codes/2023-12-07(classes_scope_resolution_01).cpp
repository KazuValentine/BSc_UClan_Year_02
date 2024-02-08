#include <iostream>

namespace test1
{
	void Print(int input)
	{
		std::cout << input << '\n';
	}
}

namespace test2
{

	void Print(char input)
	{
		std::cout << input << '\n';
	}

}

int X = 10;

int main()
{

	int a = 65;
	int X = 20;

	test1::Print(a);
	test2::Print(a);

	std::cout << X << std::endl;
	std::cout << ::X << std::endl;

	return 0;

}