/*
* X00119321 - Jason Domican
* Algorithms and Computation - CA3
*
* Huffman Compression - This program takes a specified text file from the current directory as an
* input and builds an optimal Huffman Tree based on the file. The file is then encoded, decoded,
* compressed and decompressed by the Tree. At the end of the program various file sizes are 
* displayed to compare the benefits of Huffman Compression compared to the original file.
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

template <class T1, class T2>						// Utility function to print out each key/value in a given map.
void printMap(const map<T1, T2>& map)
{
	for (auto elem : map)
	{
		if (elem.first == '\n')
		{
			cout << "New Line" << " : " << elem.second << "\n";
		}
		else
		{
			cout << elem.first << " : " << elem.second << "\n";
		}
	}
}

// Function to determine frequencies for each character in a file and populate a given map
void getCharacterFrequencies(map<char, int>& frequencies, const string& file_name, const char& pseudo_EOF)
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

	ifstream input_file(file_name);					// Input stream used to open files. Open the text file for reading, current directory
	char input_char;
	while ((input_char = input_file.get()) != EOF)	// While the next character is not an End Of File marker
	{
		frequencies[input_char]++;					// Add each character (key) to the map, increasing frequency (value) each time
	}

	frequencies[pseudo_EOF]++;	// Add a Pseudo-EOF character to signify the end of a file. This will be added to the Huffman Tree with a frequency of 1
	input_file.close();			// Close file after reading
}

/***************************************************************************************
*	Usage: modified
*	Author: Goel, A
*	Title: Greedy Algorithms | Set 3 (Huffman Coding)
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
***************************************************************************************/

void buildHuffmanTree(const map<char, int>& character_frequencies, priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare>& min_heap)
{
	// The top or 'internal' node, along with it's two child nodes
	HuffmanNode *left, *right, *top;

	// Add each character along with its frequency to the heap. The priority in which the elements are assigned is dictated by the 'compare'
	// function specified in the declaration of the queue. In this case the nodes with lowest frequency are given highest priority at the 'top' of the queue
	for (auto elem : character_frequencies)
	{
		min_heap.push(new HuffmanNode(elem.first, elem.second));
	}

	// The heap size is initially the number of unique characters in the frequencies map. Each time around this loop the size
	// decrements as elements are 'popped' off the top of the queue and added to the Huffman Tree via a new 'top' node. When the size of the
	// heap is 2, the last 2 elements are placed into the left and right nodes of the final root node and the while loop finishes
	while (min_heap.size() > 1)
	{
									//The two least frequent nodes are gathered from the queue
		left = min_heap.top();		// Assign the left child node to the top node in the queue
		min_heap.pop();				// Remove the top element from the queue
		right = min_heap.top();		// Assign the right child node to the top node in the queue after removing the previous top
		min_heap.pop();				// Again remove the top element


		// '`' (grave accent) is a special value not used in the text file given to internal 'top' nodes. These are NOT used in encoding/ decoding
		// Create the new 'internal' node with the value of the frequency of left the right nodes summed
		top = new HuffmanNode('`', left->frequency + right->frequency);

		// Set the new top node's children to be those same left and right nodes
		top->left = left;
		top->right = right;

		// Push the top node onto the tree gradually adding all the required nodes to the Huffman Tree. Repeat this for every two least 
		// frequent elements. After the last 2 elements are removed the final 'top' link is pushed to the tree. This is the top level root node.
		min_heap.push(top);
	}
	return;
}

// Pass a map by reference to be filled with the character encodings based on the previously made Huffman Tree
// The tree is travesed Pre-Order, writing the path to each character as it goes - 0 being left, 1 being right
void encodeCharacters(HuffmanNode* root, string binary_representation, map<char, string>& encoded_map)  
{
	if (!root)
	{
		return;			// Return when the root node is NULL i.e. after processing a leaf node
	}

	// The ` symbol was used to represent the 'top' internal nodes in the tree. Not to be included in the encoding process.
	// Pre-order tree traversal using recursion
	if (root->data != '`')				
	{
		encoded_map[root->data] = binary_representation;	// Accumulate and add the combination of 0s and 1s representing the character to the map for each character
	}
	encodeCharacters(root->left, binary_representation + "0", encoded_map);
	encodeCharacters(root->right, binary_representation + "1", encoded_map);
}


