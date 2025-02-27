//给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。 
//
// 整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。 
//
// 返回被除数 dividend 除以除数 divisor 得到的 商 。 
//
// 注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−2³¹, 231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 2
//31 − 1 ；如果商 严格小于 -2³¹ ，则返回 -2³¹ 。 
//
// 
//
// 示例 1: 
//
// 
//输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = 3.33333.. ，向零截断后得到 3 。 
//
// 示例 2: 
//
// 
//输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = -2.33333.. ，向零截断后得到 -2 。 
//
// 
//
// 提示： 
//
// 
// -2³¹ <= dividend, divisor <= 2³¹ - 1 
// divisor != 0 
// 
//
// Related Topics 位运算 数学 👍 1244 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：两数相除
public class P29DivideTwoIntegers {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P29DivideTwoIntegers().new Solution();
        System.out.println(solution.divide(-2147483648, -1));
        System.out.println(solution.divide(-2147483648, -2));
        System.out.println(solution.divide(2147483647, 1));
        System.out.println(solution.divide(2147483647, 2));
        System.out.println(solution.divide(45, 2));
        System.out.println(solution.divide(10, 3));
        System.out.println(solution.divide(100579234, -555806774));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int divide(int dd, int dr) {
            // 用long算
            long dividend = dd;
            long divisor = dr;
            // 正负数判断
            boolean negative = dividend < 0 ^ divisor < 0;
            dividend = Math.abs(dividend);
            divisor = Math.abs(divisor);
            // 除数更大返回0，不然（100579234, -555806774）超时
            if (dividend < divisor) return 0;
            // 按二进制列竖式除法思路
            // 先看下被除数有多少位
            long count1 = 0, temp1 = 1;
            while (dividend >= temp1) {
                count1++;
                temp1 <<= 1;
            }
            // 看除数有多少位
            long count2 = 0, temp2 = 1;
            while (divisor >= temp2) {
                count2++;
                temp2 <<= 1;
            }
            // 将除数扩大到被除数的位数
            divisor <<= (count1 - count2);
            // 一共要算差的位数+1次
            long times = count1 - count2 + 1;
            long result = 0;
            // 从高位到低位一点点减去
            while (times-- != 0) {
                result <<= 1;
                if (dividend >= divisor) {
                    // 这个位上为1
                    dividend -= divisor;
                    result += 1;
                }
                divisor >>= 1;
            }
            if (negative) result = -result;
            if (result > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (result < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            return (int) result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
