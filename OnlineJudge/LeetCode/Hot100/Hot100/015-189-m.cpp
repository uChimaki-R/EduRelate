#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        k = size - k;
        for (int i = k; i < size; i++)temp.push_back(nums[i]);
        for (int i = 0; i < k; i++)temp.push_back(nums[i]);
        nums.assign(temp.begin(), temp.end());
    }
private:
    vector<int>temp;
};