// Based on the map of encodings write the 0s and 1s representation of each character to a file
void writeEncodedText(map<char, string>& encoded_map, const string& file_name, const char& pseudo_EOF)
{
	ifstream input_file(file_name);					// Re-open the text file, now with the encoded map available
	ofstream encoded_file("encoded_" + file_name);
	cout << "\nEncoding..\n";
	char input_char;
	while ((input_char = input_file.get()) != EOF)	// For every character in the file
	{
		encoded_file << encoded_map[input_char];	// Write the character's Huffman encoding to the new file
	}

	encoded_file << encoded_map[pseudo_EOF];		// Add the Pseudo End of File marker to signify the end of the text.

	input_file.close();								// Close both files after reading
	encoded_file.close();
}

/***************************************************************************************
*	Usage: modified
*	Title: Huffman Decoding
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/huffman-decoding/
***************************************************************************************/

void decodeText(HuffmanNode* root, const string& file_name, const char& pseudo_EOF)		// Decode the encoded file and write result to a new file
{
	ifstream input_file("encoded_" + file_name);
	ofstream decoded_file("decoded_" + file_name);										// File to represent the decoded string of 1's and 0's

	cout << "Decoding..";
	HuffmanNode* current = root;
	char input_char;
	while ((input_char = input_file.get()) != EOF)										// Read in each character in the file
	{
		// Traverse through the Tree based on the encoded 1's and 0's. The unique prefix code property of the HuffMan Tree means
		// that there are no duplicate sequences of 1's and 0's that lead to a character node
		if (input_char == '0')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		// When we reach the leaf node (both children nodes are NULL), write the corresponding character to the decoded file
		if (current->isLeaf())
		{
			// When we get to the Pseudo EOF marker, break out of the loop.
			if (current->data == pseudo_EOF)
			{
				break;
			}

			decoded_file << current->data;
			//Reset the current node to the root and go again
			current = root;
		}
	}
	input_file.close();			// Close files after reading
	decoded_file.close();
}

/***************************************************************************************
*	Usage: modified
*	Title: Converting binary to ASCII
*	Date: 28/03/2018
*	Availability: https://stackoverflow.com/questions/22971794/converting-binary-to-ascii
***************************************************************************************/

void compressFile(const string& file_name)						// Compress the encoded string of 1's and 0's to reducde storage space
{
	ifstream input_file("encoded_" + file_name);				// Re-open the encoded file, this time for compression
	ofstream compressed_file("compressed_" + file_name);		// Along with a file to hold the compressed text
	cout << "\nCompressing..";

	int input_char = 0;											// Integer representation of the input character
	int output_char = 0;
	int count_bits = 0;
	while ((input_char = input_file.get()) != EOF)				// Read each character in the file
	{
		int x = input_char - '0';								// Subtract ASCII 0 value from input. ('1' - '0') is like doing (49 - 48) = 1
		if (x == 0 || x == 1)									// Ignore any characters that are not 0 or 1 in the encoded file.
		{
			output_char = (output_char << 1) + x;				// Accumulate the bits into the output character.
			count_bits++;
			if (count_bits == 8)								// For every 8 bits, write the character represented by those 8 bits
			{
				compressed_file.put(output_char);
				output_char = 0;								// Reset the count and output character values
				count_bits = 0;
			}
		}
	}

	// Pad out any remaining bits to maintain 8-bitness and add to the compressed file
	if (count_bits > 0)
	{
		cout << "\nThere are " << count_bits << " bits that were not used, adding to compression now..\n";
		while (count_bits < 8) {
			output_char = (output_char << 1) + 0;
			count_bits++;
		}
		compressed_file.put(output_char);
	}

	input_file.close();											// Close files after reading
	compressed_file.close();
}

