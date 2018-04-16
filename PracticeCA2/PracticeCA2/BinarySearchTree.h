//X00119321 Jason Domican
//ADS1 CA2
//Templated BST - add, delete, rebalance

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <cstdlib>
#include <iostream>
#include "TreeNode.h"
#include <vector>
using namespace std;

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL) {}
	void insert(T data); // Add a value to the tree
	void deleteNode(T data);
	void inOrderShow() const;
	void preOrderShow() const;
	void postOrderShow() const;
	TreeNode<T>* minValueNode();
	bool inTree(T data) const;
	int height() const;
	int size() const;
	bool hasPathSum(T sum);
	void printPaths();
	T minValue();
	T maxValue();
	int isBST();
	TreeNode<T>* buildTree();
private:
	TreeNode<T>* root;
	void insert(T data, TreeNode<T>*& subTreeRoot);
	TreeNode<T>* deleteNode(T data, TreeNode<T>*& subTreeRoot);
	void inOrderShow(TreeNode<T>* subTreeRoot) const;
	void preOrderShow(TreeNode<T>* subTreeRoot) const;
	void postOrderShow(TreeNode<T>* subTreeRoot) const;
	TreeNode<T>* minValueNode(TreeNode<T>* node);
	bool inTree(T data, TreeNode<T>* subTreeRoot) const;
	int height(TreeNode<T>* height) const;
	int size(TreeNode<T>* size) const;
	bool hasPathSum(TreeNode<T>* node, T sum);
	void printPaths(TreeNode<T>* node, T path[], int pathLength);
	T minValue(TreeNode<T>* subTreeRoot);
	T maxValue(TreeNode<T>* subTreeRoot);
	int isBST(TreeNode<T>* subTreeRoot);
	int isBSTRecur(TreeNode<T>* subTreeRoot, T min, T max);
	TreeNode<T>* buildTree(TreeNode<T>* subTreeRoot);
	void storeBSTNodes(TreeNode<T> subTreeRoot, vector < TreeNode<T>*> &nodes);
	TreeNode<T>* buildTreeUtil(vector<TreeNode<T>*> &nodes, T start, T end);
};

// Public entry point to add a value
template <class T>
void BinarySearchTree<T>::insert(T data)
{
	insert(data, root);
}

template <class T>
void BinarySearchTree<T>::insert(T data, TreeNode<T>*& subTreeRoot)
{
	// If empty tree, insert the data and make both children null
	if (subTreeRoot == NULL)
	{
		subTreeRoot = new TreeNode<T>(data, NULL, NULL);
	}
	else if (data < subTreeRoot->data)
	{
		insert(data, subTreeRoot->leftNode);
	}
	else
	{
		insert(data, subTreeRoot->rightNode);
	}
}

// Public entry point to show tree values in-order

template <class T>
void BinarySearchTree<T>::inOrderShow() const
{
	inOrderShow(root);
}

template <class T>
void BinarySearchTree<T>::inOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrderShow(subTreeRoot->leftNode);
		cout << subTreeRoot->data << " ";
		inOrderShow(subTreeRoot->rightNode);
	}
}

template <class T>
void BinarySearchTree<T>::preOrderShow() const
{
	preOrderShow(root);
}

template <class T>
void BinarySearchTree<T>::preOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		cout << subTreeRoot->data << " ";
		preOrderShow(subTreeRoot->leftNode);
		preOrderShow(subTreeRoot->rightNode);
	}
}


template <class T>
void BinarySearchTree<T>::postOrderShow() const
{
	postOrderShow(root);
}

template <class T>
void BinarySearchTree<T>::postOrderShow(TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot != NULL)
	{
		postOrderShow(subTreeRoot->leftNode);
		postOrderShow(subTreeRoot->rightNode);
		cout << subTreeRoot->data << " ";
	}
}


template<class T>
void BinarySearchTree<T>::deleteNode(T data)
{
	deleteNode(data, root);
}


