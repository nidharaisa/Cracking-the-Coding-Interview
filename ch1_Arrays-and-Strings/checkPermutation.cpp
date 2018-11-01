//
//  checkPermutation.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 2/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_VAL 256

bool checkPermutation(std::string first, std::string second, bool caseSensitive = true, bool spaceSensitive = true)
{
	int len1 = (int) first.size();
	int len2 = (int) second.size();
	
	if (spaceSensitive) {
		if(first.size() != second.size())
			return false;
	}
	
	int counter[MAX_VAL];
	memset(counter, 0, sizeof(counter));
	
	for(int i = 0; i<len1; i++) {
		char val = caseSensitive ? first[i] : tolower(first[i]);
		counter[val]++;
	}
	
	for(int i = 0; i<len2; i++) {
		char val = caseSensitive ? second[i] : tolower(second[i]);
		counter[val]--;
	}
	
	for (int i = 0; i<MAX_VAL; i++)
		if (counter[i] != 0) {
			if(!spaceSensitive && i == ' ') continue;
			return false;
		}
	
	return true;
}

int main()
{
	std::cout << "case sensitive : ('Dog', 'God') : " << std::boolalpha << checkPermutation("Dog", "God") << std::endl;
	
	std::cout << "case insensitive : ('Dog', 'God') : " << std::boolalpha << checkPermutation("Dog", "God", false) << std::endl;
	
	std::cout << "space sensitive : ('Dog  ', 'God') : " << std::boolalpha << checkPermutation("Dog  ", "God", false) << std::endl;
	
	std::cout << "space insensitive : ('Dog  ', 'God') : " << std::boolalpha << checkPermutation("Dog  ", "God", false, false) << std::endl;
	
	return 0;
}
