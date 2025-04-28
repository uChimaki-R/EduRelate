//一条包含字母 A-Z 的消息通过以下映射进行了 编码 ： 
//
// "1" -> 'A' "2" -> 'B' ... "25" -> 'Y' "26" -> 'Z' 
//
// 然而，在 解码 已编码的消息时，你意识到有许多不同的方式来解码，因为有些编码被包含在其它编码当中（"2" 和 "5" 与 "25"）。 
//
// 例如，"11106" 可以映射为： 
//
// 
// "AAJF" ，将消息分组为 (1, 1, 10, 6) 
// "KJF" ，将消息分组为 (11, 10, 6) 
// 消息不能分组为 (1, 11, 06) ，因为 "06" 不是一个合法编码（只有 "6" 是合法的）。 
// 
//
// 注意，可能存在无法解码的字符串。 
//
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。如果没有合法的方式解码整个字符串，返回 0。 
//
// 题目数据保证答案肯定是一个 32 位 的整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "12"
//输出：2
//解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
// 
//
// 示例 2： 
//
// 
//输入：s = "226"
//输出：3
//解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
// 
//
// 示例 3： 
//
// 
//输入：s = "06"
//输出：0
//解释："06" 无法映射到 "F" ，因为存在前导零（"6" 和 "06" 并不等价）。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 100 
// s 只包含数字，并且可能包含前导零。 
// 
//
// Related Topics 字符串 动态规划 👍 1601 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：解码方法
public class P91DecodeWays {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P91DecodeWays().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 1-26是合法的，0和前导0都是不合法的
        // 考虑使用dp，dp[i]表示s前i个字符的解码种数
        // 对于dp[i]，因为解码位数可以是1位或者2位，考虑从dp[i-1]和dp[i-2]处转移过来，都能转移则取二者的和
        // 如果s[i]合法（不是0），则可以从dp[i-1]转移 dp[i] += dp[i-1]
        // 如果s[i-1]和s[i]组成的数字合法（没有前导0并且处于10-26），则可以从dp[i-2]转移 dp[i] += dp[i-2]
        // 考虑初始化，空字符串可以有一种解码方法 dp[0] = 1
        public int numDecodings(String s) {
            int n = s.length();
            int[] dp = new int[n + 1];
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                if (s.charAt(i - 1) != '0') {
                    dp[i] += dp[i - 1];
                }
                if (i > 1 && s.charAt(i - 2) != '0' && Integer.parseInt(s.substring(i - 2, i)) <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
            return dp[n];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
