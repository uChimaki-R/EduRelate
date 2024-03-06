#include<vector>
#include<unordered_map>
using namespace std;

// nums中相加为k的连续子序列的个数
// nums中的数字可以是负数
// 记录前缀和出现的数字和出现个数
// 题目转换为对于每个i pre[i]-pre[j]=k的j的个数，即连续部分和为pre[j]的子序列个数
// 而j<i，所以计算到当前i的时候，SumCounts图中已经记录了和为pre[j]的子序列个数

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        // 和为0的序列默认就有一个（全不选）
        SumCounts[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            // sum就是当前的pre[i]
            sum += nums[i];
            if (SumCounts.count(sum - k))ans += SumCounts[sum - k];
            SumCounts[sum]++;
        }
        return ans;
    }
private:
    unordered_map<int, int>SumCounts;
    int ans = 0;
};