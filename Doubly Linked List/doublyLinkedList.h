#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "linkedList.h"
#include "linkedList.cpp"

template <typename T>
class doublyLinkedList : public linkedList<T>
{
    public:
        bool insertStart(const T &new_element);
        bool insertAfter(const T &previousElement,const T &new_element);   
        bool insertEnd(const T&new_element); 
        bool deleteStart(T &deletedElement);
        bool deleteStart();
        bool deleteAfter(const T &previousElement,T &deletedElement);
        bool deleteAfter(const T &previousElement);
        bool _delete(const T &element);
        bool deleteEnd(T &deletedElement);
        bool deleteEnd();
};
#endif