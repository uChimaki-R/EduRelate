#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool check() {
        for (auto i : target) {
            // ��ǰ���ַ����ж�Ӧ�ַ�������Ҫ���ڵ���Ŀ���ַ����ж�Ӧ�ַ�������
            // ��target���������ܱ�֤����
            if (now[i.first] < i.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (auto i : t)target[i]++; // Ŀ���ַ������ַ�����
        for (int i = 0; i < s.length(); i++) {
            // ֻ��¼Ŀ���ַ������е��ַ���λ��
            if (target.count(s[i]))vec.push_back(make_pair(s[i], i));
        }
        int left = 0, right = 0;
        while (right < vec.size()) {
            now[vec[right].first]++; // ���һ�����ַ�
            if (check()) {
                while (target[vec[left].first] < now[vec[left].first]) {
                    now[vec[left].first]--; // ��߿���ɾȥ��һֱ����
                    left++;
                }
                int nowLen = vec[right].second - vec[left].second + 1;
                if (nowLen < ansLen) {
                    ansLen = nowLen;
                    ansLeft = vec[left].second; // second����±�����ַ���ʵ���±�
                }
            }
            // �������ұ߾���չ
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