#ifndef HUFFMANNODE_H 
#define HUFFMANNODE_H

struct HuffmanNode {

	char data;					// An input character
	int frequency;				// The frequency of that character
	HuffmanNode* left, *right;	// Left and Right child nodes

	HuffmanNode(char data, int frequency)
		:data(data), frequency(frequency), left(nullptr), right(nullptr){}
};


struct compare {

	bool operator()(HuffmanNode* left, HuffmanNode* right)
	{
		return (left->frequency > right->frequency);
	}
};

#endif
