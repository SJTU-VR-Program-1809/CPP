#pragma once
class LinkList
{
	struct Node {
		Node *next;
		int v;
	};
public:
	LinkList(std::initializer_list<int>l);
	LinkList();
	LinkList(LinkList&& l);
	LinkList(const LinkList& l);
	~LinkList();
	LinkList& operator=(const LinkList& l);
	void Reverse();
	Node* GetLastNth(int n) const;
	size_t size() const;
	bool empty()const;
	void push_back(int n);
	void erase(int v);
	void insert(Node* n, int v);
	void print();
private:
	//Node *head{nullptr};
	std::shared_ptr<Node>head{ nullptr };
	int _size;
};

