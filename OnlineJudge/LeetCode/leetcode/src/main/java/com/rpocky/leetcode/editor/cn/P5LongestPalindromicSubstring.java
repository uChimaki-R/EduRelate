//给你一个字符串 s，找到 s 中最长的 回文 子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 双指针 字符串 动态规划 👍 7321 👎 0


package com.rpocky.leetcode.editor.cn;

//Java：最长回文子串
public class P5LongestPalindromicSubstring {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P5LongestPalindromicSubstring().new Solution();
        System.out.println(solution.longestPalindrome("cbbd"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public String longestPalindrome(String s) {
            // 动态规划
            // dp[i][j]标志从下标i到下标j的子串是否是回文串
            // dp[i][j]=true 当且仅当 dp[i+1][j-1]=true && s[i]==s[j]
            int length = s.length();
            boolean[][] dp = new boolean[length][length];
            int maxLength = 1, index = 0; // 至少0下标的字符可以是回文串
            // 初始化单个字符肯定是回文串
            for (int i = 0; i < length; i++) dp[i][i] = true;
            // 把长度为2的单独遍历一遍，保证下面的遍历长度至少为3，左边+1右边-1之后中间至少有一个字符
            // 这样就不用初始化如dp[3][2]=true的情况了（左边+1到3，右边-1到2，导致i>j）
            for (int start = 0; start < length - 1; start++) {
                if (s.charAt(start) == s.charAt(start + 1)){
                    dp[start][start + 1] = true;
                    maxLength = 2;
                    index = start;
                }
            }
            // 从3开始遍历所有长度
            for (int len = 3; len <= length; len++) {
                // 遍历起始坐标
                for (int start = 0; start < length; start++) {
                    // 判断合法性
                    if (start + len > length) break;
                    if (dp[start + 1][start + len - 2] && (s.charAt(start) == s.charAt(start + len - 1))) {
                        // 里面的是回文串并且两边的字符相同，则整个也是一个回文串
                        dp[start][start + len - 1] = true;
                    }
                    if(dp[start][start + len -1] && len > maxLength){
                        // 如果是回文串并且长度需要更新，更新长度和新开始下标
                        maxLength = len;
                        index = start;
                    }
                }
            }
            return s.substring(index, index + maxLength);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
