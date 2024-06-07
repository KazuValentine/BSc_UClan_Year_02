#include <iostream>
#include "stack.hpp"

bool Stack::IsEmpty()
{
	if (mPOS == -1)
	{
		return true;
	}
	return false;
}

void Stack::ResizeStack()
{
	if (mPOS == -1)
	{
		delete[] mpStack;
		mpStack == nullptr;
		return;
	}

	int* pNewStack = new int[mPOS + 1];

	if (mPOS != 0)
	{
		for (int i = 0; i <= mPOS; i++)
		{
			pNewStack[i] = mpStack[i];
		}
		delete[] mpStack;
	}
	mpStack = pNewStack;
	pNewStack = nullptr;
}

void Stack::Push(int num)
{
	mPOS++;
	ResizeStack();
	mpStack[mPOS] = num;
}

int Stack::Pop()
{

	if (IsEmpty())
	{
		std::cout << "Stack Empty\n";
		return 0;
	}

	int num = mpStack[mPOS];
	mPOS--;
	ResizeStack();
	return num;

}

void Stack::PrintStack()
{
	for (int i = mPOS; i > -1; i--)
	{
		std::cout << mpStack[i];
		if (i != 0)
		{
			std::cout << '\n';
		}
	}

}

int Stack::Peak()
{

	if (IsEmpty())
	{
		std::cout << "Stack Empty\n";
		return 0;
	}
	return mpStack[mPOS];
}

int Stack::Size()
{
	return mPOS + 1;
}
