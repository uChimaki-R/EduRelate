#include<vector>
using namespace std;

// ������ǰ���Ϸ����Դ������ˮ
// ȡ���ڸ���������ߵ����������ӵ��нϰ����Ǹ�
// ���ߵĸ߶Ȳ���ǿ��Խӵ���ˮ������Ҫ��������

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        // ʹ��dp��ÿ����������ߵ��Ǹ����ӵĸ߶�
        for (int i = 1; i < size; i++) {
            LeftMaxHeight[i] = max(LeftMaxHeight[i - 1], height[i - 1]);
            RightMaxHeight[size - 1 - i] = max(RightMaxHeight[size - i], height[size - i]);
        }
        for (int i = 0; i < size; i++) {
            int MinOne = min(LeftMaxHeight[i], RightMaxHeight[i]);
            int Dif = MinOne - height[i];
            if (Dif > 0)ans += Dif;
        }
        return ans;
    }
private:
    int LeftMaxHeight[20010] = {};
    int RightMaxHeight[20010] = {};
    int ans = 0;
};
