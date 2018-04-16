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
	TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right)
		:data(data), leftNode(left), rightNode(right) {}
	friend class BinarySearchTree<T>;

	TreeNode<T>* leftNode;
	TreeNode<T>* rightNode;
	T data;

};

#endif
