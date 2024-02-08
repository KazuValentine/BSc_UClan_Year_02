#include "Node.hpp"
#include <iostream>

double Node::GetNumber()
{
	return mNumber;
}

void Node::SetNumber(const double& kNumber)
{
	mNumber = kNumber;
}

Node* Node::GetNextNode()
{
	return mpNextNode;
}

void Node::SetNextNode(Node* pNextNode)
{
	mpNextNode = pNextNode;
}

Node::Node(const double& kNumber)
{
	mNumber = kNumber;
}

int Node::GetIndex()
{
	return mIndex;
}

void Node::SetIndex(const int& kIndex)
{
	mIndex = kIndex;
}

std::ostream& operator<<(std::ostream& cout, Node& node)
{
	cout << node.GetNumber();
	return cout;
}

void Node::operator=(const double& kNumber)
{
	mNumber = kNumber;
}

Node::Node(const Node& kOrgNode)
{
	mIndex = kOrgNode.mIndex;
	mNumber = kOrgNode.mNumber;
	mpNextNode = kOrgNode.mpNextNode;
}

Node::~Node()
{
	mpNextNode = nullptr;
}

Node* operator+(Node& node, const int& kValue)
{
	Node* pCurrentNode = &node;

	for (int i = 0; i < kValue; i++)
	{
		pCurrentNode = pCurrentNode->GetNextNode();
		if (pCurrentNode == nullptr)
		{
			break;
		}
	}
	return pCurrentNode;
}

Node* operator+(const int& kValue, Node& node)
{
	return operator+(node, kValue);
}
