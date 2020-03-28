#include <iostream>
#include "sequentialList.h"
#include "sequentialList.cpp"

#define TEST_LIMIT_NUMBER 500000

using namespace std;

int main()
{
    sequentialList<int> testSeqList(2);

    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        testSeqList.insert(i,i);
    int temp=0;
    //testSeqList.print();
    testSeqList._delete(5,temp);
    //cout<<endl;
    //cout<<"temp: "<<temp<<endl;
    //testSeqList.print();
    //cout<<endl;
    testSeqList._delete(7,temp);
    //testSeqList.print();
    //cout<<endl;
    testSeqList._delete(3,temp);
    //testSeqList.print();
    //cout<<endl;
    testSeqList.insert(10,6);
    //testSeqList.print();
    //cout<<endl;
    testSeqList.getData(0,temp);
    //cout<<"get data temp: "<<temp<<endl;

    sequentialList<float> testSeqList2(1);
    for(int i=0;i<TEST_LIMIT_NUMBER;i++) 
        testSeqList2.insert(3.5*i,i);
    float temp2;
    for(int i=0;i<TEST_LIMIT_NUMBER;i++) 
        testSeqList2._delete(2*i+10,temp2);
    //testSeqList2.print();
    
    
    return 0;
}
