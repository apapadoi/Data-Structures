#include <iostream>
#include "doublyLinkedList.h"
#include "doublyLinkedList.cpp"

#define TEST_LIMIT_NUMBER 10

int main()
{   
    doublyLinkedList<int> test;


    test.insertStart(5);
    test.print();
    std::cout<<endl;
    test.insertStart(8);
    test.print();
    std::cout<<endl;
    test.insertStart(9);
    test.print();
    std::cout<<endl;
    test._delete(5);
    test.print();
    std::cout<<endl;

    return 0;
}