#include <iostream>
#include "circularQueue.h"
using namespace std;

template <typename T,int CIRCULAR_QUEUE_SIZE>
circularQueue<T,CIRCULAR_QUEUE_SIZE>::circularQueue()
{
    start=finish=-1;
    if(CIRCULAR_QUEUE_SIZE>0)
        ARRAY_SIZE=CIRCULAR_QUEUE_SIZE;
    else
        ARRAY_SIZE=DEFAULT_CIRCULAR_QUEUE_SIZE;
    array=new T [ARRAY_SIZE];
}

template <typename T,int CIRCULAR_QUEUE_SIZE>
circularQueue<T,CIRCULAR_QUEUE_SIZE>::~circularQueue()
{
    delete [] array;
}

template <typename T,int CIRCULAR_QUEUE_SIZE>
bool circularQueue<T,CIRCULAR_QUEUE_SIZE>::isEmpty() const
{
    return start==-1;//we should check both start's and finish's value to be -1 but because of encapsulation 
                     //checking just one of them is enough and safe
}

template <typename T,int CIRCULAR_QUEUE_SIZE>
bool circularQueue<T,CIRCULAR_QUEUE_SIZE>::isFull() const
{
    return start==(finish+1)%ARRAY_SIZE; //if we want to check if a queue is full we will check if finish+1==start but   
                                         //if the finish is the index of the last element of the array then it must be
                                         //start==0, so in one hand when we use (finish+1)%ARRAY_SIZE if the finish is 
                                         //less than ARRAY_SIZE-1 then it behaves like finish+1==start and in the other 
                                         //hand when finish equals ARRAY_SIZE-1 then (finish+1)%ARRAY_SIZE is equal to 0 
                                        //and then we do the comparison we wanted to do in this case ( start==0 )
}

template <typename T,int CIRCULAR_QUEUE_SIZE>
bool circularQueue<T,CIRCULAR_QUEUE_SIZE>::enqueue(T enqueuedValue)
{
    if( this->isFull() )
    {
        cout<<"Circular Queue is Full!"<<endl;
        return false;
    }
    else
    {

        if( this->isEmpty() )
            start=finish=0;
        else
            finish=(finish+1)%ARRAY_SIZE;//the logic behind this line is simillar to the isFull function 
                                         //because we implement a circular queue
        array[finish]=enqueuedValue;
        return true;
    }
}

template <typename T,int CIRCULAR_QUEUE_SIZE>
bool circularQueue<T,CIRCULAR_QUEUE_SIZE>::dequeue(T &dequeuedValue)
{
    if( this->isEmpty() )
    {
        cout<<"Circular Queue is Empty!"<<endl;
        return false;
    }
    else
    {
        dequeuedValue=array[start];

        if( start==finish )
            start=finish=-1;
        else
            start=(start+1)%ARRAY_SIZE;
        
        return true;
    }
}