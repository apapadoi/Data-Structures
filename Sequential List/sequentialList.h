#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H

#define DEFAULT_SEQUENTIAL_LIST_SIZE 10

template <typename T>
class sequentialList
{
    public:
        sequentialList(int arraySize);
        ~sequentialList();
        bool isEmpty() const;
        bool isFull() const;
        bool insert(const T &new_element,int index);
        bool _delete(int index,T &deletedElement);
        void print() const;
        bool getData(int index,T &element) const;
    private:
       T*array;
       int totalElements;
       int arraySize; 
};
#endif