#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H
#include "linkedList.h"
template <typename T>
class circularList : public linkedList<T>
{
    public:
        ~circularList();
        bool insertStart(const T&new_element);
        bool insertAfter(const T &previousElement,const T &new_element);
        bool insertEnd(const T &previousElement,const T &new_element);
        bool deleteStart(T &deletedElement);
        bool deleteStart();
        bool deleteAfter(const T &previousElement,T &deletedElement);
        bool deleteAfter(const T &previousElement);
        bool _delete(const T &element);
        bool deleteEnd(T &deletedElement);
        bool deleteEnd();
        void print() const;
        bool getData(int elementIndex,T &element) const;
};
#endif