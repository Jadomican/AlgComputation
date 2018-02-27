#ifndef BinaryTree_h
#define BinaryTree_h

#include <cstdlib>
#include "TreeNode.h"

using namespace std;

class BinaryTree
{
public:
	BinaryTree();
	void add(int key);	// both the add and height methods are
	int height(BinaryTree* height);		// implemented by a private recursive 

private:

	void add(int key, TreeNode* leaf);

	// Pointer to the root of the tree
	TreeNode* root;

};

#endif