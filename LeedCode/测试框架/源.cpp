#include "TEST.h"
#include <iostream>



int main() {

	int a = 10, b = 10;
	

	system("pause");
	return 0;
}

TEST(NULL, testa, testb) {
	int a = 10, b = 10;
	for (int i = 0; i < 10; ++i) {
		ASSERT_RUN(a, b,==);
	}
}