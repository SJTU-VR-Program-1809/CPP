#include <iostream>
#include "Homework_1.h"

using namespace std;


//use https://matrix.reshish.com/determinant.php to Compute
//int main()
//{
//    Determinant deter1 = {
//        3,
//        {1,2,3,0,1,0,1,2,1},
//        {0,1,2},
//        {true,true,true},
//        2
//    };
//    Determinant deter2 = {
//        4,
//        {1.2,0.9,0.1,1.5,
//         2.3,3.4,5.1,1.2,
//         0.2,0.8,0.4,1.2,
//         1.7,8.4,4.7,7.4
//        },
//        {0,1,2,3},
//        {true,true,true,true},
//        3
//    };
//    PrintDeterminant(deter1);
//    cout << "The result is:" << Compute(deter1) << endl;
//    PrintDeterminant(deter2);
//    cout << "The result is:" << Compute(deter2) << endl;
//    cout << "end";
//}

double Compute(Determinant &deter)
{
    double result = 0;
    do
    {
        double mulNum = 1;
        for (int i = 0; i < deter.rank; i++)
        {
            mulNum *= deter.deter[i*deter.rank + deter.indexArray[i]];
        }
        if (CalcReversedOrder(deter.indexArray, deter.rank) % 2 != 0)
        {
            mulNum *= -1;
        }
        result += mulNum;
    } while (FindBiggest(deter));
    return result;
}

bool FindBiggest(Determinant &deter)
{
    int _bigestIndex = deter.biggestIndex;
    if ((_bigestIndex == 0 && deter.indexArrayLeftDir[_bigestIndex] == true) ||         //BiggestIndex in leftmost and dirention is left
        (_bigestIndex == deter.rank - 1 && deter.indexArrayLeftDir[_bigestIndex] == false))   //BiggestIndex in rightmost and direction is right
    {
        //Find less big index and change direction of biggest
        int lessNum = 2;
        bool notFind = true;
        //Change Direction
        deter.indexArrayLeftDir[_bigestIndex] = !deter.indexArrayLeftDir[_bigestIndex];
        do
        {
            //Finished!!!
            if (deter.rank - lessNum == 0)
                return false;
            for (int i = 0; i < deter.rank; i++)
            {
                if (deter.indexArray[i] == deter.rank - lessNum)
                {
                    if ((i == 0 && deter.indexArrayLeftDir[i] == true) ||
                        (i == deter.rank - 1 && deter.indexArrayLeftDir[i] == false) ||
                        (deter.indexArrayLeftDir[i] && deter.indexArray[i - 1] > deter.indexArray[i]) ||
                        (!deter.indexArrayLeftDir[i] && deter.indexArray[i + 1] > deter.indexArray[i]))
                    {
                        //find less less big index
                        lessNum++;
                        deter.indexArrayLeftDir[i] = !deter.indexArrayLeftDir[i];
                    }
                    else
                    {
                        //find and get less big index
                        notFind = false;
                        if (deter.indexArrayLeftDir[i])
                            Swap(&deter.indexArray[i], &deter.indexArrayLeftDir[i], &deter.indexArray[i - 1], &deter.indexArrayLeftDir[i - 1]);
                        else
                            Swap(&deter.indexArray[i], &deter.indexArrayLeftDir[i], &deter.indexArray[i + 1], &deter.indexArrayLeftDir[i + 1]);
                    }
                    break;
                }
            }
        } while (notFind);
    }
    else
    {
        int i = deter.biggestIndex;
        if (deter.indexArrayLeftDir[_bigestIndex] == true)
        {
            deter.biggestIndex -= 1;
            //swap()
            Swap(&deter.indexArray[i], &deter.indexArrayLeftDir[i], &deter.indexArray[i - 1], &deter.indexArrayLeftDir[i - 1]);
        }
        else
        {
            deter.biggestIndex += 1;
            Swap(&deter.indexArray[i], &deter.indexArrayLeftDir[i], &deter.indexArray[i + 1], &deter.indexArrayLeftDir[i + 1]);
        }
    }
    return true;
}

void PrintDeterminant(const Determinant &d)
{
    cout << "Your Deternimant is:" << endl;
    for (int i = 0; i < d.rank*d.rank; i++)
    {
        cout << "\t" << d.deter[i];
        if ((i + 1) % d.rank == 0)
            cout << '\n';

    }
}

void Swap(int *index_a, bool *dir_a, int *index_b, bool *dir_b)
{
    int tempIndex = *index_a;
    bool tempDir = *dir_a;
    *index_a = *index_b;
    *dir_a = *dir_b;
    *index_b = tempIndex;
    *dir_b = tempDir;
}

//Calculate Reverse Number
int CalcReversedOrder(const int nums[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] > nums[j])
                count++;
        }
    }
    return count;
}