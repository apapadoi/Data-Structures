#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T,int STACK_SIZE>
stack<T,STACK_SIZE>::stack()
{
    top=-1;
    if(STACK_SIZE>0)
        ARRAY_SIZE=STACK_SIZE;
    else
        ARRAY_SIZE=DEFAULT_STACK_SIZE;
    array=new T [ARRAY_SIZE];
}

template <typename T,int STACK_SIZE>
stack<T,STACK_SIZE>::~stack()
{
    if(array)
        delete [] array;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::isEmpty() const
{
    return top==-1;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::isFull() const
{
    return top==ARRAY_SIZE-1;
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::push(T pushedValue)
{
    if( this->isFull() )
    {
        T*temporaryPointer=new T[2*ARRAY_SIZE];
        ARRAY_SIZE*=2;
        if(!temporaryPointer)
        {
            cout<<"Error while allocating memory for extra space in push method!"<<endl<<endl;
            return false;
        }
        for(int i=0;i<top+1;i++)
            temporaryPointer[i]=array[i];
        temporaryPointer[++top]=pushedValue;
        delete [] array;
        array=temporaryPointer;
        return true;
    }
    else
    {
        array[++top]=pushedValue;
        return true;
    }
}

template <typename T,int STACK_SIZE>
bool stack<T,STACK_SIZE>::pop(T &poppedValue)
{
    if( this->isEmpty() )
    {
        T*temporaryPointer= new T [ARRAY_SIZE/2];
        ARRAY_SIZE/=2;
        if(!temporaryPointer)
        {
            cout<<"Error while reducing memory in pop method!"<<endl<<endl;
            return false;
        }
        delete [] array;
        array=temporaryPointer;
        return false;
    }
    
    //there is a value to pop
    float occupancyFactor;
    if(ARRAY_SIZE)
        occupancyFactor=((float)top)/ARRAY_SIZE;//we calculate the occupancy factor "after" the array[top] has 
                                                                //been popped and then we compare it with 1/4 
    else
    {
        cout<<"Wrong ARRAY_SIZE file: stack.cpp"<<endl;
        return false;
    }
    
    if( occupancyFactor<=1/4 )
    {
        poppedValue=array[top--];
        T*temporaryPointer=new T [ARRAY_SIZE/2];
        ARRAY_SIZE/=2;
        if(!temporaryPointer)
        {
            cout<<"Error while reducing memory in pop method!"<<endl<<endl;
            return false;
        }
        for(int i=0;i<top+1;i++)
            temporaryPointer[i]=array[i];
        delete [] array;
        array=temporaryPointer;
        return true;
    }
    else
    {
        poppedValue=array[top--];
        return true;
    }
}
