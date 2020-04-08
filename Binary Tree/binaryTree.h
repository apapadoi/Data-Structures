#include "treeNode.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
template <typename T>
class binaryTree
{
    public:
        binaryTree();
        ~binaryTree();
        bool isEmpty() const;
        bool insertRoot(const T &new_element);
        bool insertLeft(const T &new_element);
        bool insertRight(const T&new_element);
        bool deleteRoot(T &deletedElement);
        bool deleteLeft(T &deletedElement);
        bool deleteRight(T &deletedElemnt);
        bool preOrder() const;
        bool inOrder() const;
        bool postOrder() const;
    private:
        treeNode<T>* root;
        void printNode(T &element) const;
        bool preOrder( treeNode<T>* const& currentNode) const;
        bool inOrder( treeNode<T>*  const& currentNode) const;
        bool postOrder( treeNode<T>* const& currentNode) const;
        void destroyTree(treeNode<T>* currentNode);
};
#endif //BINARY_TREE_H