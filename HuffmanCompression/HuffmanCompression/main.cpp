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
using namespace std;

ifstream file;		// Global variable to represent the file to be scanned

/***************************************************************************************
*	Usage: based on
*	Title: Absolute C++ (5th Edition) - Chapter 19: Standard Template Library
*	Author: Savitch, W
*	Date: 29/10/2016
***************************************************************************************/

template <class T1, class T2>
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

void getFrequency(map<char, int>& frequencies)		//Function to determine frequencies for each character and populate map
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
	file.open("text.txt");				// Open the text file for reading, current directory
	char ch;
	while ((ch = file.get()) != EOF)	// While the next character is not an End Of File marker
	{
		frequencies[ch]++;				// Add each character (key) to the map, increasing frequency (value) each time
	}
	file.close();						// Close file after reading
}

void encodeCharacters(HuffmanNode* root, string str, map<char, string>& encoded_map)
{
	if (!root)
	{
		return;
	}
	
	if (root->data != '£')				// Pre-order tree traversal
	{
		encoded_map[root->data] = str;	// Add the combination of 0s and 1s representing the character
	}
	encodeCharacters(root->left, str + "0", encoded_map);
	encodeCharacters(root->right, str + "1", encoded_map);
}

void writeEncodedText(map<char, string>& encoded_map)
{
	file.open("text.txt");				// Re-open the text file, now with the encoded map available
	ofstream encoded_file;
	encoded_file.open("encoded.txt");
	char ch;
	while ((ch = file.get()) != EOF)	// Write the encoded text to the new file
	{
		encoded_file << encoded_map[ch];
	}
	file.close();
	encoded_file.close();
}

/***************************************************************************************
*	Usage: modified
*	Title: Huffman Decoding
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/huffman-decoding/
***************************************************************************************/

void decodeText(HuffmanNode* root, string str)		// Decode the encoded file and write result to a new file
{
	HuffmanNode* current = root;
	file.open("encoded.txt");						// Open previously opened file
	ofstream decoded_file;
	decoded_file.open("decoded.txt");				// File to represent the decoded file
	char ch;
	while ((ch = file.get()) != EOF)
	{
		if (ch == '0')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		if (!current->left && !current->right)
		{
			decoded_file << current->data;
			current = root;
		}
	}
	file.close();
	decoded_file.close();
}

//https://stackoverflow.com/questions/22971794/converting-binary-to-ascii
void compressFile()
{
	file.open("encoded.txt");		//Re-open the encoded file, this time for compression
	ofstream compressed_file;
	compressed_file.open("compressed.txt");
	int inChar = 0;
	int outChar = 0;
	int count = 0;
	while ((inChar = file.get()) != EOF)
	{
		int x = inChar - '0';
		// Ignore characters which aren't 0 or 1
		if (x == 0 || x == 1)
		{
			// Accumulate the bit into the output char.
			outChar = (outChar << 1) + x;
			++count;
			if (count == 8)							// 8 bit chunks
			{
				compressed_file.put(outChar);		// Write the compressed representation of the string of 0's and 1's
				outChar = 0;
				count = 0;
			}
		}
	}
	file.close();
	compressed_file.close();
}

void decompressFile()		//Decode the compressed file
{
	file.open("compressed.txt");
	ofstream decompressed_file;
	decompressed_file.open("decompressed.txt");



	decompressed_file.close();
	file.close();
}

/***************************************************************************************
*	Usage: based on
*	Author: Goel, A
*	Title: Greedy Algorithms | Set 3 (Huffman Coding)
*	Date: 10/03/2018
*	Availability: https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
***************************************************************************************/

void buildHuffmanTree(map<char, int> frequencies, int size)
{
	HuffmanNode *left, *right, *top;

	// Create a binary heap with a min-heap ordering
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> min_heap;

	// Add each character along with its frequency to the heap
	for (auto elem : frequencies)
	{
		min_heap.push(new HuffmanNode(elem.first, elem.second));
	}

	while (min_heap.size() != 1)
	{
		left = min_heap.top();
		min_heap.pop();
		right = min_heap.top();
		min_heap.pop();

		// '£' is a special value not used in the text
		top = new HuffmanNode('£', left->frequency + right->frequency);
		top->left = left;
		top->right = right;

		min_heap.push(top);
	}

	string str = "";					// String to represent the 0's and 1's for each character
	map<char, string> encoded_map;
	encodeCharacters(min_heap.top(), str, encoded_map);
	printMap(encoded_map);

	writeEncodedText(encoded_map);
	decodeText(min_heap.top(), str);
	compressFile();
	decompressFile();
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
	getFrequency(frequency_map);
											
	printMap(frequency_map);				//Print the contents of the map

	map<char, string> encoded_map;
	buildHuffmanTree(frequency_map, frequency_map.size());	//Build tree and kick-off encoding and decoding

	system("pause");
	return 0;
}