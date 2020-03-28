#include <iostream>
#include "sequentialList.h"

template <typename T>
sequentialList<T>::sequentialList(int arraySize)
{
    if(arraySize>0)
        this->arraySize=arraySize;
    else
        this->arraySize=DEFAULT_SEQUENTIAL_LIST_SIZE;

    totalElements=0;
    array=new T [this->arraySize];
}

template <typename T>
sequentialList<T>::~sequentialList()
{
    delete [] array;
}

template <typename T>
bool sequentialList<T>::isEmpty() const
{
    return totalElements==0;
}

template <typename T>
bool sequentialList<T>::isFull() const
{
    return totalElements==arraySize;
}

template <typename T>
bool sequentialList<T>::insert(const T &new_element,int index)
{
    if(index<0 || index>totalElements)
        return false;
    
    if( this->isFull() )
    {
        T*temporaryPointer=new T [2*arraySize];
        arraySize*=2;
        if(!temporaryPointer)
        {
            std::cout<<"Error while allocating memory for extra space in insert method!"<<std::endl<<std::endl;
            return false;
        }
        for(int i=0;i<totalElements;i++)
            temporaryPointer[i]=array[i];
        delete [] array;
        array=temporaryPointer;
    }

    for(int i=totalElements;i>index;i--)
        array[i]=array[i-1];
    
    array[index]=new_element;
    totalElements++;
    return true;
}

template <typename T>
bool sequentialList<T>::_delete(int index,T &deletedElement)
{
    if( this->isEmpty() )
    {
        T*temporaryPointer=new T [arraySize/2];
        if(!temporaryPointer)
        {
            std::cout<<"Error while reducing memory in _delete method!"<<std::endl<<std::endl;
            return false;
        }
        arraySize/=2;
        delete [] array;
        array=temporaryPointer;
        return false;
    }

    if(index<0 || index>=totalElements)
        return false;
    
    float occupancyFactor;
    if(arraySize)
        occupancyFactor=((float)(totalElements-1))/arraySize;
    else
    {
        std::cout<<"Wrong arraySize in method _delete!"<<std::endl<<std::endl;
        return false;
    }

    if( occupancyFactor<= 1/4.0 )
    {
        deletedElement=array[index];
        for(int i=index;i<totalElements-1;i++)
            array[i]=array[i+1]; 
           
        totalElements--;
        T*temporaryPointer=new T [arraySize/2];
        if(!temporaryPointer)
        {
            std::cout<<"Error while reducing memory in _delete method!"<<std::endl<<std::endl;
            return false;
        }
        for(int i=0;i<totalElements;i++)
            temporaryPointer[i]=array[i];
        delete [] array;
        array=temporaryPointer;
        return true;
    } 
    else
    {
        deletedElement=array[index];
        for(int i=index;i<totalElements-1;i++)
            array[i]=array[i+1];

        totalElements--;
        return true;
    }
}

template <typename T>
void sequentialList<T>::print() const
{
    for(int i=0;i<totalElements;i++)
        std::cout<<array[i]<<" ";
}

template <typename T>
bool sequentialList<T>::getData(int index,T &element) const
{
    if(index<0 || index>=totalElements)
        return false;
    
    element=array[index];
    return true;
}