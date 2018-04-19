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

const char kPseudoEOF = '¹';

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


	// Add a Pseudo-EOF character to signify the end of the file.
	frequencies[kPseudoEOF]++;


	input_file.close();						// Close file after reading
}

void buildHuffmanTree(map<char, int> character_frequencies, priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare>& min_heap)
{
	// The top or 'internal' node, along with it's two child nodes
	HuffmanNode *left, *right, *top;

	//min_heap.push(new HuffmanNode(kPseudoEOF, 1));

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
	return;
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
	int count = 0;
	while ((ch = input_file.get()) != EOF)	// Write the encoded text to the new file
	{
		count++;
		encoded_file << encoded_map[ch];
	}

	cout << "\nCOUNT: " << count;

	encoded_file << encoded_map[kPseudoEOF];		// Add the Pseudo End of File marker to signify the end of the text. Adding the
	encoded_file << encoded_map[kPseudoEOF];		// EOF twice pads out the bits for the compression stage, where 8 bit chunks are required

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
	ifstream input_file("encoded.txt");
	ofstream decoded_file("decoded.txt");			// File to represent the decoded string of 1's and 0's

	HuffmanNode* current = root;
	char ch;
	while ((ch = input_file.get()) != EOF)				// Read in each character in the file until we hit the pseudo EOF
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
			// When we get to the Pseudo EOF marker, break out of the loop.
			if (current->data == kPseudoEOF)
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

//https://stackoverflow.com/questions/22971794/converting-binary-to-ascii
void compressFile()
{
	ifstream file_input("encoded.txt");				// Re-open the encoded file, this time for compression
	ofstream compressed_file("compressed.txt");		// Along with a file to hold the compressed text

	cout << "\n\nWriting inChar: ";
	int inChar = 0;
	int outChar = 0;
	int count = 0;
	int count_compressed_chars = 0;
	while ((inChar = file_input.get()) != EOF)
	{
		cout << inChar;
		int x = inChar - '0';

		// Ignore newlines and other characters that are not '0' or '1'.
		if (x == 0 || x == 1)
		{
			// Accumulate the bit into the output char.
			outChar = (outChar << 1) + x;
			++count;
			if (count == 8)
			{
				//cout << "Outchar: " << (outChar) << "\n";
				count_compressed_chars++;
				compressed_file.put(outChar);
				outChar = 0;
				count = 0;
			}
		}
	}
	

	cout << "\nThere are " << count_compressed_chars << " compressed characters.\n";

	// Deal with unused outChar.
	if (count > 0)
	{
		cout << "\nThere are " << count << " bits that were not used.\n";
	}


	file_input.close();									// Close files after reading
	compressed_file.close();
}



//void compressFile()
//{
//	ifstream file_input("encoded.txt");				// Re-open the encoded file, this time for compression
//	ofstream compressed_file("compressed.txt");		// Along with a file to hold the compressed text
//
//	cout << "\nWriting: ";
//
//	char inChar;
//	int count = 0;
//	while ((inChar = file_input.get()) != EOF)
//	{
//
//		// Ignore newlines and other characters that are not '0' or '1'.
//		if (inChar == '0' || inChar == '1')
//		{
//			count++;
//			// Accumulate the bit into the output char.
//			if (count == 8)
//			{
//				cout << inChar;
//				count = 0;
//			}
//		}
//	}
//
//	// Deal with unused outChar.
//	if (count > 0)
//	{
//		cout << "There are " << count << " bits that were not used.\n";
//	}
//
//	file_input.close();									// Close files after reading
//	compressed_file.close();
//}


//void compressFile()
//{
//	ifstream input_file("encoded.txt");				// Re-open the encoded file, this time for compression
//	ofstream compressed_file("compressed.txt");		// Along with a file to hold the compressed text
//
//	char input_char;
//	bitset<8> output_char;			// Bitset represents a fixed size sequence of bits. In this case used for 8 bit chunks
//	int i = 8;
//
//	int countCharsIn = 0;
//	while (input_file >> input_char)
//	{
//		//cout << "\n\nCount INPUT CHAR: " << (char)input_char;
//		countCharsIn++;
//		output_char[--i] = input_char - '0';
//
//		if (0 == i)
//		{
//			
//			compressed_file << static_cast<char>(output_char.to_ulong());	// Write the compressed representation of the string of 0's and 1's
//			i = 8; 
//		}
//	}
//
//	//cout << "\n\nCount CHARS IN: " << countCharsIn << "\n\n";
//	input_file.close();									// Close files after reading
//	compressed_file.close();
//
//}




void decompressFile(HuffmanNode* root)		//Decode the compressed file
{
	ifstream input_file("compressed.txt");
	ofstream decompressed_file("decompressed.txt");

	char input_char;
	string decode_buffer;				// String to hold the string of 1's and 0's
	bitset<8> binary_char;				// Bitset to represent the binary representation of a character
	int count_decompresses = 0;
	int count_reads = 0;
	cout << "\nbinary_char: ";
	cout << "BIN CHAR:\n";
	while ((input_char = input_file.get()) != EOF)	// While there is another (compressed) character
	{
		count_reads++;
		//cout << input_char;
		binary_char = input_char;
		cout << binary_char;
		decode_buffer += binary_char.to_string();	// Convert from ASCII back to binary representation
		//cout << binary_char.to_string();
	}
	cout << "\n\nCountReads" << count_reads << "\n\n";


	cout << "\n\nDecodeBuffer:\n" << decode_buffer << "\n\n";

	HuffmanNode* current = root;		// Set the current root as the Huffman Tree root created previously
	for (char& ch : decode_buffer)		// For each character that was read in from the compressed file
	{
		//cout << ch;
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
			if (current->data == kPseudoEOF)
			{
				cout << "\n\n***Hit the Pseudo EOF***\n\n";
				break;
			}

			cout << current->data;
			count_decompresses++;
			decompressed_file << current->data;

			//Reset the current node to the root and go again
			current = root;
		}
	}

	cout << "\ncount decompresses: " << count_decompresses;


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

void inOrder(HuffmanNode* subTreeRoot)
{
	static int count;
	if (subTreeRoot != NULL)
	{
		// In-order traversal of the tree
		inOrder(subTreeRoot->left);
		int charInt(subTreeRoot->data);

		count += subTreeRoot->data;

		cout << "\n" << subTreeRoot->data << " : " << charInt;
		inOrder(subTreeRoot->right);
	}
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

	/* Create a binary heap with a min-heap ordering using a priority queue. Elements with high priority (lowest frequency in this case)
	are served before elements with lower priorities (most frequent). In this queue the container type is a vector of node pointers. 'compare'
	is defined in HuffmanNode.h */
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> min_heap;
	buildHuffmanTree(frequency_map, min_heap);					//Build tree using the character frequencies

	string str = "";														// String to represent the 0's and 1's for each character
	map<char, string> encoded_map;
	encodeCharacters(min_heap.top(), str, encoded_map);						// Encode the characters by traversing the tree. Note that the top
																			//of the heap is the root of the Huffman Tree
	
	printMap(encoded_map);

	writeEncodedText(encoded_map);											// Write the newly encoded map to a file
	decodeText(min_heap.top());												// Decode the string of 1's and 0's to a new file


	inOrder(min_heap.top());

	compressFile();															// Again use the encoded file, this time to compress
	decompressFile(min_heap.top());											// Decompress the file using the tree


	cout << "\n\n";


	system("pause");
	return 0;
}

bitset<8> toBits(unsigned char byte)
{
	return bitset<8>(byte);
}