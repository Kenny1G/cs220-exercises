//Kenneth Oseleononmen
//koseleo1

#include "Tree.h"
#include <sstream>

template<typename T>
Tree<T>::Tree(T val):
data(val),
kids(nullptr),
sibs(nullptr),
prev(nullptr)
{}

template<typename T>
Tree<T>::~Tree()
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

template<typename T>
Tree<T>& Tree<T>::operator^(Tree<T>& rt)
{
	this->addChild(&rt);
	return *this;
}

template<typename X>
std::ostream& operator<< (std::ostream& os, Tree<X>& rt)
{
	return os << rt.toString();
}


template<typename T>
bool Tree<T>::operator==(const Tree<T> &root)
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


template<typename T>
bool Tree<T>::addChild(T val)
{
	Tree<T> *node = new Tree<T>(val);
	bool bRet = addChild(node);
	return bRet;
}

template<typename T>
bool Tree<T>::addChild(Tree<T> *root)
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


template<typename T>
std::string Tree<T>::toString()
{
	std::stringstream str;
	str << this->data;
	str << "\n";

	if (nullptr != this->kids) str << kids->toString();
	if (nullptr != this->sibs) str << sibs->toString();

	return str.str();
}


template<typename T>
bool Tree<T>::addSibling(T val)
{
	Tree<T> *node = new Tree<T>(val);
	bool bRet = this->addSibling(node);
	return bRet;
}


template<typename T>
bool Tree<T>::addSibling(Tree<T> *root)
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

template<int>
std::ostream& operator<<(std::ostream& os, Tree<int>& rt);