//X00119321 Jason Domican - ALC Lab3B

#ifndef TreeNode_h
#define TreeNode_h

#include <cstdlib>

using namespace std;

class TreeNode
{
public:
	TreeNode(int data, TreeNode* left, TreeNode* right)
		:key_value(data), leftPointer(left), rightPointer(right){}
	friend class BinaryTree;

private:
	TreeNode* leftPointer;
	TreeNode* rightPointer;
	int key_value;

};


#endif