//X00119321 Jason Domican - ALC Lab4A

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

void BinarySearchTree::insert(char data, TreeNode *& subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode(data, NULL, NULL);
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

void BinarySearchTree::insert(char data)
{
	insert(data, root);
}

// Returns true if the value is in the tree
bool BinarySearchTree::inTree(char data, TreeNode* subTreeRoot) const
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

bool BinarySearchTree::inTree(char data) const
{
	return inTree(data, root);
}


void BinarySearchTree::inOrderShow() const
{
	inOrderShow(root);
}

void BinarySearchTree::inOrderShow(TreeNode* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftPointer);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightPointer);
	}
}

/***************************************************************************************
*    Usage: modified
*    Title: Absolute C++ (5th Edition) - Linked Data Structures (P.817)
*	 Author: Savitch, W
*    Date: 02/03/2018
***************************************************************************************/

void BinarySearchTree::preOrderShow() const
{
	preOrderShow(root);
}

void BinarySearchTree::preOrderShow(TreeNode * subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		cout << subTreeRoot->data << " ";
		preOrderShow(subTreeRoot->leftPointer);
		preOrderShow(subTreeRoot->rightPointer);
	}
}


void BinarySearchTree::postOrderShow() const
{
	postOrderShow(root);
}

void BinarySearchTree::postOrderShow(TreeNode * subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		postOrderShow(subTreeRoot->leftPointer);
		postOrderShow(subTreeRoot->rightPointer);
		cout << subTreeRoot->data << " ";
	}
}










