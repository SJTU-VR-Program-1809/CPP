#pragma once
const int MaxSize = 9;

struct Determinant
{
    const int rank;
    double deter[MaxSize*MaxSize];
    int indexArray[MaxSize];
    bool indexArrayLeftDir[MaxSize];
    int biggestIndex;
};

int CalcReversedOrder(int nums[], int size);
double Compute(Determinant *deter);
void Swap(int *index_a, bool *dir_a, int *index_b, bool *dir_b);
void PrintDeterminant(Determinant *d);
bool FindBiggest(Determinant *deter);
