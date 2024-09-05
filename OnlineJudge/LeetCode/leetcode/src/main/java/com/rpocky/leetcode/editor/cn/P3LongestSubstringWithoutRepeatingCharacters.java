//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 10301 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

//Java：无重复字符的最长子串
public class P3LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P3LongestSubstringWithoutRepeatingCharacters().new Solution();
        System.out.println(solution.lengthOfLongestSubstring("aab"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
//    class Solution {
//        public int lengthOfLongestSubstring(String s) {
//            int length = s.length();
//            int left = 0, right = 0, max = 0; // 滑动窗口
//            HashSet<Character> set = new HashSet<>();
//            while (right < length) {
//                Character c = s.charAt(right);
//                while (set.contains(c)) { // 如果之前存过c了，说明right之前有一个c，使用while还可以有if的效果
//                    // 一直移动左窗口，移除不在窗口内的字符，直到找到c并将c移除
//                    set.remove(s.charAt(left));
//                    left++;
//                }
//                set.add(c); // 这个char最后肯定是要在set里的
//                right++;
//                max = Math.max(max, set.size()); // set的最大大小就是结果
//            }
//            return max;
//        }
//    }

    // 使用map优化，不再一点点移动左窗口，而是根据键值跳跃性的移动左窗口
    class Solution {
        public int lengthOfLongestSubstring(String s) {
            int length = s.length();
            int left = 0, right = 0, max = 0;
            Map<Character, Integer> map = new HashMap<>();
            while (right < length) {
                Character c = s.charAt(right);
                if (map.containsKey(c)) {
                    // 如果存过这个字符，就把左窗口移动到存过的下标处+1的位置
                    // 如果存过的字符的下标在left之前，就保留left，所以需要取max
                    left = Math.max(left, map.get(c) + 1);
                }
                // 记录比较此时的长度
                max = Math.max(max, right - left + 1);
                // 更新这个字符的下标
                map.put(c, right);
                // 移动右窗口
                right++;
            }
            return max;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
