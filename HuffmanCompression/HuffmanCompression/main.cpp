/*
* X00119321 - Jason Domican
* Algorithms and Computation - CA3
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

/***************************************************************************************
*	Usage: based on
*	Title: Absolute C++ (5th Edition) - Chapter 19: Standard Template Library
*	Author: Savitch, W
*	Date: 29/10/2016
***************************************************************************************/


void getFrequency(string text, map<char, int>& frequencies)		//Function to determine frequencies for each character and populate map
{
	/***************************************************************************************
	*	Usage: modified
	*	Title: Filling map with 2 keys from a string. Character and frequency c++
	*	Date: 10/03/2018
	*	Availability: https://stackoverflow.com/questions/5272376/filling-map-with-2-keys-from-a-string-character-and-frequency-c
	***************************************************************************************/

	for (string::iterator i = text.begin(); i != text.end(); i++)
	{
		frequencies[*i]++;		// Add each character (key) to the map, increasing frequency (value) each time
	}
}


int main()
{
	map<char, int> huffman_map;		// Map to hold each unique character and how often it appears
	string fileline;				// Each line of the text file
	ifstream file;
	file.open("text.txt");			// Open the text file for reading, current directory
	
	/***************************************************************************************
	*	Usage: modified
	*	Title: ADS1 CA1 - C++ Plagiarism Detector
	*	Authors: Domican, J & Fitzerald, R
	*	Date: 10/03/2018
	*	Availability: https://github.com/Jadomican/ads1_ca1/blob/master/main.cpp
	***************************************************************************************/

	while (getline(file, fileline))
	{
		getFrequency(fileline, huffman_map);	// Get each character frequency for every line in the file
	}
	file.close();								// Close the text file after reading

	for (auto elem : huffman_map)
	{
		cout << elem.first << ", " << elem.second << "\n";
	}

	system("pause");
	return 0;
}