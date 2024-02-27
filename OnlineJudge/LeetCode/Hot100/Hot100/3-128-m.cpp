#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 去重
        for (auto num : nums)nums_set.insert(num);
        for (auto num : nums_set) {
            // 如果有比num小1的数，则从num开始的序列一定不是最长的，所以要保证num是序列的第一个数
            if (nums_set.count(num - 1))continue;
            else {
                int cnt = 1, temp = num;
                // 循环遍历找序列是否还有下一个数
                while (nums_set.count(temp + 1)) {
                    cnt++;
                    temp++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
private:
    unordered_set<int>nums_set;
    int ans = 0;
};
