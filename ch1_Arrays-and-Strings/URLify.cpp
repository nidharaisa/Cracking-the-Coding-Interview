//
//  URLify.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 3/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

std::string URLify(std::string &str, int len)
{
	int counter = 0;
	int lastCharPos = -1;
	
	for(int i = len-1; i>=0; i--) {
		if(-1 == lastCharPos && str[i] != ' ') {
			lastCharPos = i;
		}
		else if(-1 != lastCharPos && str[i] == ' ')
			counter++;
	}
	
	int newLen = lastCharPos + counter*2 + 1;
	str.resize(newLen);
	
	for(int i = newLen-1, j = lastCharPos; i>=0; i--, j--) {
		if(str[j] == ' ' && j>0) {
			str.replace(i-2, 3, "%20");
			i -= 2;
		}
		else {
			str[i] = str[j];
		}
	}
	
	return str;
}

int main()
{
	std::vector<std::string> URLs = {"Dr John Smith", "Nidha Raisa", "La la la  "};
	
	for (auto urls : URLs) {
		std::cout << urls << " : " << URLify(urls, (int)urls.size()) << std::endl;
	}
	
	return 0;
}

