#include "queue.h"
#include "queue.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

#define TEST_LIMIT_NUMBER 250000

int main()
{   
    /*
    queue<int,100> testQueue1;

    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
        if( testQueue1.enqueue(i) )
            cout<<"Successfully enqueued "<<i<<" value"<<endl;
        else
            cout<<"Enqueue error!!!\t\t\t"<<endl;

    cout<<endl;
    int temporaryVariable;

    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
    {
        if( testQueue1.dequeue(temporaryVariable) )
            cout<<temporaryVariable<<" ";
        else
            cout<<"Dequeue error!\t\t\t"<<endl;

        if(!(i%15))
            cout<<endl;
    }*/


    queue<int,0> firstQueue;
    queue<float,-5> secondQueue;

    for(int i=0;i<TEST_LIMIT_NUMBER;i++)
    {
        if( firstQueue.enqueue(i) )
            cout<<"Successfully enqueued "<<i<<" value"<<endl;
        else
        {
            cout<<"Enqueue error line 44!!!\t\t\t"<<endl;
            system("pause");
        }    
        int temporaryVariable;
        if(!(i%7))
        {
            if( firstQueue.dequeue(temporaryVariable) )
            {
                if( secondQueue.enqueue(temporaryVariable*0.5) )
                    cout<<"Successfully dequeued and enqueued "<<0.5*temporaryVariable<<endl;
                else
                {
                    cout<<"Error line 49"<<endl;
                    system("pause");
                }
            }
            else
            {
                cout<<"Error line 50"<<endl;
                system("pause");    
            }
        cout<<endl;
        }
    }

    float temp;
    for(int i=0;!secondQueue.isEmpty();i++)
    {
        if( secondQueue.dequeue(temp) )
            cout<<temp<<" ";
        else
            cout<<"Dequeue error!\t\t\t"<<endl;
	}
	
    return 0; 
}
