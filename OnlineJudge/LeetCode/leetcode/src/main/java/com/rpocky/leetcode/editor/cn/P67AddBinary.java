//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。 
//
// 
//
// 示例 1： 
//
// 
//输入:a = "11", b = "1"
//输出："100" 
//
// 示例 2： 
//
// 
//输入：a = "1010", b = "1011"
//输出："10101" 
//
// 
//
// 提示： 
//
// 
// 1 <= a.length, b.length <= 10⁴ 
// a 和 b 仅由字符 '0' 或 '1' 组成 
// 字符串如果不是 "0" ，就不含前导零 
// 
//
// Related Topics 位运算 数学 字符串 模拟 👍 1275 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：二进制求和
public class P67AddBinary {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P67AddBinary().new Solution();
        System.out.println(solution.addBinary("1010", "1011"));
        System.out.println(solution.addBinary("100", "110010"));
        System.out.println(solution.addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public String addBinary(String a, String b) {
            if (a.length() < b.length()) return addBinary(b, a);
            StringBuilder sb = new StringBuilder();
            int carry = 0, pa = a.length() - 1, pb = b.length() - 1;
            while (pb >= 0) {
                int aa = a.charAt(pa) - '0';
                int bb = b.charAt(pb) - '0';
                int sum = aa + bb + carry;
                carry = sum / 2;
                sb.append(sum % 2);
                pa--;
                pb--;
            }
            String front = a.substring(0, pa + 1);
            if (carry != 0) {
                if (a.length() == b.length()) {
                    sb.append(carry);
                    return sb.reverse().toString();
                } else {
                    return addBinary(front, "1") + sb.reverse().toString();
                }
            }
            return front + sb.reverse().toString();
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
