#include "LinkList.h"

LinkList::LinkList()
{
    head = std::make_shared<Node>();

}

LinkList::LinkList(std::initializer_list<int> L)
{
    std::shared_ptr < Node> q{ head };
    std::shared_ptr<Node> p;
    for (int i = 0; i < L.size(); i++)
    {
        p = std::make_shared<Node>();
        p->v = L.begin()[i];
        p->next = nullptr;
        if (head == nullptr)
        {
            head = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = p;
        }
    }
}

LinkList::LinkList(const LinkList & L_head)
{
    if (!L_head.head)
        return;
    std::shared_ptr<Node> p = L_head.head;
    std::shared_ptr<Node> q{ head };
    std::shared_ptr<Node> next;
    while (p)
    {
        next = std::make_shared<Node>();
        next->v = p->v;
        next->next = nullptr;
        p = p->next;
        if (head == nullptr)
        {
            head = next;
            q = next;
        }
        else
        {
            q->next = next;
            q = next;
        }
    }
    //  std::cout << head << "&&&" << L_head.head << std::endl;
}

LinkList::LinkList(LinkList && L_head)
{
    if (!L_head.head)
        return;
    head = L_head.head;
    L_head.head = nullptr;
}


LinkList::~LinkList()
{
    head.reset();
}

void LinkList::Reverse()
{
    if (head->next == nullptr)
        return;
    std::shared_ptr<Node> prev{ nullptr };
    std::shared_ptr<Node> q{ head };
    while (head)
    {
        head = head->next;
        q->next = prev;
        prev = q;
        q = head;
    }
    head = prev;
}

std::shared_ptr<LinkList::Node> LinkList::GetLastNth(int n)
{
    std::shared_ptr<Node> p = head;
    while (p&&n > 0)
    {
        n--;
        p = p->next;
    }
    if (!p)
    {
        std::cout << "out of the LinkList size" << std::endl;
        return nullptr;
    }
    else if (n == 0)
    {
        std::shared_ptr<Node> q = head;
        while (p)
        {
            p = p->next;
            q = q->next;
        }
        return q;
    }
    return nullptr;
}


size_t LinkList::size() const
{
    size_t size = 0;
    std::shared_ptr<Node> p{ head };
    while (p)
    {
        size++;
        p = p->next;
    }
    return size;
}

bool LinkList::empty() const
{
    return head == nullptr;
}

void LinkList::push_back(int n)
{
    std::shared_ptr<Node> p{ head };
    while (p->next)
    {
        p = p->next;
    }
    if (!head)
    {
        head = std::make_shared<Node>();
        head->v = n;
        head->next = nullptr;
    }
    else
    {
        std::shared_ptr<Node> q = std::make_shared<Node>();
        q->v = n;
        q->next = nullptr;
        p->next = q;
    }
}

void LinkList::erase(int v)
{
    if (!head) return;
    if (head->v == v)
        head = head->next;

    std::shared_ptr<Node> p{ head };
    while (p->next&&p->next->v != v)
    {
        p = p->next;
    }
    if (!p->next) return;
    else if (p->next->v == v)
    {
        p->next = p->next->next;
    }
}

void LinkList::insert(std::shared_ptr<Node> node, int v)
{
    // insert a new node that the value is v behind the node 
    std::shared_ptr<Node> p{ head };
    while (p&&p != node)
    {
        p = p->next;
    }
    if (!p)
    {
        std::cout << "out of the LinkList size" << std::endl;
        return;
    }
    else if (p == node)
    {
        std::shared_ptr<Node> q{ p->next };
        std::shared_ptr<Node> new_node = std::make_shared<Node>();
        new_node->v = v;
        new_node->next = q;
        p->next = new_node;
    }
    return;
}

void LinkList::print()
{
    if (!head)
    {
        std::cout << "the LinkList is empty" << std::endl;
        return;
    }
    std::shared_ptr<Node> p = head;
    while (p != nullptr)
    {
        std::cout << p->v;
        if (p->next != nullptr)
            std::cout << " -> ";;
        p = p->next;
    }
    std::cout << std::endl;
}
