#include "binaryTree.h"
#include "treeNode.cpp"
#include "iostream"
using namespace std;

template <typename T>
binaryTree<T>::binaryTree()
{
    root=NULL;
}

template <typename T>
binaryTree<T>::~binaryTree()
{
    destroyTree( root );
}

template <typename T>
bool binaryTree<T>::isEmpty() const
{
    return root==NULL;
}

template <typename T>
bool binaryTree<T>::insertRoot(const T &new_element)
{
    if( root ) //root!=NULL
        return false;
    
    treeNode<T>*newNode = new treeNode<T>(new_element);
    if( !newNode )
    {
        cout<<"Error while allocating memory in insertRoot method"<<endl<<endl;
        return false;
    }

    root=newNode;
    return true;
}

template <typename T>
bool binaryTree<T>::insertLeft(const T &new_element)
{
    treeNode<T>* current=root;
    while( current->left != NULL )
        current=current->left;
    
    treeNode<T>*newNode= new treeNode<T>(new_element);
    if( !newNode )
    {
        cout<<"Error while allocating memory in insertLeft method"<<endl<<endl;
        return false;
    }

    current->left=newNode;
    return true;
}

template <typename T>
bool binaryTree<T>::insertRight(const T &new_element)
{
    treeNode<T>* current=root;
    while( current->right != NULL )
        current=current->right;
    
    treeNode<T>*newNode= new treeNode<T>(new_element);
    if( !newNode )
    {
        cout<<"Error while allocating memory in insertRight method"<<endl<<endl;
        return false;
    }

    current->right=newNode;
    return true;
}

template <typename T>
bool binaryTree<T>::deleteRoot(T &deletedElement)
{
    if( this->isEmpty() )
        return false;

    if( ( root->left != NULL ) || ( root->right != NULL ) )
        return false;
    
    deletedElement=root->data;
    delete root;
    root=NULL;
    return true;
}

template <typename T>
bool binaryTree<T>::deleteLeft(T &deletedElement)
{
    if( this->isEmpty() )
        return false;
    
    treeNode<T>*previous=root;
    while( ( previous->left->left != NULL ) || ( previous->left->right != NULL ) )
        previous=previous->left;

    if( !previous )
        return false;
    
    treeNode<T>*current=previous->left;
    deletedElement=current->data;
    delete current;
    previous->left=NULL;
    return true;
}

template <typename T>
bool binaryTree<T>::deleteRight(T &deletedElement)
{
    if( this->isEmpty() )
        return false;
    
    treeNode<T>*previous=root;
    while( ( previous->right->left != NULL ) || ( previous->right->right != NULL ) )
        previous=previous->right;

    if( !previous )
        return false;

    treeNode<T>*current=previous->right;
    deletedElement=current->data;
    delete current;
    previous->right=NULL;
    return true;
}

template <typename T>
bool binaryTree<T>::preOrder() const //public method
{
    if( preOrder( root ) )
        return true;
    
    return false;
}

template <typename T>
bool binaryTree<T>::preOrder( treeNode<T>* const&currentNode) const //private method
{
    if( currentNode )
    {
        printNode( currentNode->data );
        preOrder( currentNode->left );
        preOrder( currentNode->right );
    }

    return true;
}

template <typename T>
bool binaryTree<T>::inOrder() const //public method
{
    if( inOrder( root ) )
        return true;
    
    return false;
}

template <typename T>
bool binaryTree<T>::inOrder( treeNode<T>* const&currentNode) const  //private method
{
    if( currentNode )
    {
        inOrder( currentNode->left );
        printNode( currentNode->data );
        inOrder( currentNode->right );
    }

    return true;
}

template <typename T>
bool binaryTree<T>::postOrder() const //public method
{
    if( postOrder( root ) )
        return true;
    
    return false;
}

template <typename T>
bool binaryTree<T>::postOrder( treeNode<T>* const&currentNode) const //private method
{
    if( currentNode )
    {
        postOrder( currentNode->left );
        postOrder( currentNode->right );
        printNode( currentNode->data );
    }

    return true;
}

template <typename T>
void binaryTree<T>::printNode(T &element) const 
{
    cout<<element<<" ";
}

template <typename T>
void binaryTree<T>::destroyTree(treeNode<T>* currentNode)
{
    if( currentNode )
    {
        destroyTree( currentNode->left );
        destroyTree( currentNode->right );
        delete currentNode;
    }
}