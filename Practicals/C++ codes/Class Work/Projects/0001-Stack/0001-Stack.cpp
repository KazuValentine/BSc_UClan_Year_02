#include <iostream>
#include "stack.hpp"

int main()
{

	Stack testStack;

	testStack.Push(10);
	testStack.Push(16);
	testStack.Push(41);
	testStack.Push(25);
	testStack.Push(36);
	testStack.Push(41);
	std::cout << "Size of the stack: " << testStack.Size() << '\n';

	return 0;

}