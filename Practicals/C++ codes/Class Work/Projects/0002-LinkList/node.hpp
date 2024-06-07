#pragma once
#ifndef NODE
#define NODE
#include <ostream>

class Node
{
private:

	double mNumber = 0;
	Node* mpNextNode = nullptr;
	int mIndex = 0;

	Node* GetNextNode();
	void SetNextNode(Node*);
	int GetIndex();
	void SetIndex(const int&);

public:

	double GetNumber();
	void SetNumber(const double&);

	friend std::ostream& operator<<(std::ostream&, Node&);
	friend Node* operator+(Node&, const int&);
	friend Node* operator+(const int&, Node&);
	void operator=(const double&);

	Node(const double&);
	Node(const Node&);
	~Node();

	friend class LinkList;

};

#endif