void decompressFile(HuffmanNode* root, const string& file_name, const char& pseudo_EOF)		//Decode the compressed file
{
	ifstream input_file("compressed_" + file_name);
	ofstream decompressed_file("decompressed_" + file_name);

	char input_char;
	string decode_buffer;									// String to accumulate the string of 1's and 0's
	while ((input_char = input_file.get()) != EOF)			// While there is another (compressed) character
	{
		bitset<8> binary_char(input_char);					// Place character into an 8 bit bitset to represent the char's binary representation
		decode_buffer += binary_char.to_string();			// Convert from ASCII back to binary representation
	}

	cout << "Decompressing..";
	HuffmanNode* current = root;							// Set the current root as the Huffman Tree root created previously
	for (char& decompressed_char : decode_buffer)			// For each character that was read in and decoded from the compressed file
	{
		if (decompressed_char == '0')					
		{
			current = current->left;
		}
		else if (decompressed_char == '1')
		{
			current = current->right;
		}

		// When we reach the leaf node (both children nodes are NULL), write the corresponding character to the decoded file
		if (current->isLeaf())
		{
			// If we decode the Pseudo EOF, break out of the loop and stop decompressing.
			if (current->data == pseudo_EOF)
			{
				cout << "\n**Hit the Pseudo EOF**\n";
				break;
			}
			
			decompressed_file << current->data;

			//Reset the current node to the root and start to decode the next character
			current = root;
		}
	}

	decompressed_file.close();
	input_file.close();
}

/***************************************************************************************
*	Usage: based on
*	Title: How can I get a file's size in C++?
*	Date: 18/04/2018
*	Availability: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-cs
***************************************************************************************/

// Print out the size of a given file, in bytes
void printFileSizeBytes(const char* filename)
{
	ifstream in(filename, ios::binary | ios::ate);
	cout << filename << " file size: " << in.tellg() << " bytes\n";
}

int main()
{	
	const string kFileName = "song.txt";								// The file in question to be encoded, decoded, compressed, decompressed (current directory)
	const char kPseudoEOF = '¹';										// The Pseudo-EOF character - used to tell the alrogithm when to stop decoding a file
	map<char, int> frequency_map;										// Map to hold each unique character and how often it appears
	getCharacterFrequencies(frequency_map, kFileName, kPseudoEOF);		// Populate the map with the frequencies of each character


	//Create a binary heap with a min-heap ordering using a priority queue. Elements with high priority (lowest frequency in this case)
	//are served before elements with lower priorities (most frequent). In this queue the container type is a vector of node pointers. 'compare'
	//is defined in HuffmanNode.h. A min-heap is a binary tree in which the data contained at each node is less than or equal to the data in the
	//node's children. This applies here as initially the least frequent characters appear at the top of the tree as the root before the new 'internal'
	//nodes are added. The tree is built bottom-up, combining trees to create an optimal Huffman Tree

	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> min_heap;
	buildHuffmanTree(frequency_map, min_heap);								//Build tree using the character frequencies

	string binary_representation = "";										// String to represent the 0's and 1's for each character
	map<char, string> encoded_map;											// Map of Huffman Codes for each character
	encodeCharacters(min_heap.top(), binary_representation, encoded_map);	// Encode the characters by traversing the tree. Note that the top
																			//of the heap is the root of the Huffman Tree

	cout << "Huffman Codes for " << kFileName << "\n";
	printMap(encoded_map);													// Print out the encodings for this Huffman Tree

	writeEncodedText(encoded_map, kFileName, kPseudoEOF);					// Write the encoded text to a new file using the map
	decodeText(min_heap.top(), kFileName, kPseudoEOF);						// Decode the string of 1's and 0's to a new file

	compressFile(kFileName);												// Again use the encoded file, this time to compress
	decompressFile(min_heap.top(), kFileName, kPseudoEOF);					// Decompress the file using the Huffman Tree

	cout << "\n=== Compression Results ===\n";
	printFileSizeBytes(kFileName.c_str());
	printFileSizeBytes(("encoded_" + kFileName).c_str());
	printFileSizeBytes(("compressed_" + kFileName).c_str());
	system("pause");
	return 0;
}