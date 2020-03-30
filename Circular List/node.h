#ifndef NODE_H
#define NODE_H
template <typename U>
class node
{
    public:
        U data;
        node<U>* next;
        node(U data);
};
#endif
