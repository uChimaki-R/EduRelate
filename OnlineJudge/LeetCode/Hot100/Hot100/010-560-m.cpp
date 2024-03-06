#include<vector>
#include<unordered_map>
using namespace std;

// nums�����Ϊk�����������еĸ���
// nums�е����ֿ����Ǹ���
// ��¼ǰ׺�ͳ��ֵ����ֺͳ��ָ���
// ��Ŀת��Ϊ����ÿ��i pre[i]-pre[j]=k��j�ĸ��������������ֺ�Ϊpre[j]�������и���
// ��j<i�����Լ��㵽��ǰi��ʱ��SumCountsͼ���Ѿ���¼�˺�Ϊpre[j]�������и���

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        // ��Ϊ0������Ĭ�Ͼ���һ����ȫ��ѡ��
        SumCounts[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            // sum���ǵ�ǰ��pre[i]
            sum += nums[i];
            if (SumCounts.count(sum - k))ans += SumCounts[sum - k];
            SumCounts[sum]++;
        }
        return ans;
    }
private:
    unordered_map<int, int>SumCounts;
    int ans = 0;
};