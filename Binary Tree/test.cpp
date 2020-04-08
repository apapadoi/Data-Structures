#include "binaryTree.h"
#include "binaryTree.cpp"
#include <iostream>
using namespace std;

int main()
{
    binaryTree<int> test;
    cout<<"Successfully built a binary tree of integers"<<endl;

    test.insertRoot(9);
    test.insertLeft(7);
    test.insertLeft(4);
    test.insertLeft(3);
    test.insertLeft(2);
    test.insertRight(15);
    test.insertRight(16);
    test.insertRight(28);
    test.insertRight(30);
    test.postOrder();  
    return 0;
}
