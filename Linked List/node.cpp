#include "node.h"
#include <iostream>
using namespace std;

template <typename U>
node<U>::node(U data)
{
    this->data=data;
    this->next=NULL;
}