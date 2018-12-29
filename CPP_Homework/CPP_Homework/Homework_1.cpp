#include <iostream>
using namespace std;

const int n = 3;
int z[6][n];
//输出行列式
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
//求全排列数
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
//交换两个元素
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//获取C的全排列并存在Z中
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
//计算逆序数
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
	int ac;//逆序数的个数
	int m = 1;
	int det = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "请输入a[" << i << "]" << "[" << j << "]" << "=";
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
	cout << "行列式的值为：" << det << endl;
}