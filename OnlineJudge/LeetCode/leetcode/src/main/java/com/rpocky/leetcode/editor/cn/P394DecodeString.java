//给定一个经过编码的字符串，返回它解码后的字符串。 
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。 
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。 
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "3[a]2[bc]"
//输出："aaabcbc"
// 
//
// 示例 2： 
//
// 
//输入：s = "3[a2[c]]"
//输出："accaccacc"
// 
//
// 示例 3： 
//
// 
//输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
// 
//
// 示例 4： 
//
// 
//输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 30 
// 
// s 由小写英文字母、数字和方括号
// '[]' 组成 
// s 保证是一个 有效 的输入。 
// s 中所有整数的取值范围为
// [1, 300] 
// 
//
// Related Topics 栈 递归 字符串 👍 1929 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：字符串解码
public class P394DecodeString {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P394DecodeString().new Solution();
        System.out.println(solution.decodeString("3[a]2[bc]"));
        System.out.println(solution.decodeString("3[a2[c]]"));
        System.out.println(solution.decodeString("2[abc]3[cd]ef"));
        System.out.println(solution.decodeString("abc3[cd]xyz"));
        System.out.println(solution.decodeString("100[leetcode]"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // p用数组让修改在递归中产生影响
        private String dfs(String s, int[] p) {
            // 全部递归结束
            if (p[0] >= s.length()) return "";

            StringBuilder sb = new StringBuilder();
            char c = s.charAt(p[0]);

            if (c == ']') {
                // 遇到]说明这一个[]中的内容完整了(某次递归的结束)，直接返回空字符串
                // 跳过]，让p++
                p[0]++;
                return "";
            } else if ('0' <= c && c <= '9') {
                // 数字，后面会紧跟[，一次递归的开始
                // 数字还不一定是个位数，如100，需要while拼接
                StringBuilder num = new StringBuilder();
                while (c != '[') {
                    num.append(c);
                    p[0]++;
                    c = s.charAt(p[0]);
                }
                // 获取数字
                int count = Integer.parseInt(num.toString());
                p[0]++; // 跳过[
                String after = dfs(s, p); // 获取[]中间的结果
                // 拼接count次
                sb.append(after.repeat(count));
            } else {
                // 字符直接拼接
                sb.append(c);
                p[0]++; // 跳过c
            }
            // 这次递归完成了（前面部分的[]），但是字符串不一定处理完成了，需要接着递归处理后续字符串
            return sb.toString() + dfs(s, p);
        }

        public String decodeString(String s) {
            return dfs(s, new int[]{0});
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
