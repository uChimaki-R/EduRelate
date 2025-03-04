//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。 
//
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内。 
//
// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,2,3,4]
//输出: [24,12,8,6]
// 
//
// 示例 2: 
//
// 
//输入: nums = [-1,1,0,-3,3]
//输出: [0,0,9,0,0]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁵ 
// -30 <= nums[i] <= 30 
// 输入 保证 数组 answer[i] 在 32 位 整数范围内 
// 
//
// 
//
// 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。） 
//
// Related Topics 数组 前缀和 👍 1973 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Arrays;

//Java：除自身以外数组的乘积
public class P238ProductOfArrayExceptSelf {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P238ProductOfArrayExceptSelf().new Solution();
        int[] nums = {1, 2, 3, 4};
        for (int i : solution.productExceptSelf(nums)) {
            System.out.println(i + " ");
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private static final int size = 100007;
        private final int[] leftMul = new int[size];
        private final int[] rightMul = new int[size];

        public int[] productExceptSelf(int[] nums) {
            int length = nums.length;
            int[] result = new int[length];
            for (int i = 0; i < length; i++) {
                leftMul[i] = (i == 0 ? 1 : leftMul[i - 1]) * nums[i];
                rightMul[length - 1 - i] = (i == 0 ? 1 : rightMul[length - i]) * nums[length - 1 - i];
            }
            for (int i = 0; i < length; i++) {
                result[i] = (i == 0 ? 1 : leftMul[i - 1]) * (i == length - 1 ? 1 : rightMul[i + 1]);
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
