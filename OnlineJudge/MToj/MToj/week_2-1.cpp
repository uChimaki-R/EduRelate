#include<iostream>
#include<string>
using namespace std;

bool is_all_Aa(string& s)
{
	//s.length() > 16放外面，因为resource没有长度要求
	if (s.length() == 0)
	{
		return false;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (!isalnum(s[i]) && s[i] != '_')
		{
			return false;
		}
	}
	return true;
}

bool is_legal_hostname(string& s)
{
	if (s[0] == '.' || s[s.length() - 1] == '.' || s.find("..") != s.npos || s.length() > 32 || s.length() == 0)
	{
		return false;
	}
	int pos = s.find('.');
	int start = 0;
	while (pos != s.npos)
	{
		string sub = s.substr(start, pos - start);
		if (!is_all_Aa(sub) || sub.length() > 16)
		{
			return false;
		}
		start = pos + 1;
		pos = s.find('.', pos + 1);
	}
	string sub = s.substr(start, s.length() - start);
	if (!is_all_Aa(sub) || sub.length() > 16)
	{
		return false;
	}
	return true;
}

bool is_legal(string& s)
{
	int pos = s.find('@');
	int rpos = s.rfind('@');
	if (pos != rpos)
	{
		//两个@，不合法
		return false;
	}
	string username = s.substr(0, pos);
	if (!is_all_Aa(username) || username.length() > 16)
	{
		return false;
	}
	if (s.find('/') != s.npos)
	{
		//有resource段
		string hostname = s.substr(s.find('@') + 1, s.find('/') - s.find('@') - 1);
		if (!is_legal_hostname(hostname))
		{
			return false;
		}
		string resource = s.substr(s.find('/') + 1, s.length() - s.find('/') - 1);
		if (!is_all_Aa(resource))
		{
			return false;
		}
	}
	else
	{
		string hostname = s.substr(s.find('@') + 1, s.length() - s.find('@'));
		if (!is_legal_hostname(hostname))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string address;
	getline(cin, address);
	if (is_legal(address))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
