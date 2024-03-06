#include<vector>
#include<queue>
using namespace std;

// ʹ�ô󶥶Ѵ洢�������ݣ�O(1)�ó����ֵ
// ��ÿ�����ּ����±���(ʹ��pair)������Ѷ�Ԫ���±겻�ڴ��ڷ�Χ֮���򵯳���ֱ������һ���ڴ����ڵ������������ֵ

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)NumAndIndex.emplace(make_pair(nums[i], i));
        ans.emplace_back(NumAndIndex.top().first);
        for (int i = k; i < nums.size(); i++) {
            // �����ƶ������Ԫ��
            NumAndIndex.emplace(make_pair(nums[i], i));
            // �����Ǵ����ڵ����Ԫ��
            while (NumAndIndex.top().second < i - k + 1)NumAndIndex.pop();
            // ���½��ans
            ans.emplace_back(NumAndIndex.top().first);
        }
        return ans;
    }
private:
    priority_queue<pair<int, int>>NumAndIndex;
    vector<int>ans;
};