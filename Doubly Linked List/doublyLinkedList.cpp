#include "doublyLinkedList.h"
#include <iostream>

template <typename T>
bool doublyLinkedList<T>::insertStart(const T&new_element)
{
    if( linkedList<T>::insertStart(new_element) )
    {
        if( this->head->next!=NULL )
            this->head->next->prev=this->head;
        return true;
    }
    return false;
}

template <typename T>
bool doublyLinkedList<T>::insertAfter(const T &previousElement,const T &new_element)
{
    doublyNode<T>* newNode=new doublyNode<T>(new_element);
    if(!newNode)
    {
        cout<<"Error while allocating memory for new node in doublyLinkedList::insertAfter method"<<endl;
        return false;
    }

    doublyNode<T>* previous=this->head;

    if( this->isEmpty() )
    {
        this->head=newNode;
        return true;
    }

    while( (previous->data) != previousElement )
    {
        if( !(previous->next) )
            break;
        previous=previous->next;
    }

    newNode->next=previous->next;
    newNode->prev=previous;
    previous->next=newNode;  
    if( newNode->next!=NULL )
        newNode->next->prev=newNode;
    return true;
}

template <typename T>
bool doublyLinkedList<T>::insertEnd(const T&new_element)
{
    doublyNode<T>* newNode=new doublyNode<T>(new_element);
    if(!newNode)
    {
        cout<<"Error while allocating memory for new node in doublyLinkedList::insertEnd method!"<<endl;
        return false;
    } 
    
    if( this->isEmpty() )
    {
        this->head=newNode;
        return true;
    }

    doublyNode<T>* current=this->head;
    while( (current->next) != NULL )
        current=current->next;

    current->next=newNode;
    newNode->prev=current;
    return true;
}   

template <typename T>
bool doublyLinkedList<T>::deleteStart(T &deletedElement)
{
    if( linkedList<T>::deleteStart(deletedElement) )
    {
        if( this->head!=NULL )
            this->head->prev=NULL;
        return true;
    }
    return false;
}

template <typename T>
 bool doublyLinkedList<T>::deleteStart()
 {
     if( linkedList<T>::deleteStart() )
     {
         if( this->head!=NULL )
            this->head->prev=NULL;
        return true;
     }
     return false;
 }

 template <typename T>
 bool doublyLinkedList<T>::deleteAfter(const T &previousElement,T &deletedElement)
 {
    doublyNode<T>* previous=this->head;
    while( (previous->data) != previousElement )
    {
        previous=previous->next;
        if( !(previous->next) )
            return false;
    }

    doublyNode<T>* current=previous->next;
    deletedElement=current->data;
    previous->next=current->next;
    if( current->next!=NULL )
        current->next->prev=previous;
    delete current;
    return true;
 }

template <typename T>
bool doublyLinkedList<T>::deleteAfter(const T &previousElement)
{
    T temp;
    if( doublyLinkedList::deleteAfter(previousElement,temp) )
        return true;
    
    return false;
}

template <typename T>
bool doublyLinkedList<T>::_delete(const T &element)
{
    if( this->isEmpty() )
        return false;
    
    doublyNode<T>* current=this->head;
    doublyNode<T>** previous=&(this->head);
    while( (current->data) != element)
    {
        if( !(current->next) )
            return false;
        previous=&(current->next);
        current=current->next;
    }

    *previous=current->next;
    if( current->next!=NULL )
        current->next->prev=current->prev;
    delete current;
    return true;
}

template <typename T>
bool doublyLinkedList<T>::deleteEnd(T &deletedElement)
{
    if( linkedList<T>::deleteEnd(deletedElement) )
        return true;
    
    return false;
}

template <typename T>
bool doublyLinkedList<T>::deleteEnd()
{
    if( linkedList<T>::deleteEnd() )
        return true;
    
    return false;
}