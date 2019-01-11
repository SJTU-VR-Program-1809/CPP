#pragma once
#include <iostream>
class LinkList
{
public:
    struct Node
    {
        int v;
        std::shared_ptr<Node> next;
    };

    LinkList();
    LinkList(std::initializer_list<int> l);
    LinkList(const LinkList&);
    LinkList(LinkList&&);
    ~LinkList();
    void Reverse();
    std::shared_ptr<Node> GetLastNth(int n);
    size_t size() const;
    bool empty() const;
    void push_back(int n);
    void erase(int v); //
    void insert(std::shared_ptr<Node> node, int v);
    void print();

private:
    std::shared_ptr<Node> head{ nullptr };
};

