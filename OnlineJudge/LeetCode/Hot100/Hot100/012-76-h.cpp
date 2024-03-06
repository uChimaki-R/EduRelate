#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool check() {
        for (auto i : target) {
            // 当前的字符串中对应字符数量需要大于等于目标字符串中对应字符的数量
            // 以target来迭代才能保证满足
            if (now[i.first] < i.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (auto i : t)target[i]++; // 目标字符串各字符个数
        for (int i = 0; i < s.length(); i++) {
            // 只记录目标字符串中有的字符的位置
            if (target.count(s[i]))vec.push_back(make_pair(s[i], i));
        }
        int left = 0, right = 0;
        while (right < vec.size()) {
            now[vec[right].first]++; // 添加一个该字符
            if (check()) {
                while (target[vec[left].first] < now[vec[left].first]) {
                    now[vec[left].first]--; // 左边可以删去就一直收缩
                    left++;
                }
                int nowLen = vec[right].second - vec[left].second + 1;
                if (nowLen < ansLen) {
                    ansLen = nowLen;
                    ansLeft = vec[left].second; // second存的下标才是字符真实的下标
                }
            }
            // 不成立右边就拓展
            right++;
        }
        return ansLen == 0x3f3f3f3f ? string() : s.substr(ansLeft, ansLen);
    }
private:
    unordered_map<char, int>target, now;
    vector<pair<char, int>>vec;
    int ansLen = 0x3f3f3f3f, ansLeft = 0;
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sl;
    cout << sl.minWindow(s, t);
}