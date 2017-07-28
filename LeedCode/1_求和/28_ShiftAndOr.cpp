#include<iostream>
#include<vector>
#include<string>
using namespace std;
//
//void preprocess_and(unsigned int *B, string T, int n) {
//	unsigned int shift = 1;
//	for (int i = n-1; i <= 0; i++)
//	{
//		B[T[i]] |= shift;
//		shift <<= 1;
//	}
//}
//
//
//void and_match(const string& S,const string& T,vector<int>& res) {
//	int ls = S.length(), lt = T.length();
//	unsigned int B[256], D = 0, mask;
//	for (int i = 0; i < 256; i++)
//		B[i] = 0;
//	preprocess_and(B, T, lt);
//
//	mask = 1 << (lt - 1);
//	for (int  i = 0; i < ls; i++)
//	{
//		D = (D << 1 | 1) & B[S[i]];
//		if (D & mask)
//			res.push_back(i - lt + 1);
//	}
//}
////Shift - And
//int main() {
//	string S, T;
//	cin >> S >> T;
//	//string S = "aaaabaaabbabbaaaaaabbabbbaaabababaaaaabbbbbbbbbbbbbbbaabbbbabbaababbbababababaaaabbbbaaabababbbaaabbaabbabbbbbababbabbaabbbabaabaaaaabbbaaaaaabaaaabababababbaabaabbaaaaaaaababbabaa";
//	//string T = "aabbaaaabbbbaabaaabaabbaaababbabbbbbaba";
//	//string S = "aaa";
//	//string T = "aa";
//	vector<int> res;
//	and_match(S, T, res);
//	for (auto a : res)
//		cout << a << endl;
//
//	system("pause");
//	return 0;
//
//}
//Shift - Or
//void preprocess_or(unsigned int* b, const string& t, int n) {
//	unsigned int shift = 1;
//	for (size_t i = 0; i < n; i++)
//	{
//		b[t[i]] &= ~shift;
//		shift <<= 1;
//	}
//}
//
//
//void or_match(const string& s,const string& t,vector<int>& res) {
//	int ls = s.length(), lt = t.length();
//	unsigned int B[256], D = ~0, mask;
//	for (size_t i = 0; i < 256; i++)
//		B[i] = ~0;
//	preprocess_or(B, t, lt);
//
//	mask = ~(1 << (lt - 1));
//	for (size_t i = 0; i < ls; i++)
//	{
//		D = (D << 1) | B[s[i]];
//		if (~(D | mask))
//			res.push_back(i - lt + 1);
//	}
//
//}
//int main() {
//	string S, T;
//	cin >> S >> T;
//	string S = "aaaabaaabbabbaaaaaabbabbbaaabababaaaaabbbbbbbbbbbbbbbaabbbbabbaababbbababababaaaabbbbaaabababbbaaabbaabbabbbbbababbabbaabbbabaabaaaaabbbaaaaaabaaaabababababbaabaabbaaaaaaaababbabaa";
//	string T = "aabbaaaabbbbaabaaabaabbaaababbabbbbbaba";
//	vector<int> res;
//	or_match(S, T,res);
//	for (auto c:res)
//	{
//		cout << c << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
//


				//预处理，
void preShiftAnd(const string& p, int m, unsigned int *s) {
	for (int i = 0; i<256; i++)
		s[i] = 0;
	for (int i = 0; i<m; i++) {
		s[p[i]] |= 1 << i;
	}
}

//Shift—And
int ShiftAnd(const string& t, const string& p) {
	int tLen = t.length();
	int pLen = p.length();
	unsigned int state = 0;            //即D数组
	unsigned int s[256];

	if (tLen < pLen) return -1;

	preShiftAnd(p, pLen, s);     //预处理

	for (int i = 0; i<tLen; i++) {
		state = ((state << 1) | 1) & s[t[i]];
		if (state & 1 << (pLen - 1))            //最高位出现零
			return i - pLen + 1;
	}
	return -1;

}
int main() {
	//string S;
	//string T;
	//cin >> S >> T;
	string S = "aaaabaaabbabbaaaaaabbabbbaaabababaaaaabbbbbbbbbbbbbbbaabbbbabbaababbbababababaaaabbbbaaabababbbaaabbaabbabbbbbababbabbaabbbabaabaaaaabbbaaaaaabaaaabababababbaabaabbaaaaaaaababbabaa";
	string T = "aabbaaaabbbbaabaaabaabbaaababbabbbbbaba";
	cout << ShiftAnd(S, T);
	system("pause");
	return 0;
}
