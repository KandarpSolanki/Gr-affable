#include "huffman.h"

bool isPresent(string str, char s){
	for(int i = 0; i < str.length(); i++){
		if(s == str[i]) return true;
	}
	return false;
}

// Get index of the string using this function
int isPresentWhere(string str, char s){
	for(int i = 0; i < str.length(); i++){
		if(s == str[i]) return i;
	}
}

int main(){

	string str = "helloFOSS_Gr-affable";
	int size = str.length();
	int freq[size];				// Array for frequency of each character
	string data;				// Compressed string
	/**
	 * Create a string 'data' such that each element of it is
	 * a character in original string 'str', uniquely. Map it with freq
	 * For example, for str = "hellofoss" -> data = "helofs" and freq = {1,1,2,2,1,2}
	 * freq[3] = 2 = frequency of character at index 3 in data, i.e. '0'
	 * In short, freq[i] = frequency of character at data[i]
	 */
	 
	for(int i = 0; i < str.length(); i++){
	    freq[i] = 0;
	}
	/**
	 * Set all list elements to zero i.e define them
	 */
	 
	
	for(int i = 0; i < str.length(); i++){
		if(isPresent(data,str[i])){
		    cout << str[i] << "present at " << isPresentWhere(data,str[i]) << endl;
			freq[isPresentWhere(data,str[i])] += 1;
		}
		else {
			data += str[i];
			cout << str[i] << "present at " << isPresentWhere(data,str[i]) << endl;
			freq[isPresentWhere(data,str[i])] += 1;
		}
	}

	for(int i = 0; i < data.length(); i++){
		cout << data[i] << " " << freq[i] << endl;
	}

	HuffmanTree *tree = new HuffmanTree(data,freq,size);
	
    int *huffman = new int[size];
    tree->printCode(tree->root,huffman,0);
	/**
	 * Will print the huffman code for each character in given string
	 */

}

// Compile - g++ huffman.cpp
// Run 	   - ./a.out