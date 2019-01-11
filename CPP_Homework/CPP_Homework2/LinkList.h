#pragma once
class LinkList {
public:
	struct Node {
		int v;
		Node* next;
	};
	LinkList(std::initializer_list<int> l);
	LinkList(const LinkList&);
	LinkList(LinkList&&);
	~LinkList();
	void  Reverse();
	Node* GetLastNth(int n) const;
	size_t size() const;
	bool empty() const;
	void push_back(int n);
	void erase(int v);
	void insert(Node* node, int v);
	void print();
private:
	Node* head{ nullptr };
};