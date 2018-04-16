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
};

// Used to provide the Priority Queue with a custom ordering, in this case based
// on the frequency of each character that appears in the given text file
struct compare {

	bool operator()(HuffmanNode* left, HuffmanNode* right)
	{
		return (left->frequency > right->frequency);
	}
};

#endif