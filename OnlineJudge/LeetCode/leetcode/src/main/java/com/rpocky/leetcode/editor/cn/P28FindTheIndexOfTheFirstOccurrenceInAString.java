//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 2278 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：找出字符串中第一个匹配项的下标
public class P28FindTheIndexOfTheFirstOccurrenceInAString {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P28FindTheIndexOfTheFirstOccurrenceInAString().new Solution();
        System.out.println(solution.strStr("leetcode", "leeto"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int strStr(String haystack, String needle) {
            int[] next = getNext(needle);
            int i = 0, j = 0;
            while (i < haystack.length()) {
                if (haystack.charAt(i) == needle.charAt(j)) {
                    // 匹配则同时前进
                    i++;
                    j++;
                } else if (j > 0) { // 回溯
                    j = next[j - 1];
                } else i++; // j==0，也就是回溯到了needle的第一个位置，就是说没有以这个字符结尾的前缀，即这个字符没用
                if (j == needle.length()) return i - j;
            }
            return -1;
        }

        private int[] getNext(String needle) {
            // 求next数组
            // next[i]的值=字符串[0~i]的最长共同前后缀串的长度
            // 也就是说当匹配needle字符串的时候，如果第i个位置不相同了，可以回溯到next[i-1]的位置
            // 此时因为next[i-1]前面的部分和i前面的部分相同（相同前后缀），即和匹配到不同前的那部分成功匹配到的串相同
            // 此时被匹配的串不用移动指针，needle也可以直接从next[i-1]的位置开始继续匹配，减少了无用工作
            int[] next = new int[needle.length()];
            next[0] = 0; // 0个字符没有前缀后缀，最大前后缀长度为0
            int i = 1, len = 0; // 从第二个位置开始，初始最大前后缀长度为0
            while (i < needle.length()) {
                if (needle.charAt(i) == needle.charAt(len)) {
                    // 当前字符和目前的最长相同前后缀的前缀部分的下一个（就是len下标的位置）相同
                    // 即加上这个字符后，最长相同前后缀会变长一个字符，也就是说第i个位置回溯的位置为更新后的前缀的后一个字符(len+1)
                    // 同时i也前进，len的长度也更新
                    next[i++] = ++len;
                } else if (len == 0) {
                    // 下面的else回溯到了相同前后缀长度为0的情况，保存，并让i前进
                    next[i++] = 0;
                } else {
                    // 二者不相同，前后缀不能再增大，只能从前缀中找到一个小一点的前缀，后缀里找一个相同的小一点的后缀
                    // 让 这个找到的前缀 == 这个找到的后缀+needle[i]
                    // 而实际上当前的前后缀是相同的，也就是说上面这个说法就等价于
                    // 在前缀中找到一个相同的前后缀，使得 这个找到的前缀 == 这个找到的后缀+needle[i]
                    // 而事实上我们之前已经求过当前前缀部分这个子串的最大相同前后缀长度了，就是next[len-1]
                    // 我们可以通过比较next[len-1]处的字符和i处的字符是否相同来确定i的回溯位置（next[i]）
                    // 这就是第一个if的判断，也就是说我们只要把len改为next[len-1]让他继续循环即可
                    len = next[len - 1];
                }
            }
            return next;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
