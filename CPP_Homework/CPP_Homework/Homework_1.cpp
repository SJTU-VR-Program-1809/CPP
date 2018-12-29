// ArrayTraining.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
#include <iostream>

using namespace std;

void PrintArray(int* array, int length);
int GetReverseNumber(int* array, int length);

int main()
{
	int deter[] = { 3, 1, 4, 2, 6, 7 };
	int length = sizeof(deter) / sizeof(deter[0]);
	int n = GetReverseNumber(deter, length);
	cout << n << endl;
	PrintArray(deter, length);

}


void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << endl;
	}
}

int GetReverseNumber(int* array, int length)
{
	int count = 0;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[i])
			{
				count++;
			}
		}
	}
	return count;
}
