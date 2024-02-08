#pragma once
#ifndef LINKLIST
#define LINKLIST

#include "Node.hpp"

class LinkList
{
private:

	Node* mpHead = nullptr;
	Node* mpTail = nullptr;

	void SetHead(Node* pHead);
	void SetTail(Node* pTail);
	bool IsEmpty();
	void IncrementIndex(Node*);
	void IncrementAllIndices(Node*);
	void DecrementIndex(Node*);
	void DecrementAllIndices(Node*);

public:

	Node& GetHead();
	Node& GetTail();
	void AddToHead(const double&);
	void AddToTail(const double&);
	void Insert(Node*, const double&);
	void Insert(Node&, const double&);
	void Delete(Node*);
	void Delete(Node&);
	int Length();

	Node& operator[](const int&);
	Node& operator[](Node*);

	LinkList(const LinkList&);
	LinkList();
	~LinkList();

};

#endif