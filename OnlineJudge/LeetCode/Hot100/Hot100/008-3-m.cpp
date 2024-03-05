#include<iostream>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")return 0;  // �е�����
        int left = 0, right = 1;
        words.insert(s[0]);
        ans = 1;
        while (left < right && right < s.length()) {
            if (words.count(s[right])) {
                // ɨ������ͬ���ַ�������ָ��ָ���ظ����ַ���λ�ã�ͬʱ����words���ϣ�ɾȥ�뿪���ڵ��ַ�
                while (s[left] != s[right]) {
                    words.erase(s[left]);
                    left++;
                }
                // ����ָ�붼����ͬ�ַ�λ������
                left++;
                right++;
            }
            else {
                // ������ͬ�ַ�������words���ϣ�����ans���Ҵ��ڼ�������
                words.insert(s[right]);
                ans = max(ans, (int)words.size());
                right++;
            }
        }
        return ans;
    }
private:
    unordered_set<char>words;  // ��ǰ�ִ��ַ�����
    int ans;
};
