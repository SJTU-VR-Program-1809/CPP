#include<iostream>
using namespace std;


const int n = 4;
float d[4][4] = { {1,3,2,4},{1,4,5,7},{2,3,7,6},{4,5,1,3} };


void Print()
{
	cout << "the Determinant is:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << d[i][j] << "\t";
		}
		cout << endl;
	}
}


int GetReverseNumber(int a[], int size)
{
	int rev = 0; //count Number
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (a[i] > a[j])
			{
				rev++;
			}
		}
	}
	return rev % 2 == 0 ? 1 : -1;
}


float CalculateItem(int a[4])
{
	float res = 1.0f;
	for (int i = 0; i < 4; i++)
		res *= d[i][a[i]];
	return res * GetReverseNumber(a, 4);
}


bool IsCompleteSort(int a[4])
{
	for (int i = 0; i < 4 - 1; i++)
	{
		if (a[i] < a[i + 1])
			return false;
	}
	return true;
}


float CalculateDet()
{
	float result = 0.0f;
	int rank[4] = { 0,0,0,0 }; //define a sort from small to big

	for (int i = 0; i < n; i++)
	{
		rank[i] = i;
	}
	result += CalculateItem(rank); //compute the first sort part

	while (true) //a endless loop to get all sorts  use exicographical order
	{
		int index1 = -1;

		int index2 = -1;

		int min = -1;

		for (int i = n - 1; i >= 0; i--) //get the first index1 (index1 = i-1,rank[i-1]<rank[i])
		{
			if (rank[i - 1] < rank[i])
			{
				index1 = i - 1;
				break;
			}
		}

		min = rank[index1 + 1];

		for (int i = index1 + 1; i < n; i++) //get the index2 (rank[index2]>rank[index1],after index1,rank[index2] is minimum)
		{
			if (rank[i] > rank[index1] && rank[i] <= min)
			{
				min = rank[i];
				index2 = i;
			}
		}
		int temp = rank[index2];

		rank[index2] = rank[index1];

		rank[index1] = temp; //exchange rank[index1] and rank[index2]

		int mid = (int)((n + index1 + 1) / 2);

		for (int i = index1 + 1; i < mid; i++) //reverse the rank after index
		{
			temp = rank[i];
			rank[i] = rank[n - (i - index1)];
			rank[n - (i - index1)] = temp;
		}
		result += CalculateItem(rank); //add every sort
		if (IsCompleteSort(rank)) //if it's the last sort,break loop
			break;
	}
	return result;
}


int main()
{
	Print();
	cout << "the result is:" << CalculateDet() << endl;
	return 0;
}
