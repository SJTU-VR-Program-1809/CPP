#include "SingleLinkList.h"


SingleLinkList::SingleLinkList(std::initializer_list<int> l)
{
    Node* curr{};
    for (int i : l) {
        if (!head) {
            head = new Node{ i,nullptr };
            curr = head;
        }
        else {
            curr->next = new Node{ i,nullptr };
            curr = curr->next;
        }
    }
}
SingleLinkList::SingleLinkList(const SingleLinkList& l) 
{
    head = l.head;
   /* Node* curr{ head };
    Node* lcurr{ l.head };
    while (lcurr) {
        curr->value = lcurr->value;
        curr = curr->next;
        lcurr = lcurr->next;
    }*/
}
SingleLinkList::SingleLinkList(SingleLinkList&& l) 
{
    head = std::move(l.head);
}
SingleLinkList::~SingleLinkList() 
{
    if (!head)
        return;
    Node* hnext{};
    while (head) {
        hnext = head->next;
        delete head;
        head = hnext;
    }
    delete head;
}
void SingleLinkList::Reverse() 
{
    Node* prev{};
    Node* next{};
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}
SingleLinkList::Node* SingleLinkList::GetLastNth(int n)const 
{
    if (!head|| !n)
        return nullptr;
    Node* fNode{ head };
    while (n--) {
        if (!fNode)
            return false;
        fNode = fNode->next;
    }
    Node* sNode{ head };
    while (fNode) {
        sNode = sNode->next;
        fNode = fNode->next;
    }
    return sNode;
}
size_t SingleLinkList::Size()const 
{
    Node* curr{ head };
    int size{};
    while (curr) {
        size++;
        curr = curr->next;
    }
    return size;
}
bool SingleLinkList::IsEmpty() const 
{
    if (head) {
        return false;
    }
    else {
        return true;
    }
}
void SingleLinkList::Push_Back(int n) 
{
    Node* curr{head};
    if (!head) {
        head = new Node{ n,nullptr };
        curr = head;
    }
    else {
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node{ n,nullptr };
    }
}
void SingleLinkList::Erase(int v)
{
    if (head) {
        Node* curr{ head };
        if (head->value == v)
            delete head;
        else {
            if (curr->next) {
                while (curr->next->value != v) {
                    if (curr->next->next) {
                        curr = curr->next;
                    }
                    else {
                        cout << "value:" << v << " doesn't exist" << endl;
                        return;
                    }
                }
                Node* next = curr->next->next;
                delete curr->next;
                curr->next = next;
            }
            else {
                cout << "value:" << v << " doesn't exist" << endl;
            }
        }
    }
}
void SingleLinkList::Insert(Node* node, int v)
{
    if (node) {
        Node* next{};
        next = node->next;
        node->next = new Node{ v,next };
    }
    else {
        cout << "this node is null" << endl;
    }
}
void SingleLinkList::Print()
{
    Node* curr{ head };
    while (curr) {
        cout << curr->value;
        if (curr->next) {
            cout << "->";
        }
        else {
            cout << endl;
            break;
        }
        curr = curr->next;
    }
}