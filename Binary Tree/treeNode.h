#ifndef TREE_NODE_H
#define TREE_NODE_H
template <typename U>
class treeNode
{
    public:
        treeNode(U data);
        U data;
        treeNode<U>*left;
        treeNode<U>*right;
};
#endif //TREE_NODE_H
