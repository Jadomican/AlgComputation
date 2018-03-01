#ifndef BinarySearchTree_h
#define BinarySearchTree_h


#include <cstdlib>
#include "TreeNode.h"

using namespace std;

/***************************************************************************************
*    Usage: modified
*    Title: Absolute C++ (5th Edition) - Linked Data Structures (P.805)
*	 Author: Savitch, W
*    Date: 27/02/2018
***************************************************************************************/

class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL){}
	void insert(char data);	// Add char to the tree
	bool inTree(char data) const;
	void inOrderShow() const;

private:
	void insert(char data, TreeNode*& subTreeRoot);
	bool inTree(char data, TreeNode* subTreeRoot) const;
	void inOrderShow(TreeNode* subTreeRoot) const;
	TreeNode* root;
};


#endif