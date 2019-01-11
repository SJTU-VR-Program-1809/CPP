#pragma once
#include<iostream>

using namespace std;

class SingleLinkList
{
public :
    struct Node
    {
        int value;
        Node* next;
    };

    SingleLinkList(std::initializer_list<int> l);
    SingleLinkList(const SingleLinkList&);
    SingleLinkList(SingleLinkList&&);
    ~SingleLinkList();
    void Reverse();
    Node* GetLastNth(int n)const;
    size_t Size()const;
    bool IsEmpty() const;
    void Push_Back(int n);
    void Erase(int v);
    void Insert(Node* node, int v);
    void Print();

private:
    Node* head{ nullptr };
};

