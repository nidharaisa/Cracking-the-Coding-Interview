//
//  oneEditAway.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 4/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

bool oneEditAway(std::string first, std::string second)
{
	if(first.size() < second.size()) {
		std::swap(first, second);
	}
	
	int len1 = (int) first.size();
	int len2 = (int) second.size();
	
	if( (len1-len2) > 1) {
		return false;
	}
	
	int i = 0, j = 0;
	bool mismatchFound = false;
	
	for (; j<len2; i++, j++) {
		if(first[i] != second[j])
			{
			if(false == mismatchFound) {
				if (first[i+1] == second[j]) {
					i++;
				}
				mismatchFound = true;
				continue;
			}
			return false;
			}
	}
	
	if(i != len1 && mismatchFound) {
		return false;
	}
	
	return true;
}


int main()
{
	std::vector<std::pair<std::string, std::string> > words = { {"pale", "ple"}, {"pales", "pale"}, {"pale", "bale"}, {"pale", "bae"}};
	
	std::cout << "One edit away." << std::endl;
	for(auto word : words) {
		std::cout << word.first << " & " << word.second << " are one edit away : " << std::boolalpha << oneEditAway(word.first, word.second) << std::endl;
	}
	
	return 0;
}
