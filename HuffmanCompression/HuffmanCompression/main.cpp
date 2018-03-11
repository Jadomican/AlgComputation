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

void getFrequency(ifstream& file, map<char, int>& frequencies)		//Function to determine frequencies for each character and populate map
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

	char ch;
	while ((ch = file.get()) != EOF)	// While the next character is not an End Of File marker
	{
		frequencies[ch]++;				// Add each character (key) to the map, increasing frequency (value) each time
	}
}

void encodeCharacters(HuffmanNode* root, string str, map<char, string>& encoded_map)
{
	if (!root)
	{
		return;
	}

	if (root->data != '£')
	{
		encoded_map[root->data] = str;
	}

	encodeCharacters(root->left, str + "0", encoded_map);
	encodeCharacters(root->right, str + "1", encoded_map);
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

	string str = "";
	map<char, string> encoded_map;
	encodeCharacters(min_heap.top(), str, encoded_map);
	printMap(encoded_map);
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
	ifstream file;
	file.open("text.txt");				// Open the text file for reading, current directory
	getFrequency(file, frequency_map);
	file.close();						// Close file after reading
	
										
	printMap(frequency_map);			//Print the contents of the map

	map<char, string> encoded_map;
	buildHuffmanTree(frequency_map, frequency_map.size());



	system("pause");
	return 0;
}