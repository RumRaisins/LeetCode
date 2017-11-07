#pragma once
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#define DEBUG

#ifdef DEBUG



typedef struct {
	int fail_num;
	int total_num;
	int assert_flag;
} TestInfo, *pTestInfo;


#define RUN_STR "\033[33mRUN\033[0m"
#define RUN_FAIL_STR "\033[41mRUN\033[0m"
#define PASS_STR "\033[32mPASS\033[0m"
#define FAIL_STR "\033[31mFAIL\033[0m"
#define TI_PASS(a) ((a)->total_num - (a)->fail_num)
#define TI_FAIL(a) ((a)->fail_num)
#define TI_TOTAL(a) ((a)->total_num)


void init_test_info_haizei(pTestInfo ti) {
	ti->fail_num = 0;
	ti->total_num = 0;
	ti->assert_flag = 0;
}
int TEST_RUN(void(*func)(pTestInfo), const char *module_name, const char *testcase) {
	TestInfo ti;
	init_test_info_haizei(&ti);
	func(&ti);
	if (TI_FAIL(&ti)) {
		//printf("[ %s ]", RUN_FAIL_STR);
	}
	else {
		//printf("[ %s ]", RUN_STR);
	}
	printf(" %s.%s ", module_name, testcase);
	//printf("(Total: \033[1;4m%d\033[0m) \033[1;4m%d\033[0m %s , \033[1;4m%d\033[0m %s\n",
	//	TI_TOTAL(&ti), TI_PASS(&ti), PASS_STR, TI_FAIL(&ti), FAIL_STR);
	printf("(Total: %dRUN ,%dPASS , %dFAIL\n",
		TI_TOTAL(&ti), TI_PASS(&ti), TI_FAIL(&ti), FAIL_STR);
	if (ti.assert_flag) {
		abort();
	}
	return 0;
}


#define EXPECT_RUN(a, b, c) { \
    __ti__->total_num++; \
    if (!((a) c (b))) { \
        __ti__->fail_num++; \
    } \
}

#define ASSERT_RUN(a, b, c) { \
    __ti__->total_num++; \
    if (!((a) c (b))) { \
        __ti__->fail_num++; \
        __ti__->assert_flag = 1; \
        return ;\
    } \
}



#define TEST(module_name ,testcase) \
    void module_name##_##testcase (pTestInfo); \
    const int _p##module_name##testcase = \
        TEST_RUN(module_name##_##testcase, #module_name, #testcase);\
    void module_name##_##testcase (pTestInfo __ti__)



#endif