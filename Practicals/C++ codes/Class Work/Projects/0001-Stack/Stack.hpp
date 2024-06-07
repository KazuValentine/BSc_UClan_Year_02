#pragma once
#ifndef STACK
#define STACK

class Stack
{

private:

	int* mpStack = nullptr;
	int mPOS = -1;

	bool IsEmpty();
	void ResizeStack();

public:

	void Push(int num);
	int Pop();
	int Peak();
	void PrintStack();
	int Size();

};

#endif

