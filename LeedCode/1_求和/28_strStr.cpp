#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Solution {
public:
	int shift_and(string s, int len_s, string p, int len_p)
	{
		int B[128];
		memset(B, 0, sizeof(B));

		int i;
		for (i = 0; i<len_p; i++)
			B[p[i]] |= 1 << i;

		int D = 0;
		for (i = 0; i<len_s; i++)
		{
			D = ((D << 1) | 1) & B[s[i]];  //D<<1��1λ��������ǿ�����ƥ����ʱ�ӵ�ǰ�ַ���ʼ��ʹ��λ����ʵ���˲���
			if (D & (1 << (len_p - 1)))
				return i - len_p + 1;
		}
		return -1;
	}



	int strStr(string haystack, string needle) {
		if(haystack.length() == 0 && needle.length() == 0) return 0;
		if (haystack.length() == 0 || needle.length() == 0) return -1;
		return shift_and(haystack, haystack.length(), needle, needle.length());
	
	}
};
int main()
{
	string s = "aaaabaaabbabbaaaaaabbabbbaaabababaaaaabbbbbbbbbbbbbbbaabbbbabbaababbbababababaaaabbbbaaabababbbaaabbaabbabbbbbababbabbaabbbabaabaaaaabbbaaaaaabaaaabababababbaabaabbaaaaaaaababbabaa";
	string t = "aabbaaaabbbbaabaaabaabbaaababbabbbbbaba";
	Solution sol;
	cout<<sol.strStr(s, t)<<endl;
	system("pause");
	return 0;
}