//
//  zeroMatrix.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 8/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>

void nullifyRow(int **matrix, int i, const int c) {
	for (int j=0; j<c; j++) {
		matrix[i][j] = 0;
	}
}

void nullifyCol(int **matrix, int j, const int r) {
	for (int i=0; i<r; i++) {
		matrix[i][j] = 0;
	}
}

void setZeroes(int **matrix, const int r, const int c) {
	
	if(c == 0 || r == 0) return ;
	
	bool rowHasZero = false;
	bool colHasZero = false;
	
	// check if 1st row contains any zero
	for (int i=0; i<c; i++) {
		if(0 == matrix[0][i]) {
			rowHasZero = true;
			break;
		}
	}
	// check if 1st col contains any zero
	for (int i=0; i<r; i++) {
		if(0 == matrix[i][0]) {
			colHasZero = true;
			break;
		}
	}
	
	for (int i=1; i<r; i++) {
		for (int j=1; j<c; j++) {
			if (0 == matrix[i][j]) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	
	// set zeroes to a row based on 1st value
	for (int i=1; i<r; i++) {
		if (0 == matrix[i][0]) {
			nullifyRow(matrix, i, c);
		}
	}
	// set zeroes to a col based on 1st value
	for (int j=1; j<c; j++) {
		if (0 == matrix[0][j]) {
			nullifyCol(matrix, j, r);
		}
	}
	
	if (rowHasZero) {
		// set zeroes to 1st row
		nullifyRow(matrix, 0, c);
	}
	
	if (colHasZero) {
		// set zeroes to 1st col
		nullifyCol(matrix, 0, r);
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
			matrix[i][j] = std::rand()%5;
	
	std::cout << "Given Matrix :" << std::endl;
	for(int i=0; i<n; i++) {
		for(int j =0; j<n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	setZeroes(matrix, n, n);
	
	std::cout << "\n\nZero Matrix :" << std::endl;
	for(int i=0; i<n; i++) {
		for(int j =0; j<n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
