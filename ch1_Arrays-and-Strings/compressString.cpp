//
//  compressString.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 4/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

int digitCount(int num) {
	
	int count = 0;
	while(num) {
		count++;
		num /= 10;
	}

	return count;
}

int calcCompressedLen(const std::string & str, int len)
{
	int compressedLen = 0;
	int count = 0;
	char prev = str[0];
	
	// calc compressed string len
	for(int i=0; i<len; i++) {
		if(str[i] == prev) {
			count++;
			continue;
		}
		
		compressedLen += digitCount(count) +1;
		count = 1;
		prev = str[i];
	}
	
	if(count > 0) {
		compressedLen += digitCount(count) + 1;
	}
	
	return compressedLen;
}

std::string compressString(std::string str)
{
	int len = (int) str.size();
	int compressedLen = calcCompressedLen(str, len);

	if (compressedLen >= len) {
		return str;
	}

	int count = 0;
	char prev = str[0];
	std::string compressedStr;
	compressedStr.reserve(compressedLen);

	// build compressed string
	for(int i=0; i<len; i++) {
		if(str[i] == prev) {
			count++;
			continue;
		}

		compressedStr += prev + std::to_string(count);
		count = 1;
		prev = str[i];
	}
	compressedStr += prev + std::to_string(count);

	return compressedStr;
}

int main()
{
	std::vector<std::string> words = {"aabcccccaaa", "compressed", "aaaaabbaaaa"};
	
	std::cout << "Compress string." << std::endl;
	for(auto word : words) {
		std::cout << word << " : " << compressString(word) << std::endl;
	}
	
	return 0;
}
