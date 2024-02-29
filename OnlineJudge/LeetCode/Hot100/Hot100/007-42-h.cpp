#include<vector>
using namespace std;

// 按列求当前列上方可以存多少雨水
// 取决于该列左右最高的那两个柱子当中较矮的那个
// 二者的高度差就是可以接的雨水数量（要是正数）

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        // 使用dp求每个列左右最高的那个柱子的高度
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
