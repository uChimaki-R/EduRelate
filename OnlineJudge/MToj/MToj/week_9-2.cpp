#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

typedef long long LL;

const LL mod = 1000007;

map<LL, string>mp;

int main()
{
	LL n;
	string s;
	cin >> n;
	cin.get();
	while (n--)
	{
		getline(cin, s);
		stringstream ss;
		ss << s;
		LL sum = 0, po = 1, val;
		while (ss >> val)
		{
			sum = (sum + val) % mod;
			po = po * val % mod;
		}
		if (mp.count((sum + po) % mod))
		{
			string vals = mp[(sum + po) % mod];
			if (vals == s)
			{
				cout << "found.";
				return 0;
			}
			for (int j = 0; j <= 8; j += 2)
			{
				string same = vals.substr(j + 2, 9 - j) + " " + vals.substr(0, j + 1);
				if (same == s)
				{
					cout << "found.";
					return 0;
				}
			}
			reverse(s.begin(), s.end());
			if (vals == s)
			{
				cout << "found.";
				return 0;
			}
			for (int j = 0; j <= 8; j += 2)
			{
				string same = vals.substr(j + 2, 9 - j) + " " + vals.substr(0, j + 1);
				if (same == s)
				{
					cout << "found.";
					return 0;
				}
			}
		}
		else
		{
			mp[(sum + po) % mod] = s;
		}
	}
	cout << "No";
	return 0;
}


//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//typedef long long LL;
//
//vector<string>v;
//map<string, LL>mp;
//
//int main()
//{
//	LL n;
//	string s;
//	cin >> n;
//	cin.get();
//	while (n--)
//	{
//		getline(cin, s);
//		v.push_back(s);
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		vector<string>vv;
//		s = v[i];
//		if (mp[s])
//		{
//			cout << "found.";
//			return 0;
//		}
//		else
//		{
//			vv.push_back(s);
//		}
//		for (int j = 0; j <= 8; j += 2)
//		{
//			string same = s.substr(j + 2, 9 - j) + " " + s.substr(0, j + 1);
//			if (mp[same])
//			{
//				cout << "found.";
//				return 0;
//			}
//			else
//			{
//				vv.push_back(same);
//			}
//		}
//		reverse(s.begin(), s.end());
//		if (mp[s])
//		{
//			cout << "found.";
//			return 0;
//		}
//		else
//		{
//			vv.push_back(s);
//		}
//		for (int j = 0; j <= 8; j += 2)
//		{
//			string same = s.substr(j + 2, 9 - j) + " " + s.substr(0, j + 1);
//			if (mp[same])
//			{
//				cout << "found.";
//				return 0;
//			}
//			else
//			{
//				vv.push_back(same);
//			}
//		}
//		for (int j = 0; j < vv.size(); j++)
//		{
//			mp[vv[j]]++;
//		}
//	}
//	cout << "No";
//	return 0;
//}