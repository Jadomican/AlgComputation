#ifndef BinaryTree_h
#define BinaryTree_h

#include <cstdlib>
#include "TreeNode.h"

using namespace std;

/***************************************************************************************
*    Usage: modified
*    Title: Absolute C++ (5th Edition) - Linked Data Structures (P.804)
*	 Author: Savitch, W
*    Date: 27/02/2018
***************************************************************************************/


class BinaryTree
{
public:
	BinaryTree() :root(NULL) {};
	void add(int key);	// both the add and height methods are
	int height() const;
private:

	int height(TreeNode* height) const;		// implemented by a private recursive 
	void add(int key, TreeNode*& leaf);
	// Pointer to the root of the tree
	TreeNode* root;

};

#endif