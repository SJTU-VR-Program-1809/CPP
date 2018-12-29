#include <iostream>
#include "ClassDeterminent.h"
using namespace std;

int main()
{
    int a;
    float dettest[4][4] = { { 1, 4, -1, 4 }, { 0, -7, 6, -5 }, { 0, -14, 7, -5 }, { 0, -12, 12, -10 } };
    ClassDeterminent det;
    det.SetDet(dettest);
    det.PrintDet();
    cout << "the result is:" << det.ComputeDet() << endl;
    cin >> a;
    return 0;
}