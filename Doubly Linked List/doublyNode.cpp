#include "doublyNode.h"
#include <iostream>
using namespace std;

template <typename U>
doublyNode<U>::doublyNode(U data)
{
    this->data=data;
    this->next=this->prev=NULL;
}