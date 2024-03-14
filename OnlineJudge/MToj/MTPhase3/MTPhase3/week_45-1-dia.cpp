#include<iostream>
using namespace std;

string merge(string s1, string s2) {
	int len1 = s1.length();
	int minl = min(len1, int(s2.length()));
	for (int i = minl; i >= 1; i--) {
		string t1 = s1.substr(len1 - i);
		string t2 = s2.substr(0, i);
		if (t1 == t2) {
			return s1 + s2.substr(i);
		}
	}
	return s1 + s2;
}

int mergeWithOrder(string s1, string s2, string s3) {
	return merge(merge(s1, s2), s3).length();
}

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1.find(s2) != s1.npos)s2 = s1;
	if (s1.find(s3) != s1.npos)s3 = s1;
	if (s2.find(s1) != s2.npos)s1 = s2;
	if (s2.find(s3) != s2.npos)s3 = s2;
	if (s3.find(s1) != s3.npos)s1 = s3;
	if (s3.find(s2) != s3.npos)s2 = s3;
	/*string t1 = "iiiiiqwe", t2 = "ertjjjjj";
	cout << merge(t1, t2);*/
	int ans = 0x3f3f3f3f;
	ans = min(ans, mergeWithOrder(s1, s2, s3));
	ans = min(ans, mergeWithOrder(s1, s3, s2));
	ans = min(ans, mergeWithOrder(s2, s1, s3));
	ans = min(ans, mergeWithOrder(s2, s3, s1));
	ans = min(ans, mergeWithOrder(s3, s2, s1));
	ans = min(ans, mergeWithOrder(s3, s1, s2));
	cout << ans;
	return 0;
}