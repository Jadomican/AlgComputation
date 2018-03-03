//X00119321 Jason Domican - ALC Lab4B

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

//Insert values into the tree in a properly ordered fashion (required for 
//min() and max() methods to function correctly later
void BinarySearchTree::insert(int data, TreeNode *& subTreeRoot)
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

void BinarySearchTree::insert(int data)
{
	insert(data, root);
}

// Returns true if the value is in the tree
bool BinarySearchTree::inTree(int data, TreeNode* subTreeRoot) const
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

bool BinarySearchTree::inTree(int data) const
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


/***************************************************************************************
*    Usage: modified
*    Title: Stanford-cslib-BinaryTree
*	 Author: Ramachandran, A
*    Date: 02/03/2018
*	 Availability: https://github.com/ArunRamachandran/Stanford-cslib-BinaryTree
***************************************************************************************/

//The min and max value methods will only work on a
//properly ordered Binary Tree
int BinarySearchTree::minValue()
{
	return minValue(root);
}

//Returns the left-most value in the tree, the minimum if it is properly ordered
int BinarySearchTree::minValue(TreeNode* subTreeRoot)
{
	if (subTreeRoot->leftPointer != NULL)
	{
		minValue(subTreeRoot->leftPointer);
	}
	else
	{
		return subTreeRoot->data;
	}
}


int BinarySearchTree::maxValue()
{
	return maxValue(root);
}

//Returns the right-most value in the tree, the maximum if it is properly ordered
int BinarySearchTree::maxValue(TreeNode* subTreeRoot)
{
	if (subTreeRoot->rightPointer != NULL)
	{
		maxValue(subTreeRoot->rightPointer);
	}
	else
	{
		return subTreeRoot->data;
	}
}

int BinarySearchTree::isBST()
{
	return isBST(root);
}

int BinarySearchTree::isBST(TreeNode * subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		return 0;
	}
	else
	{
		//Initial values for min and max are the highest and lowest Integers
		//These values get smaller with each recursive call in isBSTRecur()
		return isBSTRecur(subTreeRoot, INT_MIN, INT_MAX);
	}
}

int BinarySearchTree::isBSTRecur(TreeNode * subTreeRoot, int min, int max)
{
	if (subTreeRoot == NULL)
	{
		//Return true
		return 1;
	}

	if (subTreeRoot->data > max || subTreeRoot->data < min) 
	{
		//Return false
		return 0;
	}
	else
	{
		isBSTRecur(subTreeRoot->leftPointer, min, subTreeRoot->data);
		isBSTRecur(subTreeRoot->rightPointer, subTreeRoot->data, max);
	}
}









