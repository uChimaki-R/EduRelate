#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] < 0)dp[i] = nums[i]; // 以前一个结尾的子序列最大和还小于0，直接舍弃
            else dp[i] = dp[i - 1] + nums[i]; // 大于0则可以考虑加入新的数（可以当作从下标0开始，相当于一开始就多了一点正数和，那这个位置的最大和序列肯定是 以前一个位置结尾的最大子序列+该位置组成的子序列）
            if (dp[i] > ans)ans = dp[i]; // 每次更新结果
        }
        return ans;
    }
private:
    // 以i为结尾的子序列中最大的和
    int dp[100010];
};