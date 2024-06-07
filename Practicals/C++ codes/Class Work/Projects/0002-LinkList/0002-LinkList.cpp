#include <iostream>
#include "LinkList.hpp"
#include <crtdbg.h>

void PrintAll(LinkList&);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("color 0a");

	std::cout << "Size of PTR: " << sizeof(Node*) * 8 << " bits\n";
	std::cout << "Size of DOUBLE: " << sizeof(double) * 8 << " bits\n";
	std::cout << "Size of INT: " << sizeof(int) * 8 << " bits\n";
	std::cout << "Size of NODE: " << sizeof(Node) * 8 << " bits\n";
	std::cout << "Size of LINKLIST: " << sizeof(LinkList) * 8 << " bits\n\n";

	LinkList list;

	list.Insert(list.GetTail(), 999);
	list.AddToTail(0);
	list.AddToTail(1);
	list.AddToTail(3);
	list.AddToTail(4);
	list.AddToTail(6);
	list.AddToTail(7);

	PrintAll(list);
	std::cout << "\n\n";

	list.Insert(list.GetHead() + 3, 2);
	list.Insert(list.GetHead() + 6, 5);
	list.Insert(list.GetHead(), -1);
	list.Insert(list.GetTail(), 8);

	PrintAll(list);
	std::cout << "\n\n";

	list.AddToHead(-2);
	list.AddToHead(-3);
	list.AddToHead(-4);
	list.AddToHead(-5);

	PrintAll(list);
	std::cout << "\n\n";

	list.Delete(list.GetTail());
	list.Delete(list.GetHead());

	PrintAll(list);
	std::cout << "\n\n";

	list.Delete(list.GetHead() + 4);


	PrintAll(list);
	std::cout << "\n\n";

	list[list.Length() - 1] = 100;

	PrintAll(list);
	std::cout << "\n\n";

	std::cout << list[list.GetHead() + 5];

	return 0;
	
}

void PrintAll(LinkList& list)
{
	for (int i = 0; i < list.Length(); i++)
	{
		std::cout << list[i];
		if (list.Length() - i != 1)
		{
			std::cout << ", ";
		}
	}
}
