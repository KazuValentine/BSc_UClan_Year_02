#include "mattrix.hpp"
#include <iostream>

int main()
{

	double** ppMattrixOne = new double* [2];
	for (int i = 0; i < 2; i++)
	{
		ppMattrixOne[i] = new double[3];
	}
	double** ppMattrixTwo = new double* [3];
	for (int i = 0; i < 3; i++)
	{
		ppMattrixTwo[i] = new double[4];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ppMattrixOne[i][j] = i * 3 + j + 1;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ppMattrixTwo[i][j] = i * 4 + j + 1;
		}
	}

	Mattrix mattrix1(2, 3, ppMattrixOne);
	Mattrix mattrix2(3, 4, ppMattrixTwo);

	std::cout << "Mattrix 1:\n" << mattrix1 << std::endl << std::endl;
	std::cout << "Mattrix 2:\n" << mattrix2 << std::endl << std::endl;
	std::cout << "Mattrix 1 x Mattrix 2:\n" << mattrix1 * mattrix2;

	for (int i = 0; i < 3; i++)
	{
		delete[] ppMattrixTwo[i];
	}
	delete[] ppMattrixTwo;

	for (int i = 0; i < 2; i++)
	{
		delete[] ppMattrixOne[i];
	}
	delete[] ppMattrixOne;

	ppMattrixOne = nullptr;
	ppMattrixTwo = nullptr;

	return 0;

}