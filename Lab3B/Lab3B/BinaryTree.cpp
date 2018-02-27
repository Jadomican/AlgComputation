#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = NULL;
}

void BinaryTree::add(int key)
{
	if (root != NULL)
	{
		add(key, root);
	}
	else
	{
		// If root is null, set it
		root = new TreeNode(key);
		root->leftPointer = NULL;
		root->rightPointer = NULL;
	}
}

int BinaryTree::height(BinaryTree * height)
{
	return 0;
}


void BinaryTree::add(int key, TreeNode* leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->leftPointer != NULL)
		{
			add(key, leaf->leftPointer);
		}
		else
		{
			leaf->leftPointer = new TreeNode(key);
			leaf->leftPointer->leftPointer = NULL; //Sets the left child of the child node to null
			leaf->leftPointer->rightPointer = NULL; //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->rightPointer != NULL)
		{
			add(key, leaf->rightPointer);
		}
		else
		{
			leaf->rightPointer = new TreeNode(key);
			leaf->rightPointer->leftPointer = NULL; //Sets the left child of the child node to null
			leaf->rightPointer->rightPointer = NULL; //Sets the right child of the child node to null
		}
	}
}
