#include "LinkList.h"
#include<iostream>
using namespace std;


LinkList::LinkList(std::initializer_list<int> l)
{
	auto item = l.begin();
	shared_ptr<Node> p{ nullptr };
	shared_ptr<Node> q{ nullptr };
	p->v = *item++;
	head = make_shared<Node>(p);
	for (; item != l.end(); item++)
	{
		q->v = *item;
		p->next = &*q;
		p = q;
	}
	_size = l.size();
}

LinkList::LinkList()
{
	head = make_shared<Node>(nullptr);
	_size = 0;
}


LinkList::~LinkList()
{
	auto p = head;
	while (p)
	{
		auto del = p;
		p = shared_ptr<Node>(p->next);
		delete &del;
		del.reset();
	}
}

LinkList::LinkList(const LinkList &l)
{
	head = l.head;
	_size = l._size;
}

LinkList & LinkList::operator=(const LinkList & l)
{
	head = l.head;
	_size = l._size;
	return *this;
}

LinkList::LinkList(LinkList &&l)
{
	head = const_pointer_cast<Node>(l.head);
	_size = move(l._size);
}

void LinkList::Reverse()
{
	if (empty())
	{
		cout << "LinkList is null";
		return;
	}
	shared_ptr<Node> prev{ nullptr };
	while (head)
	{
		shared_ptr<Node> next = make_shared<Node>(head->next);
		head->next = &*prev;
		prev = head;
		head = next;
	}
	head = prev;
}

LinkList::Node *  LinkList::GetLastNth(int n) const
{
	shared_ptr<Node>p{ head };
	shared_ptr<Node>q{ head };
	int t = 0;
	while (p != nullptr)
	{
		t++;
		p = make_shared<Node>(p->next);
	}
	int k = 0;
	while (k < t - n)
	{
		k++;
		q = make_shared<Node>(q->next);
	}
	return &*q;
}

size_t LinkList::size() const
{
	return _size;
}

bool LinkList::empty() const
{
	if (head != nullptr)
		return false;
	else
		return true;
}

void LinkList::push_back(int n)
{
	shared_ptr<Node>p{ head };
	Node*q;
	while (p != nullptr)
	{
		p = make_shared<Node>(p->next);
	}
	q = (Node *)new Node{};
	q->v = n;
	p->next = q;
}

void LinkList::erase(int v)
{
	shared_ptr<Node>p{ head };
	Node*q;
	while (p->v != v)
	{
		p = make_shared<Node>(p->next);
	}
	if (p != nullptr)
	{
		q = (Node *)new Node{};
		q->v = p->next->next->v;
		q->next = p->next->next;
		p->next = q;
	}
}

void LinkList::insert(Node *node, int v)
{
	shared_ptr<Node>p{ head };
	shared_ptr<Node>q{ nullptr };
	while (p)
	{
		if (&*p == &*node)
		{
			shared_ptr<Node> node{ nullptr };
			node->v = v;
			node->next = &* p;
			if (q)
			{
				q->next = &*node;
			}
			else
			{
				head->next = &*node;
			}
			return;
		}
		p = make_shared<Node>(p->next);
	}

}

void LinkList::print()
{
	shared_ptr<Node>p{ head };
	while (p != nullptr)
	{
		std::cout << p->v << "-> ";
	}
	std::cout << endl;
}
