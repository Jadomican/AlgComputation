/*
* X00119321 - Jason Domican
* Algorithms and Computation - CA3
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "HuffmanNode.h"
#include <queue>
#include <bitset>
using namespace std;

/***************************************************************************************
*	Usage: based on
*	Title: Absolute C++ (5th Edition) - Chapter 19: Standard Template Library
*	Author: Savitch, W
*	Date: 29/10/2016
***************************************************************************************/

template <class T1, class T2>		// Utility function to print out each key/value in a given map.
void printMap(map<T1, T2> map)
{
	for (auto elem : map)
	{
		if (elem.first == '\n')
		{
			cout << "New Line" << ", " << elem.second << "\n";
		}
		else
		{
			cout << elem.first << ", " << elem.second << "\n";
		}
	}
}

void get_frequency(map<char, int>& frequencies)	//Function to determine frequencies for each character and populate map
{
	/***************************************************************************************
	*	Usage: modified
	*	Title: Filling map with 2 keys from a string. Character and frequency c++
	*	Date: 10/03/2018
	*	Availability: https://stackoverflow.com/questions/5272376/filling-map-with-2-keys-from-a-string-character-and-frequency-c
	*
	*	Usage: modified
	*	Title: fstream Reading Carriage Return
	*	Date: 10/03/2018
	*	Availability: http://www.cplusplus.com/forum/beginner/1893/
	***************************************************************************************/
	ifstream input_file("text.txt");			// Input stream used to open files. Open the text file for reading, current directory
	char ch;
	while ((ch = input_file.get()) != EOF)	// While the next character is not an End Of File marker
	{
		frequencies[ch]++;				// Add each character (key) to the map, increasing frequency (value) each time
	}
	input_file.close();						// Close file after reading
}

// Pass a map by reference to be filled with the character encodings based on the previously made Huffman Tree
// The tree is travesed Pre-Order, writing the path to each character as it goes - 0 being left, 1 being right
void encodeCharacters(HuffmanNode* root, string str, map<char, string>& encoded_map)  
{
	if (!root)
	{
		return;
	}

	// The ` symbol was used to represent the 'top' internal nodes in the tree. Not to be included in the encoding process.
	// Pre-order tree traversal using recursion
	if (root->data != '`')				
	{
		encoded_map[root->data] = str;	// Add the combination of 0s and 1s representing the character to the map for each character
	}
	encodeCharacters(root->left, str + "0", encoded_map);
	encodeCharacters(root->right, str + "1", encoded_map);
}


// Based on the map of encodings write the 0s and 1s representation of each character to a file
void writeEncodedText(map<char, string>& encoded_map)
{
	ifstream input_file("text.txt");			// Re-open the text file, now with the encoded map available
	ofstream encoded_file("encoded.txt"); 
	char ch;
	while ((ch = input_file.get()) != EOF)	// Write the encoded text to the new file
	{
		encoded_file << encoded_map[ch];
	}
	input_file.close();						// Close both files after reading
	encoded_file.close();
}

/***************************************************************************************
*	Usage: modified
*	Title: Huffman Decoding
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/huffman-decoding/
***************************************************************************************/

void decodeText(HuffmanNode* root)		// Decode the encoded file and write result to a new file
{
	HuffmanNode* current = root;
	ifstream input_file("encoded.txt");
	ofstream decoded_file("decoded.txt");			// File to represent the decoded string of 1's and 0's
	char ch;
	while ((ch = input_file.get()) != EOF)				// Read in each character in the file
	{
		// Traverse through the Tree based on the 1's and 0's. The unique prefix code property of the HuffMan Tree means
		// that there are no duplicate sequences of 1's and 0's that lead to a character node
		if (ch == '0')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		// When we reach the leaf node (both children nodes are NULL), write the corresponding character to the decoded file
		if (!current->left && !current->right)
		{
			decoded_file << current->data;
			//Reset the current node to the root and go again
			current = root;
		}
	}
	input_file.close();			// Close files after reading
	decoded_file.close();
}

//https://stackoverflow.com/questions/22971794/converting-binary-to-ascii
//void compressFile()
//{
//	ifstream file("encoded.txt");					// Re-open the encoded file, this time for compression
//	ofstream compressed_file("compressed.txt");		// Along with a file to hold the compressed text
//	int inChar = 0;
//	int outChar = 0;
//	int count = 0;
//	while ((inChar = file.get()) != EOF)
//	{
//		int x = inChar - '0';
//		// Ignore characters which aren't 0 or 1
//		if (x == 0 || x == 1)
//		{
//			// Accumulate the bit into the output char.
//			outChar = (outChar << 1) + x;
//			++count;
//			if (count == 8)							// 8 bit chunks
//			{
//				compressed_file.put(outChar);		// Write the compressed representation of the string of 0's and 1's
//				outChar = 0;
//				count = 0;
//			}
//		}
//	}
//	file.close();									// Close files after reading
//	compressed_file.close();
//}

