#include <iostream>

int main()
{

	int* ptrOne = new int(10);
	delete ptrOne;
	std::cout << *ptrOne << std::endl;

	return 0;

}