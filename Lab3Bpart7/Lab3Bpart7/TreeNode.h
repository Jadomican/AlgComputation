//X00119321 Jason Domican - ALC Lab 3B

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
		:data(data), leftPointer(left), rightPointer(right) {}
	friend class BinarySearchTree<T>;

private:
	TreeNode<T>* leftPointer;
	TreeNode<T>* rightPointer;
	T data;

};

#endif