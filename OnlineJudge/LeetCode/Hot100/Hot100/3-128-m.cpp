#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ȥ��
        for (auto num : nums)nums_set.insert(num);
        for (auto num : nums_set) {
            // ����б�numС1���������num��ʼ������һ��������ģ�����Ҫ��֤num�����еĵ�һ����
            if (nums_set.count(num - 1))continue;
            else {
                int cnt = 1, temp = num;
                // ѭ�������������Ƿ�����һ����
                while (nums_set.count(temp + 1)) {
                    cnt++;
                    temp++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
private:
    unordered_set<int>nums_set;
    int ans = 0;
};
