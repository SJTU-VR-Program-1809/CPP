#include<iostream>
#include"SingleLinkList.h"

using namespace std;

int main() {
    SingleLinkList list{ 1,2,3,4,5 };
    list.Print();
    list.Reverse();
    list.Print();                                                   //5,4,3,2,1
    auto pNode = list.GetLastNth(4);  
    if (pNode) {
        cout << "the 4th node value: " << pNode->value << endl;     //4
        list.Insert(pNode, 7);
        list.Print();                                               //5,4,7,3,2,1
    }
    else
        cout << "out of the length of list" << endl;
    list.Push_Back(10);
    if (!list.IsEmpty())
        cout << "listsize: " << list.Size() << endl;                //7
    SingleLinkList k = list;
    k.Print();                                                      //5,4,7,3,2,1,10
    SingleLinkList h = std::move(list);
    h.Print();                                                      //5,4,7,3,2,1,10
    list.Print();                                                   //null
   
    return 0;
}