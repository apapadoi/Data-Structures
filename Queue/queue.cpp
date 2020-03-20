#include <iostream>
#include "queue.h"
using namespace std;

template <typename T,int QUEUE_SIZE>
queue<T,QUEUE_SIZE>::queue()
{
    finish=-1;
    ARRAY_SIZE=QUEUE_SIZE;
    array=new T [ARRAY_SIZE];
}

template <typename T,int QUEUE_SIZE>
queue<T,QUEUE_SIZE>::~queue()
{
    if(array)
        delete [] array;
}

template <typename T,int QUEUE_SIZE>
bool queue<T,QUEUE_SIZE>::isEmpty() const
{
    return finish==-1;
}

template <typename T,int QUEUE_SIZE>
bool queue<T,QUEUE_SIZE>::isFull() const
{
    return finish==ARRAY_SIZE-1;
}

template <typename T,int QUEUE_SIZE>
bool queue<T,QUEUE_SIZE>::enqueue(T enqueuedValue)
{
    if( this->isFull() )
    {
        T*temporaryPointer=new T[2*ARRAY_SIZE];
        ARRAY_SIZE*=2;
        if(!temporaryPointer)
        {
            cout<<"Error while allocating memory for extra space in enqueue method!"<<endl<<endl;
            return false;
        }
        for(int i=0;i<finish+1;i++)
            temporaryPointer[i]=array[i];
        temporaryPointer[++finish]=enqueuedValue;
        delete [] array;
        array=temporaryPointer;
        return true;
    }
    else
    {
        array[++finish]=enqueuedValue;
        return true;
    }
}

template <typename T,int QUEUE_SIZE>
bool queue<T,QUEUE_SIZE>::dequeue(T &dequeuedValue)
{
    if( this->isEmpty() )
    {
        T*temporaryPointer= new T[ARRAY_SIZE/2];
        ARRAY_SIZE/=2;
        if(!temporaryPointer)
        {
            cout<<"Error while reducing memory in dequeue method!"<<endl<<endl;
            return false;
        }
        delete [] array;
        array=temporaryPointer;
        return false;
    }

    //there is a value to dequeue
    float occupancyFactor=((float)finish)/ARRAY_SIZE;//calculating the occupancy factor "after" the array[finish] has
                                                     //been dequeued and then we compare it with 1/4
    if( occupancyFactor<=1/4 )
    {
        dequeuedValue=array[0];
        T*temporaryPointer=new T [ARRAY_SIZE/2];
        ARRAY_SIZE/=2;
        if(!temporaryPointer)
        {
            cout<<"Error while reducing memory in dequeue method!"<<endl<<endl;
            return false;
        }
        for(int i=0;i<finish+1;i++)
            temporaryPointer[i]=array[i];
        delete [] array;
        array=temporaryPointer;
        for(int i=0;i<finish;i++)
            array[i]=array[i+1];
        finish--;
        return true;
    }
    else
    {
        dequeuedValue=array[0];
        for(int i=0;i<finish;i++)
            array[i]=array[i+1];
        finish--;
        return true;
    }
} 