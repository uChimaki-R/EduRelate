#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int plen = p.length();
        int slen = s.length();
        if (plen > slen)return ans;
        sWordCounts.resize(26);
        pWordCounts.resize(26);
        // 记录 窗口内s的各字母数量 p字符串中各字母数量
        for (int i = 0; i < plen; i++) {
            sWordCounts[s[i] - 'a']++;
            pWordCounts[p[i] - 'a']++;
        }
        if (sWordCounts == pWordCounts)ans.emplace_back(0);
        for (int i = 0; i < slen - plen; i++) {
            // 滑动窗口 去掉第一个字母 加上下一个字母
            sWordCounts[s[i] - 'a']--;
            sWordCounts[s[i + plen] - 'a']++;
            // 再次判断是否是同构的字符串
            if (sWordCounts == pWordCounts)ans.emplace_back(i + 1);
        }
        return ans;
    }
private:
    vector<int>ans;
    vector<int>sWordCounts;
    vector<int>pWordCounts;
};