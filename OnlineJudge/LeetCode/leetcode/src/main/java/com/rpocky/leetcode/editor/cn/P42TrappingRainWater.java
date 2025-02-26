//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 5544 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：接雨水
public class P42TrappingRainWater {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P42TrappingRainWater().new Solution();
        System.out.println(solution.trap(new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int trap(int[] height) {
            // 找出每个下标左右最高的高度
            int[] leftHighest = new int[height.length];
            int[] rightHighest = new int[height.length];
            leftHighest[0] = height[0];
            rightHighest[height.length - 1] = height[height.length - 1];
            for (int i = 1; i < height.length; i++) {
                leftHighest[i] = Math.max(leftHighest[i - 1], height[i]);
                rightHighest[height.length - i - 1] = Math.max(rightHighest[height.length - i], height[height.length - i - 1]);
            }
            int ans = 0;
            for (int i = 1; i < height.length - 1; i++) {
                // 取左右最高的高度中较小的那个（至少是自己），减去自己的高度即自己上方水的高度
                ans += Math.min(leftHighest[i], rightHighest[i]) - height[i];
            }
            return ans;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
