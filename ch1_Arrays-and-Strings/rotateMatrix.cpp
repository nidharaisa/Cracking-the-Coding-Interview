//
//  rotateMatrix.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 7/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>

void rotate(int **matrix, int n) {
	
	if(n == 0) return ;
	
	for (int layer=0; layer<n/2; layer++)
	{
		int first = layer;
		int last = n - 1 - layer;
		
		for (int i=first; i<last; i++) {
			int offset = i - first;
			int top = matrix[first][i];

			// left -> top
			matrix[first][i] = matrix[last-offset][first];
			// bottom -> left
			matrix[last-offset][first] = matrix[last][last - offset];
			// right -> bottom
			matrix[last][last-offset] = matrix[i][last];
			// top -> right
			matrix[i][last] = top;
		}
	}
	
	return ;
}

int main()
{
	int n = 4;
	int **matrix = new int* [n];
	
	for(int i=0; i<n; i++)
		matrix[i] = new int[n];
	
	for(int i=0; i<n; i++)
		for(int j =0; j<n; j++)
			matrix[i][j] = std::rand()%17;
	
	std::cout << "Given Matrix :" << std::endl;
	for(int i=0; i<n; i++) {
		for(int j =0; j<n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	rotate(matrix, n);
	
	std::cout << "\n\nRotate Matrix :" << std::endl;
	for(int i=0; i<n; i++) {
		for(int j =0; j<n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
