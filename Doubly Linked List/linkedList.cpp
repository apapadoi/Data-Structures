#include "linkedList.h"
#include "doublyNode.h"
#include "doublyNode.cpp"
#include <iostream>
using namespace std;

template <typename T>
linkedList<T>::linkedList()
{
    head=NULL;
}

template <typename T>
linkedList<T>::~linkedList()
{
    doublyNode<T>*current;
    //cout<<head;
    while(head!=NULL)
    {
        current=head;
        head=head->next;
        delete current;
    }
}

template <typename T>
bool linkedList<T>::isEmpty() const
{
    return head==NULL;
}

template <typename T>
bool linkedList<T>::insertStart(const T &new_element)
{
    doublyNode<T>* newNode=new doublyNode<T>(new_element);
    if(!newNode)
    {
        cout<<"Error while allocating memory for a new node in insertStart method"<<endl;
        return false;
    }

    newNode->next=head;
    head=newNode;
    return true;
}

template <typename T>
bool linkedList<T>::insertAfter(const T &previousElement,const T &new_element)
{
    doublyNode<T>* newNode=new doublyNode<T>(new_element);
    if(!newNode)
    {
        cout<<"Error while allocating memory for new node in insertAfter method"<<endl;
        return false;
    }
    
    doublyNode<T>* current=head;
    
    if( this->isEmpty() )
    {
        head=newNode;
        return true;
    }

    while( (current->data) != previousElement )
    {
        if( !(current->next) )
            break;
        current=current->next;
    }
    
    newNode->next=current->next;
    current->next=newNode;
    return true;
}

template <typename T>
bool linkedList<T>::insertEnd(const T &new_element)
{
    doublyNode<T>* newNode=new doublyNode<T>(new_element);
    if(!newNode)
    {
        cout<<"Error while allocating memory for new node in insertEnd method!"<<endl;
        return false;
    } 

    if( this->isEmpty() )
    {
        head=newNode;
        return true;
    }

    doublyNode<T>* current=head;
    while( (current->next) != NULL )
        current=current->next;

    current->next=newNode;
    return true;
}

template <typename T>
bool linkedList<T>::deleteStart(T &deletedElement)
{
    if( !head )// this->isEmpty()
        return false;

    doublyNode<T>* current=head;
    deletedElement=current->data;
    head=head->next;
    delete current;
    return true;
}   

template <typename T>
bool linkedList<T>::deleteStart()
{
    if( !head )
        return false;

    doublyNode<T>* current=head;
    head=head->next;
    delete current;
    return true;
}   

template <typename T>
bool linkedList<T>::deleteAfter(const T &previousElement,T &deletedElement)
{
    doublyNode<T>* previous=head;
    while( (previous->data) != previousElement )
    {
        previous=previous->next;
        if( !(previous->next) )
            return false;
    }

    doublyNode<T>* current=previous->next;
    deletedElement=current->data;
    previous->next=current->next;
    delete current;
    return true;
}

template <typename T>
bool linkedList<T>::deleteAfter(const T &previousElement)
{
    doublyNode<T>* previous=head;
    while( (previous->data) != previousElement )
    {
        previous=previous->next;
        if( !(previous->next) )
            return false;
    }
    
    doublyNode<T>* current=previous->next;
    previous->next=current->next;
    delete current;
    return true;
}

template <typename T>
bool linkedList<T>::_delete(const T &element)
{
    if( this->isEmpty() )
        return false;
    
    doublyNode<T>* current=head;
    doublyNode<T>** previous=&head;
    while( (current->data) != element)
    {
        if( !(current->next) )
            return false;
        previous=&(current->next);
        current=current->next;
    }

    *previous=current->next;
    delete current;
    return true;
}

template <typename T>
bool linkedList<T>::deleteEnd(T &deletedElement)
{
    if( this->isEmpty() )
        return false;

    doublyNode<T>*current=head;
    doublyNode<T>** previous=&head;
    while( (current->next) != NULL )
    {
        previous=&(current->next);
        current=current->next;
    }
    deletedElement=current->data;
    *previous=NULL;
    delete current;
    return true;
}

template <typename T>
bool linkedList<T>::deleteEnd()
{
    if( this->isEmpty() )
        return false;

    doublyNode<T>*current=head;
    doublyNode<T>** previous=&head;
    while( (current->next) != NULL )
    {
        previous=&(current->next);
        current=current->next;
    }

    *previous=NULL;
    delete current;
    return true;
}

template <typename T>
void linkedList<T>::print() const
{
    doublyNode<T>*current=head;

    while( current!=NULL )
    {
        //cout<<"print"<<endl;
        cout<<current->data<<" ";
        current=current->next;
    }
}

template <typename T>
bool linkedList<T>::getData(int elementIndex,T &element) const
{
    if(elementIndex<0)
        return false;
    else
    {
        doublyNode<T>*current=head;
        for(int i=0;i<elementIndex;i++)
        {
            current=current->next;
            if( !current )
                return false;
        }
        element= current->data;
        return true;
    }
}