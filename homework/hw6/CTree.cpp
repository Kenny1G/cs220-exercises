//Kenneth Oseleononmen
//koseleo1

#include "CTree.h"
#include <string>
#include <sstream>


CTree::CTree(char ch):
data(ch),
kids(nullptr),
sibs(nullptr),
prev(nullptr)
{}

CTree::~CTree()
{
	if (nullptr != this->sibs) 
	{
		delete this->sibs;
	}
	if (nullptr != this->kids) 
	{
		delete this->kids;
	}
}

CTree& CTree::operator^(CTree& rt)
{
	this->addChild(&rt);
	return *this;
}


std::ostream& operator<<(std::ostream& os, CTree& rt)
{
	return os << rt.toString();
}


bool CTree::operator==(const CTree &root)
{
	if (this->data != root.data) return false;

	if (nullptr != this->kids)
	{
		if (nullptr == this->kids) return false;
		if (!(*this->kids == *root.kids)) return false;
	}
	else if (nullptr != root.kids) return false;

	if (nullptr != this->sibs)
	{
		if (nullptr == root.sibs) return false;
		if (!(*this->sibs == *root.sibs)) return false;
	}
	else if (nullptr != root.sibs) return false;
	return true;
}


bool CTree::addChild(char ch)
{
	CTree *node = new CTree(ch);
	bool bRet = addChild(node);
	return bRet;
}

bool CTree::addChild(CTree *root)
{
	if (nullptr != root->prev || nullptr != root->sibs) return false;

	if (nullptr == this->kids)
	{
		this->kids = root;
		root->prev = this;
		return true;
	}
	else
	{
		bool bRet = this->kids->addSibling(root);
		return bRet;
	}
}


std::string CTree::toString()
{
	std::stringstream str;
	str << this->data;
	str << "\n";

	if (nullptr != this->kids) str << kids->toString();
	if (nullptr != this->sibs) str << sibs->toString();

	return str.str();
}


bool CTree::addSibling(char ch)
{
	CTree *node = new CTree(ch);
	bool bRet = this->addSibling(node);
	return bRet;
}


bool CTree::addSibling(CTree *root)
{
	if (nullptr == this->prev) return false;
	if (root->data == this->data) return false;

	if (root->data < this->data)
	{
		root->sibs = this;
		root->prev = this->prev;
		if (nullptr == this->prev->prev)
		{
			this->prev->kids = root;
		}
		else
		{
			this->prev->sibs = root;
		}
		this->prev = root;
	}
	else 
	{
		if (nullptr == this->sibs)
		{
			this->sibs = root;
			root->sibs = nullptr;
			root->prev = this;
		}
		else 
		{
			bool bRet = this->sibs->addSibling(root);
			return bRet;
		}
	}
	return true;
}