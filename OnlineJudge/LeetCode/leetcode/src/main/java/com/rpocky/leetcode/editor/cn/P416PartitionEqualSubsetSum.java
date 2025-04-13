//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 2331 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：分割等和子集
public class P416PartitionEqualSubsetSum {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P416PartitionEqualSubsetSum().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        /**
         * 要求分割成两个和相同的部分，那么说明总和一定是一个偶数
         * 题目等价于从数组中选取元素，使得这些元素的和等于数组所有元素的和的一半
         * 所以肯定需要知道总和是多少
         * 剪枝考虑：记录数组中存在的最大数，如果这个最大的数都大过总和的一半（提供了半数的和），那么肯定分不了两个相等的部分
         * 类似背包问题，只是选取的物品要刚好背包一半大小
         * 定义dp[i][j]为前i个元素是否能选择构造成和为j
         * 考虑nums[i]和当前背包容量j的关系
         * 如果nums[i]<=j，说明能放入背包，则考虑放或者不放两种情况，有一种能为true即可
         * dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
         * 如果nums[i]>j，说明放不到背包里，则选不了
         * dp[i][j] = dp[i-1][j]
         * 初始化，j为0的话，只要不选就满足了，所以dp[i][0]都是true
         */
        public boolean canPartition(int[] nums) {
            int maxValue = 0;
            int sum = 0;
            for (int num : nums) {
                sum += num;
                maxValue = Math.max(maxValue, num);
            }
            int target = sum >> 1;
            if ((sum & 1) == 1 || maxValue > target) {
                return false;
            }
            boolean[][] dp = new boolean[nums.length][target + 1];
            for (int i = 0; i < nums.length; i++) {
                dp[i][0] = true;
            }
            // 初始化第一个数，只能选第一个数，则能够构造和为nums[0]
            dp[0][nums[0]] = true;
            for (int i = 1; i < nums.length; i++) {
                for (int j = 0; j <= target; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (nums[i] <= j) {
                        dp[i][j] |= dp[i - 1][j - nums[i]];
                    }
                }
            }
            return dp[nums.length - 1][target];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
