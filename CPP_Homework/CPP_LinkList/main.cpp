#include <iostream>
#include "LinkList.h"
using namespace std;


struct Nodes {
    int v;
    shared_ptr<Nodes> next;
};

int main()
{
    //LinkList linkList{};
    LinkList l{ 1,2,3,4,5 };
    l.print();
    l.Reverse();
    l.print();
    auto pNode = l.GetLastNth(4);
    if (pNode)
    {
        cout << "the 4th node value :" << pNode->v << endl;
        l.insert(pNode, 7);
        l.print();
    }
    else
        cout << "out of the length of list" << endl;
    l.push_back(10);
    l.print();
    if (!l.empty())
        cout << "list size " << l.size() << endl;
    l.erase(3);
    l.print();
    LinkList k = l;
    k.print();
    LinkList k1 = std::move(l);
    l.print();//null

    int xx;
    cin >> xx;
    return 0;
}
