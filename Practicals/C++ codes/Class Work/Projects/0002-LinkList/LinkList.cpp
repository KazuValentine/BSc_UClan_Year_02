#include "LinkList.hpp"
#include <iostream>

bool LinkList::IsEmpty()
{
	if (mpHead == nullptr && mpTail == nullptr)
	{
		return true;
	}
	return false;
}

void LinkList::SetHead(Node* pHead)
{
	mpHead = pHead;
}

void LinkList::SetTail(Node* pTail)
{
	mpTail = pTail;
}

Node& LinkList::GetHead()
{
	return *mpHead;
}

Node& LinkList::GetTail()
{
	return *mpTail;
}

void LinkList::AddToHead(const double& kNumber)
{
	Node* pNewNode = new Node(kNumber);

	if (IsEmpty())
	{
		SetHead(pNewNode);
		SetTail(pNewNode);
		return;
	}

	IncrementAllIndices(mpHead);
	pNewNode->SetNextNode(mpHead);
	mpHead = pNewNode;

}

void LinkList::AddToTail(const double& kNumber)
{
	Node* pNewNode = new Node(kNumber);

	if (IsEmpty())
	{
		SetHead(pNewNode);
		SetTail(pNewNode);
		return;
	}

	pNewNode->SetIndex(mpTail->GetIndex() + 1);
	mpTail->SetNextNode(pNewNode);
	mpTail = pNewNode;

}

Node& LinkList::operator[](const int& kIndex)
{

	if (kIndex < 0 || kIndex > mpTail->GetIndex())
	{
		throw std::invalid_argument("invalid index");
	}

	Node* pCurrentNode = mpHead;

	for (int i = 0; i < kIndex; i++)
	{
		pCurrentNode = pCurrentNode->GetNextNode();
	}

	return *pCurrentNode;

}

Node& LinkList::operator[](Node* pNode)
{
	return operator[](pNode->GetIndex());
}

void LinkList::IncrementIndex(Node* pNode)
{
	pNode->SetIndex(pNode->GetIndex() + 1);
}

void LinkList::DecrementIndex(Node* pNode)
{
	pNode->SetIndex(pNode->GetIndex() - 1);
}

void LinkList::IncrementAllIndices(Node* pCurrentNode)
{
	while (pCurrentNode != nullptr)
	{
		IncrementIndex(pCurrentNode);
		pCurrentNode = pCurrentNode->GetNextNode();
	}
}

void LinkList::DecrementAllIndices(Node* pCurrentNode)
{
	while (pCurrentNode != nullptr)
	{
		DecrementIndex(pCurrentNode);
		pCurrentNode = pCurrentNode->GetNextNode();
	}
}

void LinkList::Insert(Node* pNode, const double& kNumber)
{
	if (pNode == nullptr && mpTail != nullptr)
	{
		std::cerr << "invalid index\n";
		return;
	}
	if (mpTail == nullptr)
	{
		AddToHead(kNumber);
		return;
	}
	if (pNode == mpHead)
	{
		AddToHead(kNumber);
		return;
	}
	if (pNode == mpTail)
	{
		AddToTail(kNumber);
		return;
	}
	Node* pLeftNode = mpHead;

	for (int i = 0; i < pNode->GetIndex() - 1; i++)
	{
		pLeftNode = pLeftNode->GetNextNode();
	}
	Node* pNewNode = new Node(kNumber);
	pNewNode->SetNextNode(pLeftNode->GetNextNode());
	pLeftNode->SetNextNode(pNewNode);
	pNewNode->SetIndex(pLeftNode->GetIndex() + 1);
	IncrementAllIndices(pNewNode->GetNextNode());
}

void LinkList::Insert(Node& node, const double& kNumber)
{
	Insert(&node, kNumber);
}

void LinkList::Delete(Node* pNode)
{
	if (pNode == nullptr)
	{
		std::cerr << "invalid index\n";
		return;
	}

	Node* pMiddleNode = mpHead;
	Node* pLeftNode = mpHead;


	for (int i = 0; i < pNode->GetIndex(); i++)
	{
		if (pNode->GetIndex())
		{
			pLeftNode = pMiddleNode;
		}

		pMiddleNode = pMiddleNode->GetNextNode();

	}

	if (pMiddleNode == mpTail)
	{
		mpTail = pLeftNode;
		mpTail->SetNextNode(nullptr);
	}
	else
	{
		if (pMiddleNode == mpHead)
		{
			mpHead = pMiddleNode->GetNextNode();
		}
		else
		{
			pLeftNode->SetNextNode(pMiddleNode->GetNextNode());
		}
		DecrementAllIndices(pMiddleNode->GetNextNode());
	}
	delete pMiddleNode;
}

void LinkList::Delete(Node& pNode)
{
	Delete(&pNode);
}

int LinkList::Length()
{
	return mpTail->GetIndex() + 1;
}

LinkList::LinkList(const LinkList& kOriginal)
{
	Node* pCurrentNode = kOriginal.mpHead;
	while (pCurrentNode != nullptr)
	{
		AddToTail(pCurrentNode->GetNumber());
	}
}

LinkList::LinkList()
{
}

LinkList::~LinkList()
{
	Node* pCurrentNode = mpHead;
	Node* pNextNode = nullptr;
	while (pCurrentNode != nullptr)
	{
		pNextNode = pCurrentNode->GetNextNode();
		delete pCurrentNode;
		pCurrentNode = pNextNode;
	}
}
