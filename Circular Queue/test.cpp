#include "circularQueue.h"
#include "circularQueue.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

#define TEST_LIMIT_NUMBER 1000000000
typedef unsigned long int element;

int main()
{
    circularQueue<element,(int)(0.8*TEST_LIMIT_NUMBER)> testcircularQueue;
    
    element temp;
    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
    {
        if(!testcircularQueue.enqueue(i))
        {
            cout<<"i: "<<i<<endl;
            system("pause");
        }

        if(!(i%5))
        {
            if(!testcircularQueue.dequeue(temp))
            {
        		//cout<<temp<<endl;
            	cout<<"i: "<<i<<endl;
            	system("pause");
            }
            
            //cout<<"i: "<<i<<endl;
            //cout<<"Inside loop: "<<temp<<endl;
        }
    }

    //system("pause");
    while( ! ( testcircularQueue.isEmpty() ))
    {
        if(!testcircularQueue.dequeue(temp))
        {
        	//cout<<temp<<endl;
            //cout<<"i: "<<i<<endl;
            system("pause");
        }

        //cout<<temp<<endl;
    }
 
    return 0;
}