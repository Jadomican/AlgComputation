//X00119321 Jason Domican - ALC Lab3B

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

void BinarySearchTree::inOrderShow() const
{
	inOrderShow(root);
}





