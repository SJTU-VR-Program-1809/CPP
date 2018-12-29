#include <iostream>
using namespace std;

const int n = 3;
int z[6][n];
//�������ʽ
void print(int a[][n])
{
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < n; j++)
		{
			cout << " " << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
}
//��ȫ������
const int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}
//��������Ԫ��
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//��ȡC��ȫ���в�����Z��
void perm(int c[], int first, int last) {
	static int k = 0;
	if (first == last)
	{
		for (int j = 0; j < n; j++)
			z[k][j] = c[j];
		k++;
	}
	else
	{
		for (int i = first; i < last; i++)
		{
			swap(c[i], c[first]);
			perm(c, first + 1, last);
			swap(c[i], c[first]);
		}
	}
}
//����������
int againstCount(int a[])
{
	int ac = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				ac++;
			}
		}
	}
	return ac;
}

int main()
{
	int a[n][n];
	int c[n];
	int ac;//�������ĸ���
	int m = 1;
	int det = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "������a[" << i << "]" << "[" << j << "]" << "=";
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		c[i] = i;
	}
	print(a);
	perm(c, 0, n);
	for (int i = 0; i < factorial(n); i++)
	{
		m = 1;
		for (int j = 0; j < n; j++)
		{
			m *= a[j][z[i][j]];
		}
		ac = againstCount(z[i]);
		det += pow(-1, ac)*m;
	}
	cout << "����ʽ��ֵΪ��" << det << endl;
}