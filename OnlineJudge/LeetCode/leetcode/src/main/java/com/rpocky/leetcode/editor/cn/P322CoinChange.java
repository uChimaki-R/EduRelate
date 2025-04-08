//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。 
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 2³¹ - 1 
// 0 <= amount <= 10⁴ 
// 
//
// Related Topics 广度优先搜索 数组 动态规划 👍 3029 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：零钱兑换
public class P322CoinChange {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P322CoinChange().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // dp[i] 表示凑成i的最少硬币总数
        // 遍历硬币列表，dp[i] = min(dp[i], dp[i-coin] + 1)
        // 最大值，全都是1元，需要amount个
        // 初始值为最大值+1
        // +1是因为最大值也是一个合理的答案，如果答案得出是最大值+1，则说明无法凑成结果
        public int coinChange(int[] coins, int amount) {
            int[] dp = new int[amount + 1];
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                int minCount = amount + 1;
                for (int coin : coins) {
                    if (i >= coin) {
                        minCount = Math.min(minCount, dp[i - coin] + 1);
                    }
                }
                dp[i] = minCount;
            }
            return dp[amount] == amount + 1 ? -1 : dp[amount];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