void compressFile()
{
	ifstream input_file("encoded.txt");				// Re-open the encoded file, this time for compression
	ofstream compressed_file("compressed.txt");		// Along with a file to hold the compressed text

	char input_char;
	bitset<8> output_char;			// Bitset represents a fixed size sequence of bits. In this case used for 8 bit chunks
	int i = 8;

	while (input_file >> input_char)
	{
		output_char[--i] = input_char - '0';

		if (0 == i)
		{
			compressed_file << static_cast<char>(output_char.to_ulong());	// Write the compressed representation of the string of 0's and 1's
			i = 8; 
		}
	}


	input_file.close();									// Close files after reading
	compressed_file.close();

	// TODO add pseudo eof
}

void decompressFile(HuffmanNode* root)		//Decode the compressed file
{
	ifstream input_file("compressed.txt");
	ofstream decompressed_file("decompressed.txt");

	char input_char;
	string decode_buffer = "";			// String to hold the string of 1's and 0's
	bitset<8> binary_char;				// Bitset to represent the binary representation of a character

	while (input_file >> input_char)	// While there is another character
	{
		binary_char = input_char;
		decode_buffer += binary_char.to_string();	// Convert from ASCII back to binary representation
	}
	cout << decode_buffer;

	HuffmanNode* current = root;		// Set the current root as the Huffman Tree root created previously
	for (char& ch : decode_buffer)		// For each character read in from the compressed file
	{
		if (ch == '0')					
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		// When we reach the leaf node (both children nodes are NULL), write the corresponding character to the decoded file
		if (!current->left && !current->right)
		{
			decompressed_file << current->data;
			//Reset the current node to the root and go again
			current = root;
		}
	}

	decompressed_file.close();
	input_file.close();
}

/***************************************************************************************
*	Usage: based on
*	Author: Goel, A
*	Title: Greedy Algorithms | Set 3 (Huffman Coding)
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
***************************************************************************************/

void buildHuffmanTree(map<char, int> character_frequencies)
{
	// The top or 'internal' node, along with it's two child nodes
	HuffmanNode *left, *right, *top;

	/* Create a binary heap with a min-heap ordering using a priority queue. Elements with high priority (lowest frequency in this case)
	   are served before elements with lower priorities (most frequent). In this queue the container type is a vector of node pointers. 'compare'
	   is defined in HuffmanNode.h */
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> min_heap;

	// Add each character along with its frequency to the heap. The priority in which the elements are assigned is dictated by the 'compare'
	// function specified in the declaration of the queue. In this case the nodes with lowest frequency are given highest priority at the 'top' of the queue
	for (auto elem : character_frequencies)
	{
		min_heap.push(new HuffmanNode(elem.first, elem.second));
	}

	// The heap size is initially the number of unique characters in the frequencies map. Each time around this loop
	// the size decrements as elements are 'popped' off the top of the queue and added to the Huffman Tree via a new 'top' node. When the size of the
	// heap is 2, the last 2 elements are placed into the left and right nodes of the final root node and the while loop finishes
	while (min_heap.size() > 1)
	{
		//cout << "TOP: " << min_heap.top()->data << " : " << min_heap.top()->frequency << "\n";

									//The two lowest frequency nodes are gathered from the queue
		left = min_heap.top();		// Assign the left child node to the top node in the queue
		min_heap.pop();				// Remove the top element from the queue
		right = min_heap.top();		// Assign the right child node to the top node in the queue
		min_heap.pop();				// Again remove the top element

		// '`' (grave accent) is a special value not used in the text file given to internal 'top' nodes. These are NOT used in encoding/ decoding
		// Create the new 'internal' node with the value of the frequency of left the right nodes summed
		top = new HuffmanNode('`', left->frequency + right->frequency);

		// Set the new top node's children to be those same left and right nodes
		top->left = left;
		top->right = right;

		// Push the top node onto the tree gradually adding all the required nodes to the Huffman Tree. Repeat this for every two least 
		//frequent elements. After the last 2 elements are removed the final 'top' link is pushed to the tree. This is the top level root node.
		min_heap.push(top);
	}

	string str = "";										// String to represent the 0's and 1's for each character
	map<char, string> encoded_map;
	encodeCharacters(min_heap.top(), str, encoded_map);		// Encode the characters by traversing the tree
	printMap(encoded_map);

	writeEncodedText(encoded_map);							// Write the newly encoded map to a file
	decodeText(min_heap.top());								// Decode the string of 1's and 0's to a new file
	compressFile();											// Again use the encoded file, this time to compress
	decompressFile(min_heap.top());							// Decompress the file using the tree
}


int main()
{
	/***************************************************************************************
	*	Usage: modified
	*	Title: ADS1 CA1 - C++ Plagiarism Detector
	*	Authors: Domican, J & Fitzerald, R
	*	Date: 10/03/2018
	*	Availability: https://github.com/Jadomican/ads1_ca1/blob/master/main.cpp
	***************************************************************************************/

	map<char, int> frequency_map;			// Map to hold each unique character and how often it appears
	get_frequency(frequency_map);			// Populate the map with the frequencies of each character
											
	printMap(frequency_map);				//Print the contents of the map

	map<char, string> encoded_map;
	buildHuffmanTree(frequency_map);	//Build tree using the character frequencies and kick-off encoding and decoding

	system("pause");
	return 0;
}