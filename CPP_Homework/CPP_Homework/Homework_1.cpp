#include <iostream>
#include 
using namespace std;

int main()
{
    //��C#�ڶ�����ҵ����������ʽ��ֵ��ת��ΪC++����
    float[, ] dettest = new float[4, 4]{ { 1, 4, -1, 4 }, { 0, -7, 6, -5 }, { 0, -14, 7, -5 }, { 0, -12, 12, -10 } };
    Determinant det = new Determinant();
    det.SetDet(dettest);
    det.PrintDet();
    Console.WriteLine("the result is:" + det.ComputeDet());
    cout << "Test" << endl;
    return 0;
}