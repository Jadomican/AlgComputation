#ifndef TreeNode_h
#define TreeNode_h

#include <cstdlib>

using namespace std;

class TreeNode
{
	friend class BinaryTree;
public:
	TreeNode(int);

private:
	TreeNode* leftPointer;
	TreeNode* rightPointer;
	int key_value;

};


#endif