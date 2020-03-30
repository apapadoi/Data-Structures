#include "node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class linkedList
{
    public:
        linkedList();
        ~linkedList();
        bool isEmpty() const;
        bool insertStart(const T &new_element);
        bool insertAfter(const T &previousElement,const T &new_element);
        bool insertEnd(const T &new_element);
        bool deleteStart(T &deletedElement);
        bool deleteStart();
        bool deleteAfter(const T &previousElement,T &deletedElement);
        bool deleteAfter(const T &previousElement);
        bool _delete(const T &element);
        bool deleteEnd(T &deletedElement);
        bool deleteEnd();
        void print() const;
        bool getData(int elementIndex,T &element) const;
    protected:
        node<T> *head;
};
#endif
