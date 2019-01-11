#include"LinkList.h"
#include<iostream>
using namespace std;
int main()
{
	LinkList l{ 1,2,3,4,5 };
	l.print();
	l.Reverse();
	l.print();
	auto pNode = l.GetLastNth(4);
	if (pNode)
	{
		cout << "the 4th node value:" << pNode->v << endl;
		l.insert(pNode, 7);
		l.print();
	}
	else
		cout << "out of the length of list.";
	l.push_back(10);
	if (!l.empty())
		cout << "list size:" << l.size() << endl;
	LinkList k = 1;
	k.print();
	LinkList k = move(l);
	l.print();
}