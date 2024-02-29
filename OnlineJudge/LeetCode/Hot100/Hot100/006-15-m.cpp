#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 最小的已经是正数了，后面的数不可能和为0，剪枝
            if (nums[i] > 0)return ans;
            // 去除重复结果
            if (i > 0 && nums[i] == nums[i - 1])continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] == -nums[r]) {
                    ans.push_back({ nums[i], nums[l], nums[r] });
                    // 去除重复结果
                    while (l < r && nums[l] == nums[l + 1])l++;
                    while (l < r && nums[r] == nums[r - 1])r--;
                    l++, r--;
                }
                else if (nums[i] + nums[l] < -nums[r])l++;
                else r--;
            }
        }
        return ans;
    }
private:
    vector<vector<int>>ans;
};
