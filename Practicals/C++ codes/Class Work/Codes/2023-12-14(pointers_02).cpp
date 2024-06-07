#include <iostream>

void DerefPtr();

int main()
{

	int num = 10;
	int* pNum = &num;
	int** ppNum = &pNum;
	int*** pppNum = &ppNum;

	std::cout << "pNum: " << pNum << std::endl;
	std::cout << "ppNum: " << ppNum << std::endl;
	std::cout << "pppNum: " << pppNum << std::endl;
	
	return 0;

}