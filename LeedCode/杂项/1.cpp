#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using std::cout;
using std::cin;
using std::string;
using std::vector;

#define BASEA 'a'
#define BASE0 '0'

int main() {

	char temp;
	int *p = new int[256]();
	
	while(scanf("%c" , &temp) != EOF){
		++p[temp];
	}
	for (int i = 97; i <= 122; ++i) {
		if (p[i]) {
			for (int j = 0; j < p[i]; ++j) {
				printf("%c", i);
			}
		}
	}
	for (int i = 48; i <= 57; ++i) {
		if (p[i]) {
			for (int j = 0; j < p[i]; ++j) {
				printf("%c", i);
			}
		}
	}
	

	delete[]p;
	system("pause");
	return 0;
}