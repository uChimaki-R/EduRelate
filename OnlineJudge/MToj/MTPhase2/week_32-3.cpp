#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

const int N = 1007;
int fp, flag;
string input, target;
vector<string>path;

struct Folder {
	string name;
	int id, level, father;
	vector<int>sons;
}folders[N];

void dfs(int id) {
	if (folders[id].name == target) {
		for (auto i : path)cout << i;
		cout << endl;
		flag = 1;
	}
	for (auto i : folders[id].sons) {
		path.push_back("/");
		path.push_back(folders[i].name);
		dfs(i);
		path.pop_back();
		path.pop_back();
	}
}

int main() {
	stack<Folder>st;
	folders[fp++].level = 0;
	st.push(folders[0]);
	while (true) {
		getline(cin, input);
		if (input == "#")break;
		for (int i = 0;; i++) {
			if (input[i] != ' ') {
				folders[fp].name = input.substr(i);
				folders[fp].level = i + 1;
				folders[fp].id = fp;
				while (st.top().level >= folders[fp].level)st.pop();
				folders[fp].father = st.top().id;
				folders[st.top().id].sons.push_back(folders[fp].id);
				st.push(folders[fp]);
				fp++;
				break;
			}
		}
	}
	cin >> target;
	dfs(0);
	if (!flag)cout << "NULL";
	return 0;
}