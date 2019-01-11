#pragma once
#include<iostream>

class LinkList {
public:
    struct Node
    {
        Node* next;
        int v;
        //Node(Node*n, int _v) { next = n; v = _v; }
    };

    LinkList(std::initializer_list<int>l);
    LinkList();                       //缺省构造
    LinkList(LinkList&& l);
    LinkList(const LinkList& l);        //拷贝构造
    ~LinkList();
    LinkList& operator=(const LinkList& l);
    void Reverse();
    Node* GetLastNth(int n) const;
    size_t size() const;
    bool empty();
    void push_back(int n);
    void erase(int v);
    void insert(Node* n, int v);
    void print();
private:
    std::shared_ptr<Node>head{ nullptr };
    int _size;
};

/*
void test()
{
    LinkList l{ 1,2,3,4,5 };
    l.print();
    l.Reverse();
    l.print();
    auto pNode = l.GetLastNth(4);
    if (pNode)
    {
        std::cout << "the 4th node value: " << pNode->v << std::endl;
        l.insert(pNode, 7);
        l.print();
    }
    else
        std::cout << "out of length" << std::endl;
    l.push_back(10);
    if (!l.empty())
        std::cout << "list size:" << l.size() << std::endl;
    LinkList k = l;
    k.print();
    LinkList k = std::move(l);
    l.print();      //应该没打印东西


}
*/
