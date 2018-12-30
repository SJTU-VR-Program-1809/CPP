#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}NODE;
NODE *head = NULL;

//获取链表长度
int Length()
{
	NODE *p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//得到坐标下的元素
int GetItem(int t)
{
	NODE *p = head;
	int k = 0;
	while (k < t - 1)
	{
		p = p->next;
		k++;
	}
	return p->data;
}

//i:第几位插入，e：插入的数据
void InsertForword(int i, int e)
{
	NODE *p = head;
	NODE *q;
	int k = 0;
	if (i == 0)
	{
		q = new NODE[1];
		q->data = e;
		q->next = p;
		head = q;
	}
	while (p&&k < i - 2)
	{
		p = p->next;
		k++;
	}
	q = new NODE[1];
	q->data = e;
	q->next = p->next;
	p->next = q;
}

void  InsertBack(int i, int e)
{
	NODE *p = head;
	NODE  *q;
	int j = 0;
	if (i == 0)
	{
		q = (NODE *)new NODE[1];
		q->data = e;
		q->next = p;
		head = q;

	}
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return;
	q = (NODE *)new NODE[1];
	q->data = e;
	q->next = p->next;
	p->next = q;
}

void Delete(int i)
{
	NODE *p = head;
	NODE *q;
	if (p == NULL) return;
	int j = 0;
	if (i == 0)
	{
		head = head->next;
		delete p;
		p = NULL;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return;
	q = p->next;
	p->next = p->next->next;
	delete q;
	q = NULL;
	return;
}

void Reverse()
{
	if (head == NULL || head->next == NULL) return;
	NODE *p = head;
	NODE *q = head->next;
	NODE *r;
	head->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
}
void Print()
{
	NODE*p = head;
	while (p != NULL)
	{
		cout << p->data << "-> ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	InsertBack(0, 1);
	InsertBack(1, 5);
	InsertBack(2, 7);
	InsertBack(3, 6);
	InsertBack(4, 11);
	InsertBack(5, 17);
	Print();
	cout << "链表长度" << Length() << endl;
	cout << "第二个元素是：" << GetItem(2) << endl;
	cout << endl;
	Delete(0);
	Print();
	InsertForword(1, 99);
	cout << "反转后各个元素的值是：";
	Print();
	cout << endl;
	Reverse();
	Print();
	cout << endl;
}

