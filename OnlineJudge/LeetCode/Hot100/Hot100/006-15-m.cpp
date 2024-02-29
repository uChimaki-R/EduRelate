#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // ��С���Ѿ��������ˣ�������������ܺ�Ϊ0����֦
            if (nums[i] > 0)return ans;
            // ȥ���ظ����
            if (i > 0 && nums[i] == nums[i - 1])continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] == -nums[r]) {
                    ans.push_back({ nums[i], nums[l], nums[r] });
                    // ȥ���ظ����
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
