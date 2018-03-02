//X00119321 Jason Domican - ALC Lab4A

#ifndef TreeNode_h
#define TreeNode_h

#include <cstdlib>

using namespace std;

class TreeNode
{
public:
	TreeNode(int data, TreeNode* left, TreeNode* right)
		:data(data), leftPointer(left), rightPointer(right) {}
	friend class BinaryTree;

private:
	TreeNode * leftPointer;
	TreeNode* rightPointer;
	int data;

};


#endif