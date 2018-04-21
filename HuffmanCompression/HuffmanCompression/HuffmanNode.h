/*
* X00119321 - Jason Domican
* Algorithms and Computation - CA3
*/

#ifndef HUFFMANNODE_H 
#define HUFFMANNODE_H

// Struct representing a Huffman Tree Node
struct HuffmanNode {

	char data;					// An input character in a text file, for example
	int frequency;				// The frequency of that character in the file
	HuffmanNode* left, *right;	// Left and Right child nodes

	// Initialise the node using a constructor
	HuffmanNode(char data, int frequency)
		:data(data), frequency(frequency), left(nullptr), right(nullptr) {}

	// Determine whether or not a node is a leaf (both child nodes null)
	bool isLeaf()
	{
		if (!left && !right)
		{
			return true;
		}
		return false;
	}
};

// Struct to provide the Priority Queue with a custom ordering, in this case the nodes
// with lowest frequency are given highest priority at the 'top' of the queue
struct compare {

	bool operator()(HuffmanNode* left, HuffmanNode* right)		//Return true if the left node is more frequent than the right. 
	{
		return (left->frequency > right->frequency);
	}
};

#endif