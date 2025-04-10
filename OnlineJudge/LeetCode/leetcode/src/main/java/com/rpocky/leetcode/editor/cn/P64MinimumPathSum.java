//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 
//
// 示例 1： 
// 
// 
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 200 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 1802 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：最小路径和
public class P64MinimumPathSum {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P64MinimumPathSum().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
//        // dp[i][j] 存储从 (0, 0) 到 (i, j) 所需的最小路径和
//        // 则对于单行/单列，可以初始化
//        // 对于中间的i、j，可以从上方/左侧转移过来（向下走/向右走）
//        public int minPathSum(int[][] grid) {
//            int n = grid.length;
//            int m = grid[0].length;
//            int[][] dp = new int[n][m];
//            // 初始化
//            dp[0][0] = grid[0][0];
//            for (int i = 1; i < n; i++) {
//                dp[i][0] = dp[i - 1][0] + grid[i][0];
//            }
//            for (int i = 1; i < m; i++) {
//                dp[0][i] = dp[0][i - 1] + grid[0][i];
//            }
//            // 转移
//            for (int i = 1; i < n; i++) {
//                for (int j = 1; j < m; j++) {
//                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//                }
//            }
//            return dp[n - 1][m - 1];
//        }

        // dp 从左侧和上方转移，且步长为1，可以优化到一维数组
        public int minPathSum(int[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            int[] dp = new int[m];
            // 初始化
            dp[0] = grid[0][0];
            for (int i = 1; i < m; i++) {
                dp[i] = dp[i - 1] + grid[0][i];
            }
            // 转移
            for (int i = 1; i < n; i++) {
                dp[0] = dp[0] + grid[i][0];
                for (int j = 1; j < m; j++) {
                    dp[j] = Math.min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
            return dp[m - 1];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
