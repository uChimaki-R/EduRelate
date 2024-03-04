#include<iostream>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")return 0;  // 判掉特例
        int left = 0, right = 1;
        words.insert(s[0]);
        ans = 1;
        while (left < right && right < s.length()) {
            if (words.count(s[right])) {
                // 扫到了相同的字符，让左指针指到重复的字符的位置，同时更新words集合，删去离开窗口的字符
                while (s[left] != s[right]) {
                    words.erase(s[left]);
                    left++;
                }
                // 左右指针都从相同字符位置右移
                left++;
                right++;
            }
            else {
                // 不是相同字符，更新words集合，更新ans，右窗口继续扩大
                words.insert(s[right]);
                ans = max(ans, (int)words.size());
                right++;
            }
        }
        return ans;
    }
private:
    unordered_set<char>words;  // 当前字串字符集合
    int ans;
};
