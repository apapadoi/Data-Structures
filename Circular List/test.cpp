#include "linkedList.h"
#include "linkedList.cpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

#define TEST_LIMIT_NUMBER 100000

int main()
{
    linkedList<int> test;

    /*
    for(unsigned long long int i=0;i<TEST_LIMIT_NUMBER;i++)
        if(!test.insertStart(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    */

    //test.print();

    /*test.insertStart(0);
    test.insertAfter(0,1);
    test.insertAfter(1,2);
    test.insertAfter(2,3);
    test.insertAfter(3,4);
    */
    /*
        for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        if(!test.insertAfter(i%5,i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    */
    //test.print();

    /*
        for(int i=0;i<TEST_LIMIT_NUMBER;i++)
            if(!test.insertEnd(i))
            {
                std::cout<<"i: "<<i<<std::endl;
                system("pause");
            }
    */
    /*test.print();
    std::cout<<std::endl;
    test.deleteStart();
    test.print();
    std::cout<<std::endl;
    test.deleteStart();
    test.print();
    std::cout<<std::endl;
    test.deleteStart();
    test.print();
    std::cout<<std::endl;
    test.deleteStart();
    test.print();
    std::cout<<std::endl;
    test.print(); */

    /*
    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        if(!test.insertStart(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }

    for(unsigned long long int i=0;i<TEST_LIMIT_NUMBER/2;i++)
        if(!test.deleteStart())
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    */
    //test.print();

    /*	
    test.insertStart(0);
    test.insertAfter(0,1);
    test.insertAfter(1,2);
    test.insertAfter(2,3);
    test.insertAfter(3,4);

    test.print();
    cout<<endl;
    test.deleteAfter(0);
    test.print();
    cout<<endl;
    test.deleteAfter(2);
    test.print();
    cout<<endl;
    if(!test.deleteAfter(4))
        cout<<"Empty list deleteAfter(4)"<<endl;
    cout<<endl;
    test.deleteAfter(2);
    test.print();
    cout<<endl;
    test.deleteAfter(0);
    test.print();
    */

    /*
    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        if(!test.insertEnd(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    //test.print();
    cout<<endl<<endl;
    for(int i=0;i<TEST_LIMIT_NUMBER;i+=2)
        if(!test.deleteAfter(i))
        {
            std::cout<<"delete i: "<<i<<std::endl;
            system("pause");
        }
    */

    /*
    if(!test._delete(0.5))
        cout<<"List has no element equal to 0"<<endl;
    test.insertStart(0.4);
    test.insertAfter(0.4,1.5);
    test.insertAfter(1.5,2.8);
    test.insertAfter(2.8,3.2);
    test.insertAfter(3.2,4.95);
    test.print();
    cout<<endl;
    test._delete(4.95);
    test._delete(2.8);
    test._delete(0.4);
    test.print(); 
    */

    /*
    for(double i=0.0;i<TEST_LIMIT_NUMBER;i+=0.2)
        if(!test.insertEnd(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    //test.print();
    //system("pause");
    for(double i=0.2;i<TEST_LIMIT_NUMBER;i+=0.2)
        if(!test._delete(i))
        {
            cout<<"i: "<<i<<endl;
            system("pause");
        }
    */
    //test.print();

    /*
    for(double i=0.0;i<TEST_LIMIT_NUMBER;i+=0.2)
        if(!test.insertEnd(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }

    for(double i=0.0;i<TEST_LIMIT_NUMBER/2;i+=0.2)
        if(!test.deleteEnd())
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    test.print();
    */

    /*
    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        if(!test.insertEnd(i))
        {
            std::cout<<"i: "<<i<<std::endl;
            system("pause");
        }
    int temp;
    if(!test.getData(-2,temp))
        cout<<"Wrong index"<<endl;

    if(test.getData(0,temp))
        cout<<"temp= "<<temp<<endl;
    
    if(test.getData(500,temp))
        cout<<"temp= "<<temp<<endl;
    else
        cout<<"Wrong index"<<endl;

    if(test.getData(25000,temp))
        cout<<"temp= "<<temp<<endl;
    else
        cout<<"Wrong index"<<endl;
    */
    return 0;
}

/* Methods Tested
insertStart 100 million
print 1 million
insertAfter 250 thousand
insertEnd 100 thousand
deleteStart 50 million
deleteAfter ~50 thousand
_delete ~100 thousand
deleteEnd ~10 thousand
getData ~100 thousand
*/
