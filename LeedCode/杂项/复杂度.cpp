/*************************************************************************
> File Name: 5.ÒÉËÆ²¡¶¾.cpp
> Author:
> Mail:
> Created Time: Sat 25 Nov 2017 11:16:12 AM DST
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


struct Matrix {
	int size;
	int **data;


	Matrix(int n) : size(n) {
		printf("Yes\n");
		this->data = (int **)malloc(n * sizeof(int*));
		for (int i = 0; i < n; ++n) {
			this->data[i] = (int *)calloc(n , sizeof(int));
		}
		printf("Yes\n");
	}
	~Matrix() {
		clear_data();
	}
	void mul() {
		Matrix temp(size);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				for (int k = 0; k < size; ++k) {
					temp.data[i][j] += data[i][k] * data[k][j];
				}
			}
		}
		clear_data();
		data = temp.data;
		temp.data = NULL;
	}
	void quick_mul(int a) {
		while (a) {
			if (a & 1) mul();
			mul();
			a >>= 1;
		}
	}
	void out() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				printf("%d ", data[i][j]);
			}
			printf("\n");
		}
	}
	void clear_data() {
		for (int i = 0; i < size; ++i) {
			free(data[i]);
		}
		free(data);
	}
};








int main() {


	Matrix a(3);
	a.out();
	/*
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &a.data[i][j]);
		}
	}
	a.out();
	int n;
	scanf("%d", &n);
	a.quick_mul(n);
	a.out();
	*/

	return 0;
}





