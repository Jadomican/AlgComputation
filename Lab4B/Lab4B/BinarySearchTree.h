//X00119321 Jason Domican - ALC Lab4B

#ifndef BinarySearchTree_h
#define BinarySearchTree_h


#include <cstdlib>
#include "TreeNode.h"

using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL) {}
	void insert(int data);	// Add int to the tree
	bool inTree(int data) const;
	void inOrderShow() const;
	void preOrderShow() const;
	void postOrderShow() const;
	int minValue();
	int maxValue();
	int isBST();
private:
	void insert(int data, TreeNode*& subTreeRoot);
	bool inTree(int data, TreeNode* subTreeRoot) const;
	void inOrderShow(TreeNode* subTreeRoot) const;
	void preOrderShow(TreeNode* subTreeRoot) const;
	void postOrderShow(TreeNode* subTreeRoot) const;
	int minValue(TreeNode* subTreeRoot);
	int maxValue(TreeNode* subTreeRoot);
	int isBST(TreeNode* subTreeRoot);
	int isBSTRecur(TreeNode* subTreeRoot, int min, int max);
	TreeNode* root;
};


#endif