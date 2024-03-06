#include<vector>
#include<queue>
using namespace std;

// 使用大顶堆存储窗口内容，O(1)得出最大值
// 给每个数字加上下标标记(使用pair)，如果堆顶元素下标不在窗口范围之内则弹出，直到出现一个在窗口内的数即所需最大值

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)NumAndIndex.emplace(make_pair(nums[i], i));
        ans.emplace_back(NumAndIndex.top().first);
        for (int i = k; i < nums.size(); i++) {
            // 窗口移动添加新元素
            NumAndIndex.emplace(make_pair(nums[i], i));
            // 弹出非窗口内的最大元素
            while (NumAndIndex.top().second < i - k + 1)NumAndIndex.pop();
            // 更新结果ans
            ans.emplace_back(NumAndIndex.top().first);
        }
        return ans;
    }
private:
    priority_queue<pair<int, int>>NumAndIndex;
    vector<int>ans;
};