//X00119321 Jason Domican
//ADS1 CA2
//Templated BST - add, delete, rebalance

#ifndef TreeNode_h
#define TreeNode_h

#include <cstdlib>
using namespace std;


template <class T>
class BinarySearchTree;

template <class T>
class TreeNode
{
public:
	// Initialise via constructor
	TreeNode(T data, TreeNode* leftNode, TreeNode* rightNode)
		:data(data), leftNode(leftNode), rightNode(rightNode) {}
	friend class BinarySearchTree<T>;
private:
	TreeNode* leftNode;
	TreeNode* rightNode;
	T data;
};

#endif
