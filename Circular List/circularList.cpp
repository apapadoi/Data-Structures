#include <iostream>
#include "circularList.h"

template <typename T>
circularList<T>::~circularList()
{
    if( this->head->next == this->head )
    {
        this->head->next=NULL;
    }

    node<T>* current=this->head->next;
    while( current->next != this->head )
        current=current->next;
    
    current->next=NULL;
}

template <typename T>
bool circularList<T>::insertStart(const T&new_element)
{
    node<T>* newNode=new node<T>(new_element);
    if(!newNode)
    {
        std::cout<<"Error while allocating memory for a new node in circularList::insertStart method!"<<std::endl<<std::endl;
        return false;
    }

    if( this->isEmpty() )
    {
        this->head=newNode;
        this->head->next=this->head;
        return true;
    }

    node<T>* last=this->head;

    while( last->next != this->head )
        last=last->next;
    
    last->next=newNode;
    newNode->next=this->head;
    this->head=newNode;
    return true;
}

template <typename T>
bool circularList<T>::insertAfter(const T &previousElement,const T &new_element)
{
    if( linkedList<T>::insertAfter(previousElement,new_element) )
    {
        if( this->head->next=NULL )
            this->head->next=this->head;
        
        return true;
    }

    return false;
}

template <typename T>
bool circularList<T>::insertEnd(const T &previousElement,const T &new_element)
{
    node<T>* newNode=new node<T>(new_element);
    if(!newNode)
    {
        std::cout<<"Error while allocating memory for new node in circularList::insertEnd method!"<<std::endl;
        return false;
    } 

    if( this->isEmpty() )
    {
        this->head=newNode;
        newNode->next=this->head;
        return true;
    }

    node<T>* current=this->head;
    while ( (current->next) != this->head )
        current=current->next;

    current->next=newNode;
    newNode->next=this->head;
    return true;
}

template <typename T>
bool circularList<T>::deleteStart(T &deletedElement)
{
    if( this->isEmpty() )
        return false;

    if( this->head==this->head->next )
    {
        deletedElement=this->head->data;
        delete this->head;
        this->head=NULL;
        return true;
    }

    deletedElement=this->head->data;
    node<T>* last=this->head->next;
    while ( last->next != this->head )
        last=last->next;

    last->next=this->head->next;
    delete this->head;
    this->head=last->next;
    return true;
}

template <typename T>
bool circularList<T>::deleteStart()
{
    T temp;
    if( circularList::deleteStart(temp) )
        return true;
    
    return false;
}

template <typename T>
bool circularList<T>::deleteAfter(const T &previousElement,T &deletedElement)
{
    if( this->isEmpty() )
        return false;

    node<T> * previous=this->head;

    if( this->head == this->head->next)
        return false;

    while( (previous->data) != previousElement )
    {
        previous=previous->next;
        if ( previous->next == this->head )
            return false;
    }

    node<T>* current=previous->next;
    deletedElement=current->data;
    previous->next=current->next;
    delete current;
    return true;
}

template <typename T>
bool circularList<T>::deleteAfter(const T &previousElement)
{
    T temp;
    if( circularList::deleteAfter(previousElement,temp) )
        return true;
    
    return false;
}

template <typename T>
bool circularList<T>::_delete(const T &element)
{
    if( this->isEmpty() )
        return false;
    
    if( ( this->head->data == element ) && ( this->head->next == this->head ) )
    {
        delete this->head;
        this->head=NULL;
        return true;
    }

    if( this->head->data == element )//if the element is in the first "position" of the list
    {
        node<T>* current=this->head;
        node<T>* last=this->head->next;

        while( last->next != this->head )
            last=last->next;

        last->next=this->head->next;
        this->head=this->head->next;
        delete current;
        return true;
    }

    node<T>* current=this->head->next;//if the control of the program reaches this line it means that the element is not at the start of the list
    node<T>** previous=&(this->head->next);

    while( (current->data) != element )
    {
        if( current->next == this->head )
            return false;
        
        previous=&(current->next);
        current=current->next;
    }

    *previous=current->next;
    delete current;
    return true;
}

template <typename T>
bool circularList<T>::deleteEnd(T &deletedElement)
{
    if( this->isEmpty() )
        return false;

    if( this->head->next == this->head )// list has only 1 element
    {
        deletedElement=this->head->data;
        delete this->head;
        this->head=NULL;
        return true;
    }

    node<T>* current=this->head;
    node<T>** previous=&(this->head);
    while( (current->next) != this->head )
    {
        previous=&(current->next);
        current=current->next;
    }
    deletedElement=current->data;
    *previous=current->next;
    delete current;
    return true;
}

template <typename T>
bool circularList<T>::deleteEnd()
{
    T temp;
    if ( circularList::deleteEnd(temp) )
        return true;

    return false;
}

template <typename T>
void circularList<T>::print() const
{
    node<T>* current=this->head;
    
    if( !( this->isEmpty() ) )
    {
        std::cout<<current->data<<" ";

        current=current->next;
        while ( current != this->head )
        {
            std::cout<<current->data<<" ";
            current=current->next;
        }
    }
}

template <typename T>
bool circularList<T>::getData(int elementIndex,T &element) const
{
    if( element<0 || this->isEmpty() )
        return false;
    else
    {
        if(!elementIndex)
        {
            element=this->head->data;
            return true;
        }

        node<T>* current=this->head->next;
        for(int i=1;i<elementIndex;i++)
        {
            current=current->next;
            if( current == this->head )
                return false;
        }
        element=current->data;
        return true;
    }
}
