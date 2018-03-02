//X00119321 Jason Domican - ALC Lab4A

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
	void printPaths();

	//Utility function to print the paths to the screen
	void printPathsArray(int ints[], int length);

private:
	void add(int key, TreeNode*& leaf);
	int height(TreeNode* height) const;
	bool hasPathSum(TreeNode* node, int sum);
	TreeNode* root;
	void printPaths(TreeNode* node, int path[], int pathLength);

};

#endif