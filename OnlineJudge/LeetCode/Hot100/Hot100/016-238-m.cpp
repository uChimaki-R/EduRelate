#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        // ×óÓÒ¶àÁ½¸öÉÚ±ø
        leftMul[0] = rightMul[size + 1] = 1;
        for (int i = 1; i < size + 1; i++) {
            leftMul[i] = nums[i - 1] * leftMul[i - 1];
            rightMul[size + 1 - i] = nums[size - i] * rightMul[size + 2 - i];
        }
        for (int i = 1; i < size + 1; i++)ans.emplace_back(leftMul[i - 1] * rightMul[i + 1]);
        return ans;
    }
private:
    int leftMul[100010];
    int rightMul[100010];
    vector<int>ans;
};
