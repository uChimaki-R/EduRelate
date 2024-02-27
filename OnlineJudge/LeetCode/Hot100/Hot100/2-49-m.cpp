#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hash[temp].emplace_back(str);
        }
        for (auto pr : hash) {
            ans.emplace_back(pr.second);
        }
        return ans;
    }
private:
    unordered_map<string, vector<string>>hash;
    vector<vector<string>>ans;
};
