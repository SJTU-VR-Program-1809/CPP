#include <iostream>;
#include"customerclass.h";
using namespace std;

void main() {
    float element[n][n]{ {1,3,0},
                         {2,3,2},
                         {1,0,1} };
    Determinant determinant{element};
    determinant.Print();
    cout << "result:" << determinant.Compute() << endl;
}

Determinant::Determinant(float _deter[n][n]) {
    rank = n;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            deter[i][j] = _deter[i][j];
        }
    }
    biggestIndex = rank-1;
    for (int i = 0; i < rank; i++) {
        indexArray[i] = i;
        isIndexLeft[i] = true;
    }
}
float Determinant::Compute() {
    float result=0;
    float mulNum = 1;
    do {
        for (int i = 0; i < rank; i++) {
            mulNum *= deter[i][indexArray[i]];
        }
        if (GetReverseNumber(indexArray) % 2 != 0) {
            mulNum *= -1;
        }
        result += mulNum;
    } 
    while (FindBiggest());
    return result;
}
int Determinant::GetReverseNumber(int _indexArray[n]) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (_indexArray[i] > _indexArray[j]) {
                count++;
            }
         }
    }
    return count;
}
bool Determinant::FindBiggest() {
    if ((biggestIndex == 0 && isIndexLeft[biggestIndex] == true) ||
        (biggestIndex == rank - 1 && isIndexLeft[biggestIndex] == false)){
        int lessNum = 2;
        bool notFind = true;
        isIndexLeft[biggestIndex]=!isIndexLeft[biggestIndex];
        do {
            if (rank - lessNum == 0)
                return false;
            for (int i = 0; i < rank; i++) {
                if (indexArray[i] == rank - lessNum) {
                    if ((i == 0 && isIndexLeft[i] == true) ||
                        (i == rank - 1 && isIndexLeft[i] == false) ||
                        (isIndexLeft[i] && indexArray[i - 1] > indexArray[i]) ||
                        (!isIndexLeft[i] && indexArray[i + 1] > indexArray[i])) {
                        lessNum++;
                        isIndexLeft[i] = !isIndexLeft[i];
                    }
                    else {
                        notFind = false;
                        if (isIndexLeft[i]) {
                            Swap(i, i - 1);
                        }
                        else {
                            Swap(i, i + 1);
                        }
                    }
                    break;
                }
            }
        } while (notFind);
    }
    else {
        if (isIndexLeft[biggestIndex]) {
            Swap(biggestIndex, biggestIndex - 1);
            biggestIndex -= 1;
        } 
        else {
            Swap(biggestIndex, biggestIndex + 1);
            biggestIndex += 1;
        }  
    }
    return true;
}
void Determinant::Swap(int a,int b){
    int tempIndex = indexArray[a];
    bool tempisLeft = isIndexLeft[a];
    indexArray[a] = indexArray[b];
    isIndexLeft[a] = isIndexLeft[b];
    indexArray[b] = tempIndex;
    isIndexLeft[b] = tempisLeft;
}

void Determinant::Print() {
    cout << "determinant:" << endl;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            cout << deter[i][j] << " " ;
        }
        cout << endl;
    }
}





 // 给排列中的每个元素均赋予一个向左的箭头。
 //如果元素k的箭头指向的是与其相邻但小于k的元素，则称元素k是活动的。
 //从排列 1 2 3 … n 开始，找其中的最大活动元素k，将该元素k与它所指向的相邻元素交换位置，并改变所有大于k的元素的方向。