//
//  PalindromePermutation.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 3/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <bitset>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define MAX_VAL 127

bool checkPermutation(std::string str)
{
	int len = (int) str.size();
	
	int counter[MAX_VAL];
	memset(counter, 0, sizeof(counter));
	
	for(int i = 0; i<len; i++) {
		char val = tolower(str[i]);
		counter[val]++;
	}
	
	bool foundOdd = false;
	for (int i = 0; i<MAX_VAL; i++)
		if (counter[i]%2 != 0 && i != ' ') {
			if (!foundOdd) {
				foundOdd = true;
			}
			else {
				return false;
			}
		}
	
	return true;
}


bool checkPermutation_bitset(const std::string &word)
{
	long len = word.size();
	
	std::bitset<(MAX_VAL+1)> bits(0);
	
	for(long i = 0; i<len; i++) {
		int val = tolower(word[i]);
		bits.flip(val);
	}
	
	int count = 0;
	for(long i = 0; i<len; i++) {
		int val = word[i];
		if(val != ' ') {
			count += bits.test(val);
		}
	}
	
	return (count <= 1);
}

int main()
{
	std::vector<std::string> words = {"Tact Coa", "attca", "apple"};
	
	std::cout << "Palindrome Permutation using array." << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << std::boolalpha << checkPermutation(word) << std::endl;
	}
	
	std::cout << "\n\nPalindrome Permutation using bitset." << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << std::boolalpha << checkPermutation_bitset(word) << std::endl;
	}
	
	return 0;
}
