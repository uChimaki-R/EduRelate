//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
//
// Related Topics 字典树 字符串 👍 3173 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：最长公共前缀
public class P14LongestCommonPrefix {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P14LongestCommonPrefix().new Solution();
        System.out.println(solution.longestCommonPrefix(new String[]{"dog", "racecar", "car"}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
//    public String longestCommonPrefix(String[] strs) {
//        StringBuilder result = new StringBuilder();
//        for (int pos = 0; pos < 200; pos++) {
//            boolean same = true;
//            // 取一个标志字符，取之前要判断是否越界
//            if (pos == strs[0].length()) return result.toString();
//            char ch = strs[0].charAt(pos);
//            for (int i = 1; i < strs.length; i++) {
//                if (pos == strs[i].length()) {
//                    // 有字符串扫描到最后的位置了，返回结果
//                    return result.toString();
//                }
//                if (ch != strs[i].charAt(pos)) same = false;
//            }
//            if (same) result.append(ch);
//            else return result.toString(); // 有不同的就说明已经到了最大前缀长度了
//        }
//        return result.toString();
//    }

        // 别人的思路
        // 以最短的字符串为标准即可，遍历看其他字符串是否以该字符串开头，不是则截短再次判断，直到该字符串满足以该最短的字符串的某个前缀开头
        public String longestCommonPrefix(String[] strs) {
            // 先找出最短的字符串，先假设他就是最长前缀
            String preStr = strs[0];
            for (String str : strs) {
                if (str.length() < preStr.length()) {
                    preStr = str;
                }
            }
            // 遍历所有字符串，将前缀（preStr）一点点截短以满足其是所有字符串的前缀
            for (String str : strs) {
                while (!str.startsWith(preStr)) {
                    preStr = preStr.substring(0, preStr.length() - 1);
                }
            }
            return preStr;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
