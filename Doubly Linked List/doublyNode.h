#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H
template <typename U>
class doublyNode
{
    public:
        U data;
        doublyNode<U>* next;
        doublyNode<U>* prev;
        doublyNode(U data);
};
#endif
