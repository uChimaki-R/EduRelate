//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。 
//
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 
//
// 
// 例如，121 是回文，而 123 不是。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 121
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：x = -121
//输出：false
//解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3： 
//
// 
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
//
// 
//
// 进阶：你能不将整数转为字符串来解决这个问题吗？ 
//
// Related Topics 数学 👍 2892 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：回文数
public class P9PalindromeNumber {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P9PalindromeNumber().new Solution();
        System.out.println(solution.isPalindrome(-10));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
//        public boolean isPalindrome(int x) {
//            if (x < 0) return false;
//            String s = String.valueOf(x);
//            int left = 0, right = s.length() - 1;
//            while (left < right) {
//                if (s.charAt(left) != s.charAt(right)) return false;
//                left++;
//                right--;
//            }
//            return true;
//        }
        // 尝试不借用字符串
        public boolean isPalindrome(int x) {
            if (x < 0) return false;
            // 看反转之后是不是相等就行了
            int rev = 0, temp = x;
            while (temp != 0){
                rev = rev * 10 + temp % 10;
                temp = temp / 10;
            }
            return rev == x;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
