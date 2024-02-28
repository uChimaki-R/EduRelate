#include<iostream>
#include<vector>
//#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /*map<int, int>mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end())return { mp[nums[i]], i };
            else mp[target - nums[i]] = i;
        }
        return {};*/

        unordered_map<int, int>mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end())return { mp[nums[i]], i };
            else mp[target - nums[i]] = i;
        }
        return {};
    }
};
