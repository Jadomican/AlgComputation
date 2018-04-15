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
	void deleteNode(T data);
	void inOrderShow() const;
	TreeNode<T>* minValueNode();
	bool inTree(T data) const;

private:
	TreeNode<T>* root;
	void insert(T data, TreeNode<T>*& subTreeRoot);
	TreeNode<T>* deleteNode(T data, TreeNode<T>*& subTreeRoot);
	void inOrderShow(TreeNode<T>* subTreeRoot) const;
	TreeNode<T>* minValueNode(TreeNode<T>* node);
	bool inTree(T data, TreeNode<T>* subTreeRoot) const;

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
void BinarySearchTree<T>::inOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftNode);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightNode);
	}
}


template<class T>
void BinarySearchTree<T>::deleteNode(T data)
{
	deleteNode(data, root);
}


template<class T>
TreeNode<T>* BinarySearchTree<T>::minValueNode()
{
	minValueNode(root);
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::minValueNode(TreeNode<T>* node)
{
	// Gets the left-most node
	TreeNode<T>* current = node;
	while (current->leftNode != NULL)
	{
		current = current->leftNode;
	}
	return current;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::deleteNode(T data, TreeNode<T>*&subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		return subTreeRoot;
	}

	if (data < subTreeRoot->data)
	{
		subTreeRoot->leftNode = deleteNode(data, subTreeRoot->leftNode);
	}
	else if (data > subTreeRoot->data)
	{
		subTreeRoot->rightNode = deleteNode(data, subTreeRoot->rightNode);
	}
	else
	{
		if (subTreeRoot->leftNode == NULL)
		{
			TreeNode<T>* temp = subTreeRoot->rightNode;
			free (subTreeRoot);
			//delete(subTreeRoot);
			//subTreeRoot = NULL;
			return temp;
		}
		else if (subTreeRoot->rightNode == NULL)
		{
			TreeNode<T>* temp = subTreeRoot->leftNode;
			free(subTreeRoot);
			//delete(subTreeRoot);
			//subTreeRoot = NULL;
			return temp;
		}

		TreeNode<T>* temp = minValueNode(subTreeRoot->rightNode);

		subTreeRoot->data = temp->data;

		subTreeRoot->rightNode = deleteNode(temp->data, subTreeRoot->rightNode);
	}
	return subTreeRoot;
}

template <class T>
bool BinarySearchTree<T>::inTree(T data) const
{
	return inTree(data, root);
}

// Returns true if the value is in the tree
template <class T>
bool BinarySearchTree<T>::inTree(T data, TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot == NULL)
	{
		return false;
	}
	else if (subTreeRoot->data == data)
	{
		return true;
	}
	else if (data < subTreeRoot->data)
	{
		return inTree(data, subTreeRoot->leftNode);
	}
	else
	{
		return inTree(data, subTreeRoot->rightNode);
	}
}



#endif
