#include<iostream>
#include<vector>
using namespace std;

string s1[] = {
	"zero", "one", "two", "three", "four", "five", "six",
	"seven", "eight", "nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen"
};

string s2[] = {
	"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
	"eighty", "ninety"
};

vector<string>ans;

int main() {
	int num;
	cin >> num;
	if (num == 0) {
		cout << "zero";
		return 0;
	}
	int q = num / 1000;
	int b = num / 100 % 10;
	int s = num / 10 % 10;
	int g = num % 10;
	if (q)ans.push_back(s1[q]), ans.push_back("thousand");
	if (q && !b && (s || g))ans.push_back("and");
	if (b)ans.push_back(s1[b]), ans.push_back("hundred");
	if (b && !s && g)ans.push_back("and");
	if (s && s != 1)ans.push_back(s2[s]);
	if (s == 1)ans.push_back(s1[s * 10 + g]);
	if (s != 1 && g)ans.push_back(s1[g]);
	for (int i = 0; i < ans.size() - 1; i++)cout << ans[i] << " ";
	cout << ans[ans.size() - 1];
	return 0;
}