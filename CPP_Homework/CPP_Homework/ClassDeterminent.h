#pragma once
#include <iostream>
using namespace std;
const int N = 100;
class ClassDeterminent
{

private:

    float det[N][N];
    int n;
public:
    ClassDeterminent();
    void SetDet(float d[4][4]);

    void PrintDet();
    float ComputeDet();

    ~ClassDeterminent();

private:
    float ComputeItem(int a[4]);
    int GetReverseNumber(int a[], int size);
    bool IsCompleteSort(int a[4]);

};

