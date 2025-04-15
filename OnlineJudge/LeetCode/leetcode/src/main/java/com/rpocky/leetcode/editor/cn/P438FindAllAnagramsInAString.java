//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 1655 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.List;

//Java：找到字符串中所有字母异位词
public class P438FindAllAnagramsInAString {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P438FindAllAnagramsInAString().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        /**
         * 基于滑动窗口，根据窗口前后字符的添加和移除，动态更新窗口内子串和p的差异关系diff
         */
        public List<Integer> findAnagrams(String s, String p) {
            List<Integer> result = new ArrayList<>();
            // p更长，不可能有异位词
            if (s.length() < p.length()) {
                return result;
            }
            // s和p的字母个数差异数组
            int[] diffCounts = new int[26];
            // 初始化，窗口处于下标0处，更新差异数组
            for (int i = 0; i < p.length(); i++) {
                diffCounts[s.charAt(i) - 'a']++;
                diffCounts[p.charAt(i) - 'a']--;
            }
            // 记录当前有多少字母是不等个数的
            int diff = 0;
            for (int diffCount : diffCounts) {
                if (diffCount != 0) {
                    diff++;
                }
            }
            // 最开始就有可能是异位词
            if (diff == 0) {
                result.add(0);
            }
            // 滑动窗口，动态更新diff
            for (int i = 0; i < s.length() - p.length(); i++) {
                // 更新前判断一下左侧去除的字母差异数
                if (diffCounts[s.charAt(i) - 'a'] == 1) {
                    // 差异为1，去除之后差异为0，diff减少
                    diff--;
                } else if (diffCounts[s.charAt(i) - 'a'] == 0) {
                    // 原本没有差异，移除这个字母，差异增加
                    diff++;
                }
                // 移除字母，修改差异
                diffCounts[s.charAt(i) - 'a']--;
                // 右侧同理
                if (diffCounts[s.charAt(i + p.length()) - 'a'] == -1) {
                    // 差异为-1，添加这个字母之后差异为0，diff减少
                    diff--;
                } else if (diffCounts[s.charAt(i + p.length()) - 'a'] == 0) {
                    // 原本没有差异，添加这个字母，差异增加
                    diff++;
                }
                // 添加字母，修改差异
                diffCounts[s.charAt(i + p.length()) - 'a']++;

                // 如果差异为0，加入结果
                if (diff == 0) {
                    result.add(i + 1);
                }
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