template<class T>
TreeNode<T>* BinarySearchTree<T>::minValueNode()
{
	minValueNode(root);
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::minValueNode(TreeNode<T>* node)
{
	// Gets the left-most node
	TreeNode<T>* current = node;
	while (current->leftNode != NULL)
	{
		current = current->leftNode;
	}
	return current;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::deleteNode(T data, TreeNode<T>*&subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		return subTreeRoot;
	}

	if (data < subTreeRoot->data)
	{
		subTreeRoot->leftNode = deleteNode(data, subTreeRoot->leftNode);
	}
	else if (data > subTreeRoot->data)
	{
		subTreeRoot->rightNode = deleteNode(data, subTreeRoot->rightNode);
	}
	else
	{
		if (subTreeRoot->leftNode == NULL)
		{
			TreeNode<T>* temp = subTreeRoot->rightNode;
			free (subTreeRoot);
			//delete(subTreeRoot);
			//subTreeRoot = NULL;
			return temp;
		}
		else if (subTreeRoot->rightNode == NULL)
		{
			TreeNode<T>* temp = subTreeRoot->leftNode;
			free(subTreeRoot);
			//delete(subTreeRoot);
			//subTreeRoot = NULL;
			return temp;
		}

		TreeNode<T>* temp = minValueNode(subTreeRoot->rightNode);

		subTreeRoot->data = temp->data;

		subTreeRoot->rightNode = deleteNode(temp->data, subTreeRoot->rightNode);
	}
	return subTreeRoot;
}

template <class T>
bool BinarySearchTree<T>::inTree(T data) const
{
	return inTree(data, root);
}

// Returns true if the value is in the tree
template <class T>
bool BinarySearchTree<T>::inTree(T data, TreeNode<T>* subTreeRoot) const
{
	if (subTreeRoot == NULL)
	{
		return false;
	}
	else if (subTreeRoot->data == data)
	{
		return true;
	}
	else if (data < subTreeRoot->data)
	{
		return inTree(data, subTreeRoot->leftNode);
	}
	else
	{
		return inTree(data, subTreeRoot->rightNode);
	}
}

template <class T>
int BinarySearchTree<T>::height() const
{
	return height(root);
}

template <class T>
int BinarySearchTree<T>::height(TreeNode<T>* node) const
{
	if (node == NULL)
	{
		return -1;
	}

	int left = height(node->leftNode);
	int right = height(node->rightNode);

	if (left > right)
	{
		return 1 + left;
	}
	else
	{
		return 1 + right;
	}

}


template <class T>
int BinarySearchTree<T>::size() const
{
	return size(root);
}

template <class T>
int BinarySearchTree<T>::size(TreeNode<T>* node) const
{
	if (node == NULL)
	{
		return 0;
	}
	return (1 + size(node->leftNode) + size(node->rightNode));
}

template <class T>
bool BinarySearchTree<T>::hasPathSum(T sum)
{
	return hasPathSum(root, sum);
}


template <class T>
bool BinarySearchTree<T>::hasPathSum(TreeNode<T>* subTreeRoot, T sum)
{
	if (!subTreeRoot)
	{
		return sum == static_cast<T>(0);
	}
	else
	{
		bool answer = static_cast<T>(0);

		T subSum = sum - subTreeRoot->data;

		// If at a leaf and sum becomes 0, return true
		if (subSum == static_cast<T>(0) && subTreeRoot->leftNode == NULL && subTreeRoot->rightNode == NULL)
		{
			return static_cast<T>(1);
		}

		if (subTreeRoot->leftNode)
		{
			answer = answer || hasPathSum(subTreeRoot->leftNode, subSum);
		}
		if (subTreeRoot->rightNode)
		{
			answer = answer || hasPathSum(subTreeRoot->rightNode, subSum);
		}

		return answer;
	}
}

template <class T>
T BinarySearchTree<T>::minValue()
{
	return minValue(root);
}

//Returns the left-most value in the tree, the minimum if it is properly ordered
template <class T>
T BinarySearchTree<T>::minValue(TreeNode<T>* subTreeRoot)
{
	if (subTreeRoot->leftNode != NULL)
	{
		minValue(subTreeRoot->leftNode);
	}
	else
	{
		return subTreeRoot->data;
	}
}

template <class T>
T BinarySearchTree<T>::maxValue()
{
	return maxValue(root);
}

//Returns the right-most value in the tree, the maximum if it is properly ordered
template <class T>
T BinarySearchTree<T>::maxValue(TreeNode<T>* subTreeRoot)
{
	if (subTreeRoot->rightNode != NULL)
	{
		maxValue(subTreeRoot->rightNode);
	}
	else
	{
		return subTreeRoot->data;
	}
}


template <class T>
int BinarySearchTree<T>::isBST()
{
	return isBST(root);
}


template <class T>
int BinarySearchTree<T>::isBST(TreeNode<T>* subTreeRoot)
{
	if (subTreeRoot == NULL)
	{
		return 0;
	}
	else
	{
		//Initial values for min and max are the highest and lowest Integers
		//These values get smaller with each recursive call in isBSTRecur()
		return isBSTRecur(subTreeRoot, INT_MIN, INT_MAX);
	}
}


template <class T>
int BinarySearchTree<T>::isBSTRecur(TreeNode<T>* subTreeRoot, T min, T max)
{
	if (subTreeRoot == NULL)
	{
		//Return true
		return 1;
	}

	if (subTreeRoot->data > max || subTreeRoot->data < min)
	{
		//Return false
		return 0;
	}
	else
	{
		isBSTRecur(subTreeRoot->leftNode, min, subTreeRoot->data);
		isBSTRecur(subTreeRoot->rightNode, subTreeRoot->data, max);
	}
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::buildTree()
{
	return buildTree(root);
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::buildTree(TreeNode<T>* subTreeRoot)
{
	vector<TreeNode*> nodes;
	storeBSTNodes(subTreeRoot, nodes);

	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n - 1);
}

template <class T>
void BinarySearchTree<T>::storeBSTNodes(TreeNode<T> subTreeRoot, vector <TreeNode<T>*> &nodes)
{
	if (subTreeRoot == NULL)
	{
		return;
	}

	storeBSTNodes(subTreeRoot->leftNode, nodes);
	nodes.push_back(subTreeRoot);
	storeBSTNodes(subTreeRoot->leftright, nodes);
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::buildTreeUtil(vector<TreeNode<T>*> &nodes, T start, T end)
{
	if (start > end)
	{
		return NULL;
	}

	T mid = (start + end) / 2;
	TreeNode<T>* subTreeRoot = nodes[mid];

	subTreeRoot->leftNode = buildTreeUtil(nodes, start, mid - 1);
	subTreeRoot->rightNode = buildTreeUtil(nodes, mid + 1, end);

	return subTreeRoot;
}



#endif
