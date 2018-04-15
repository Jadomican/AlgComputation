//X00119321 Jason Domican
//ADS1 CA2
//Templated BST - add, delete, rebalance

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <cstdlib>
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL) {}
	void insert(T data); // Add a value to the tree
	void inOrderShow() const;

private:
	TreeNode<T>* root;
	void insert(T data, TreeNode<T>*& subTreeRoot);
	void inOrderShow(TreeNode<T>* subTreeRoot) const;
};

// Public entry point to add a value
template <class T>
void BinarySearchTree<T>::insert(T data)
{
	insert(data, root);
}

template <class T>
void BinarySearchTree<T>::insert(T data, TreeNode<T>*& subTreeRoot)
{
	// If empty tree, insert the data and make both children null
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode<T>(data, NULL, NULL);
	}
	else if (data < subTreeRoot->data)
	{
		insert(data, subTreeRoot->leftNode);
	}
	else
	{
		insert(data, subTreeRoot->rightNode);
	}
}

// Public entry point to show tree values in-order

template <class T>
void BinarySearchTree<T>::inOrderShow() const
{
	inOrderShow(root);
}

template <class T>
void BinarySearchTree<T>::inOrderShow(TreeNode<T> * subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		inOrderShow(subTreeRoot->leftNode);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightNode);
	}
}

#endif
