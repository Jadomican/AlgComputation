//X00119321 Jason Domican - ALC Lab3B

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
	void add(int key);
	int height() const;
	bool hasPathSum(int sum);
private:
	void add(int key, TreeNode*& leaf);
	int height(TreeNode* height) const;
	bool hasPathSum(TreeNode* node, int sum);
	TreeNode* root;
};

#endif