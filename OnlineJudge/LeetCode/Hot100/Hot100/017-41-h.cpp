#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto i : nums) {
            if (i > 0)st.insert(i);;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!st.count(i))return i;
        }
        return nums.size()+1;
    }
private:
    unordered_set<int>st;
};