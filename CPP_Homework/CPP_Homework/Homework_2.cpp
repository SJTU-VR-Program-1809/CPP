#include "Homework_2.h"
using namespace std;

LinkList::LinkList(std::initializer_list<int> l)
{
    auto item = l.begin();
    shared_ptr<Node> currNode{ nullptr };
    shared_ptr<Node> nextNode{ nullptr };
    currNode->v = *item++;
    head = make_shared<Node>(currNode);
    for (; item != l.end(); item++)
    {
        nextNode->v = *item;
        currNode->next = &*nextNode;
        currNode = nextNode;
    }
    _size = l.size();
}

LinkList::LinkList()
{
    head = make_shared<Node>(nullptr);
    _size = 0;
}

LinkList::LinkList(LinkList && l)
{
    head = const_pointer_cast<Node>(l.head);
    _size = move(l._size);
}

LinkList::LinkList(const LinkList & l)
{
    head = l.head;
    _size = l._size;
}

LinkList::~LinkList()
{
    auto cur = head;
    while (cur)
    {
        auto del = cur;
        cur = shared_ptr<Node>(cur->next);
        delete &del;
        del.reset();
    }
}

LinkList & LinkList::operator=(const LinkList & l)
{
    if (this == &l)
    {
        return *this;
    }
    head = l.head;
    _size = l._size;
    return *this;
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

LinkList::Node* LinkList::GetLastNth(int n) const
{
    shared_ptr<Node> fNode{ head };
    while (n--)
    {
        if (!fNode)
        {
            cerr << "the n is less than length of list" << endl;
            return nullptr;
        }
        fNode = make_shared<Node>(fNode->next);
    }
    shared_ptr<Node>sNode{ head };
    while (fNode)
    {
        fNode = make_shared<Node>(fNode->next);
        sNode = make_shared<Node>(sNode->next);
    }
    return &*sNode;
}



size_t LinkList::size() const
{
    return _size;
}

bool LinkList::empty()
{
    return head ? true : false;
}

void LinkList::push_back(int n)
{
    shared_ptr<Node> cur = head;
    while (cur->next)
    {
        cur = make_shared<Node>(cur->next);
    }
    shared_ptr<Node> node{ nullptr };
    node->next = nullptr;
    node->v = n;
    cur->next = &* node;
}

void LinkList::erase(int v)
{
    shared_ptr<Node> prev{ nullptr };
    shared_ptr<Node> curr{ head };
    while (curr)
    {
        if (curr->v == v)
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                head = make_shared<Node>(curr->next);
            }
        }
        else
        {
            prev = curr;
        }
        curr = make_shared<Node>(curr->next);
    }
}

void LinkList::insert(Node * n, int v)
{
    shared_ptr<Node>prev{ nullptr };
    shared_ptr<Node>curr{ head };
    while (curr)
    {
        if (&*curr == &*n)
        {
            shared_ptr<Node> node{ nullptr };
            node->v = v;
            node->next = &* curr;
            if (prev)
            {
                prev->next = &*node;
            }
            else
            {
                head->next = &*node;
            }
            return;
        }
        curr = make_shared<Node>(curr->next);
    }
    cerr << "linklist does not contain Node: " << n << endl;
}


void LinkList::print()
{
    shared_ptr<Node> curr{ head };
    while (curr)
    {
        cout << curr->v << "->";
    }
    cout << endl;
}

int main()
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
    k = std::move(l);
    l.print();      //应该没打印东西

}