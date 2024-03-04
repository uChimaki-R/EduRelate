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
        // ��¼ ������s�ĸ���ĸ���� p�ַ����и���ĸ����
        for (int i = 0; i < plen; i++) {
            sWordCounts[s[i] - 'a']++;
            pWordCounts[p[i] - 'a']++;
        }
        if (sWordCounts == pWordCounts)ans.emplace_back(0);
        for (int i = 0; i < slen - plen; i++) {
            // �������� ȥ����һ����ĸ ������һ����ĸ
            sWordCounts[s[i] - 'a']--;
            sWordCounts[s[i + plen] - 'a']++;
            // �ٴ��ж��Ƿ���ͬ�����ַ���
            if (sWordCounts == pWordCounts)ans.emplace_back(i + 1);
        }
        return ans;
    }
private:
    vector<int>ans;
    vector<int>sWordCounts;
    vector<int>pWordCounts;
};