#include <iostream>
#include "LinkList.h"
using namespace std;


LinkList::LinkList(initializer_list<int> l)
{
	Node* curr{ nullptr };
	for (auto i: l)
	{
		if (!head)
		{
			head = new Node{i,nullptr };
			curr = head;
		}
		else
		{
			curr->next = new Node{ i,nullptr };
			curr = curr->next;
		}
	}
}
LinkList::LinkList(const LinkList & list)
{
	Node*cur{ head };
	Node*lcur{ list.head };
	if (list.head)
		return;
	else
	{
		cur = new Node{ lcur->v,nullptr };
		while (lcur->next)
		{
			lcur = lcur->next;
			cur->next= new Node{ lcur->v,nullptr };
			cur = cur->next;
		}
	}
}
LinkList::LinkList(LinkList && list)
{
}
LinkList::~LinkList()
{
}
void LinkList::erase(int v)
{
	Node*cur{head};
	if (!head) return;
	if (head->v == v)
		head = head->next;
	while (cur)
	{
		if (cur->next ->v == v)
		{
			cur->next = cur->next->next;
			return;
		}
		cur = cur->next;
	}
}
//在node前插入一个值为v的node
void LinkList::insert(Node * node, int v)
{
	Node* p{nullptr};
	Node* pre{head};
	if (!head)
		return;
	if (head == node)
	{
		head->next = pre;
		head->v = v;
	}
	else
	{
		while (pre->next != node)
		{
			pre = pre->next;
		}
		p->next = node;
		pre->next = p;
		p->v = v;
	}
}
void LinkList::print()
{
	Node* curr{ head };
	while (curr)
	{
		cout << curr->v << endl;
		curr = curr->next;
	}
}
void  LinkList::Reverse()
{
	Node* prev{ nullptr };
	while (head)
	{
		auto next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
}
LinkList::Node*LinkList::GetLastNth(int n) const
{
	if (!head || !n)
		return nullptr;
	Node* fNode{ head };
	while (n--)
	{
		if (!fNode)
		{
			return nullptr;
		}
		fNode = fNode->next;
	}
	Node* sNode{ head };
	while (fNode)
	{
		fNode = fNode->next;
		sNode = sNode->next;
	}
	return sNode;
}

size_t LinkList::size() const
{
	Node* next{head};
	int i = 0;
	if (!head)
	{
		return 0;
	}
	while (next)
	{
		next = head->next;                                                                                                    
		i++;
	}
	return i;
}

bool LinkList::empty() const
{
	if (!head)
		return false;
	else
		return true;
}

void LinkList::push_back(int n)
{
}





