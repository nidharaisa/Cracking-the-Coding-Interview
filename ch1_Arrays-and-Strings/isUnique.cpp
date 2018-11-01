//
//  isUnique.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 1/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <bitset>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

	// largest extended ascii value is 255, if not using extended one use 127
#define largest_ASCII_value 255

bool isUnique_bitset(const std::string &word)
{
	long len = word.size();
	
	if (len > largest_ASCII_value) {
		return false;
	}
	
	std::bitset<(largest_ASCII_value+1)> bits(0);
	
	for(long i = 0; i<len; i++) {
		int val = word[i];
		
		if(true == bits.test(val)) {
			return false;
		}
		
		bits.set(val);
	}
	return true;
}

bool isUnique_loop(const std::string &word)
{
	long len = word.size();
	
	if (len > largest_ASCII_value) {
		return false;
	}
	
	for(long i = 0; i<len-1; i++)
		for(long j = i+1; j<len; j++) {
			if(word[j] == word[i])
				return false;
		}
	
	return true;
}

std::string mergeSort(std::string &word, int start, int end)
{
	if(start == end) return word;
	
	int mid = (start + end)/2;
	
	mergeSort(word, start, mid);
	mergeSort(word, mid+1, end);
	
	int i = start, j = mid+1;
	
	for( ; i<end && j<=end; i++) {
		
		if(word[i] > word[j]) {
			std::swap(word[i], word[j]);
			
			if (word[j] > word[j+1]) j++;
		}
	}
	
	return word;
}

bool isUnique_mergeSort(std::string word)
{
	int len = (int) word.size()-1;
	mergeSort(word, 0, len);
	
	for(int i = 0; i<len; i++) {
		if(word[i] == word[i+1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	std::vector<std::string> words = {"pine", "apple", "pineapple"};
	
	std::cout << "isUnique test using bitset." << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << std::boolalpha << isUnique_bitset(word) << std::endl;
	}
	
	std::cout << "\n\nisUnique test using simple loop. O(n*n)" << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << std::boolalpha << isUnique_loop(word) << std::endl;
	}
	
	std::cout << "\n\nisUnique test using merge sort. O(NlogN)" << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << std::boolalpha << isUnique_mergeSort(word) << std::endl;
	}
	
	return 0;
}
