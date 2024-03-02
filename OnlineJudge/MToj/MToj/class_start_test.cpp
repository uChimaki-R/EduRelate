#include<iostream>
using namespace std;

//unordered_map<string, pair<int, int>>map;
//
//bool my_sort(pair<string, pair<int, int>>& p1, pair<string, pair<int, int>>& p2) {
//	if (p1.second.first != p2.second.first)return p1.second.second < p2.second.second;
//	return p1.second.first > p2.second.first;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string name;
//		int dif;
//		cin >> name >> dif;
//		map[name].first = i;
//		map[name].second += dif;
//	}
//	vector < pair<string, pair<int, int>>>vec(map.begin(), map.end());
//	sort(vec.begin(), vec.end(), my_sort);
//	cout << vec[0].first << endl << vec[0].second.second + 1000;
//	return 0;
//}

//int words[26];

//int main() {
//	string ducks;
//	cin >> ducks;
//	for (int i = 0; i < ducks.length(); i++) {
//		words[ducks[i] - 'A']++;
//	}
//	for (int i = 25; i >= 0; i--) {
//		if (words[i]) {
//			cout << (char)(i + 'A');
//			break;
//		}
//	}
//}
//#include<vector>
//string s;
//vector<char>s1, s2;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < 10000; i++) {
//		if (i % 2 == 0) {
//			s1.push_back('A');
//			s2.push_back('B');
//		}
//		else {
//			s2.push_back('A');
//			s1.push_back('B');
//		}
//	}
//	while (n--) {
//		cin >> s;
//		int cnt1 = 0, cnt2 = 0;
//		for (int i = 0; i < s.length(); i++) {
//			cnt1 += abs(s[i] - s1[i]);
//			cnt2 += abs(s[i] - s2[i]);
//		}
//		cout << min(cnt1, cnt2) << endl;
//	}
//}

//#include<unordered_set>
//#include<vector>
//unordered_set<int>s;
//vector<int>vec;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		vec.push_back(num);
//	}
//	int l = 0, r = 0;
//	int ans = 0;
//	while (r < vec.size()) {
//		if (s.count(vec[r])) {
//			while (vec[l] != vec[r]) {
//				s.erase(vec[l]);
//				l++;
//			}
//			l++;
//		}
//		else {
//			s.insert(vec[r]);
//			ans = max(ans, (int)s.size());
//		}
//		r++;
//	}
//	cout << ans;
//}

const int N = 502;
int map[N][N];
int n, m;

bool check(int st) {
	if (map[st][n])return true;
	for (int i = 1; i <= n; i++) {
		if (map[st][i] && check(i))return true;
	}
	return false;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	if (check(1))cout << "Yes";
	else cout << "No";
}