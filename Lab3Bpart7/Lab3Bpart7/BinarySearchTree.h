//X00119321 Jason Domican - ALC Lab 3B

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <cstdlib>
#include "TreeNode.h"

using namespace std;

/***************************************************************************************
*	Usage: modified
*	Title: Absolute C++ (5th Edition) - Linked Data Structures (P.804-806)
*	Author: Savitch, W
*	Date: 27/02/2018
***************************************************************************************/

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL) {}
	void insert(T data);	// Add char to the tree
	bool inTree(T data) const;
	void inOrderShow() const;

private:
	void insert(T data, TreeNode<T>*& subTreeRoot);
	bool inTree(T data, TreeNode<T>* subTreeRoot) const;
	void inOrderShow(TreeNode<T>* subTreeRoot) const;
	TreeNode<T>* root;
};


template <class T>
void BinarySearchTree<T>::insert(T data, TreeNode<T>*& subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode<T>(data, NULL, NULL);
	}
	else if (data < subTreeRoot->data)
	{
		insert(data, subTreeRoot->leftPointer);
	}
	else
	{
		insert(data, subTreeRoot->rightPointer);
	}
}

template <class T>
void BinarySearchTree<T>::insert(T data)
{
	insert(data, root);
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
		return inTree(data, subTreeRoot->leftPointer);
	}
	else
	{
		return inTree(data, subTreeRoot->rightPointer);
	}
}

template <class T>
bool BinarySearchTree<T>::inTree(T data) const
{
	return inTree(data, root);
}

template <class T>
void BinarySearchTree<T>::inOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftPointer);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightPointer);
	}
}

template <class T>
void BinarySearchTree<T>::inOrderShow() const
{
	inOrderShow(root);
}

#endif

/***************************************************************************************
*    Title: Splitting templated C++ classes into .hpp/.cpp files--is it possible?
*    Date: 27/02/2018
*	 Availability: https://stackoverflow.com/questions/1724036/splitting-templated-c-classes-into-hpp-cpp-files-is-it-possible
***************************************************************************************/



