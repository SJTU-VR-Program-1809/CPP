#pragma once
#include<iostream>;
using namespace std;
const int n =3;

class Determinant {
public:
    int rank;
 
    Determinant(float _deter[n][n]);
    void Print();
    float Compute();

private:
    float deter[n][n];
    int indexArray[n];
    int biggestIndex;
    bool isIndexLeft[n];

    void Swap(int a, int b);
    int GetReverseNumber(int _indexArray[n]);
    bool FindBiggest();
};