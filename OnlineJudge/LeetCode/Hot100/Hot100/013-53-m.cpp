#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] < 0)dp[i] = nums[i]; // ��ǰһ����β�����������ͻ�С��0��ֱ������
            else dp[i] = dp[i - 1] + nums[i]; // ����0����Կ��Ǽ����µ��������Ե������±�0��ʼ���൱��һ��ʼ�Ͷ���һ�������ͣ������λ�õ��������п϶��� ��ǰһ��λ�ý�β�����������+��λ����ɵ������У�
            if (dp[i] > ans)ans = dp[i]; // ÿ�θ��½��
        }
        return ans;
    }
private:
    // ��iΪ��β�������������ĺ�
    int dp[100010];
};