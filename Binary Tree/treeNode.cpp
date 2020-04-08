#include "treeNode.h"
#include <iostream>
using namespace std;

template <typename U>
treeNode<U>::treeNode(U data)
{
    this->data=data;
    this->left=this->right=NULL;
}