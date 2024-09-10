//请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。 
//
// 函数 myAtoi(string s) 的算法如下： 
//
// 
// 空格：读入字符串并丢弃无用的前导空格（" "） 
// 符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。 
// 转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。 
// 舍入：如果整数数超过 32 位有符号整数范围 [−2³¹, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2³¹ 的整数应
//该被舍入为 −2³¹ ，大于 231 − 1 的整数应该被舍入为 231 − 1 。 
// 
//
// 返回整数作为最终结果。 
//
// 
//
// 示例 1： 
//
// 
// 输入：s = "42" 
// 
//
// 输出：42 
//
// 解释：加粗的字符串为已经读入的字符，插入符号是当前读取的字符。 
//
// 
//带下划线线的字符是所读的内容，插入符号是当前读入位置。
//第 1 步："42"（当前没有读入字符，因为没有前导空格）
//         ^
//第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//         ^
//第 3 步："42"（读入 "42"）
//           ^
// 
//
//
// 示例 2： 
//
// 
// 输入：s = " -042" 
// 
//
// 输出：-42 
//
// 解释： 
//
// 
//第 1 步："   -042"（读入前导空格，但忽视掉）
//            ^
//第 2 步："   -042"（读入 '-' 字符，所以结果应该是负数）
//             ^
//第 3 步："   -042"（读入 "042"，在结果中忽略前导零）
//               ^
// 
//
//
// 示例 3： 
//
// 
// 输入：s = "1337c0d3" 
// 
//
// 输出：1337 
//
// 解释： 
//
// 
//第 1 步："1337c0d3"（当前没有读入字符，因为没有前导空格）
//         ^
//第 2 步："1337c0d3"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//         ^
//第 3 步："1337c0d3"（读入 "1337"；由于下一个字符不是一个数字，所以读入停止）
//             ^
// 
//
//
// 示例 4： 
//
// 
// 输入：s = "0-1" 
// 
//
// 输出：0 
//
// 解释： 
//
// 
//第 1 步："0-1" (当前没有读入字符，因为没有前导空格)
//         ^
//第 2 步："0-1" (当前没有读入字符，因为这里不存在 '-' 或者 '+')
//         ^
//第 3 步："0-1" (读入 "0"；由于下一个字符不是一个数字，所以读入停止)
//          ^
// 
//
//
// 示例 5： 
//
// 
// 输入：s = "words and 987" 
// 
//
// 输出：0 
//
// 解释： 
//
// 读取在第一个非数字字符“w”处停止。 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 200 
// s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成 
// 
//
// Related Topics 字符串 👍 1850 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：字符串转换整数 (atoi)
public class P8StringToIntegerAtoi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P8StringToIntegerAtoi().new Solution();
        System.out.println(solution.myAtoi("-1010023630o4"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int myAtoi(String s) {
            // 去除空格
            s = s.trim();
            if (s.isEmpty()) return 0;

            long result = 0;
            // 标记负数，如果有负号要去掉
            boolean negative = false;
            boolean flag = false; // 标记是不是处理过+-的情况了，像 -+12 这种，符号只处理一次，-+12返回0
            if (s.charAt(0) == '-') {
                negative = true;
                s = s.substring(1);
                flag = true;
            }
            if (s.isEmpty()) return 0;

            // 如果有正号要去掉
            if (!flag && s.charAt(0) == '+') {
                s = s.substring(1);
            }
            if (s.isEmpty()) return 0;

            // 去除前导0
            while (s.charAt(0) == '0') {
                s = s.substring(1);
                if (s.isEmpty()) return 0;
            }

            // 遍历
            for (int i = 0; i < s.length(); i++) {
                // 存在巨大数字，甚至超过了long的范围，这种要提前返回，不然后续返回int的最大/最小值时会出错
                if (i > 10) { // 大过10位，即百亿数字及以上
                    if (negative) return Integer.MIN_VALUE;
                    else return Integer.MAX_VALUE;
                }
                // 正常判断
                if (Character.isDigit(s.charAt(i))) {
                    result = result * 10 + Character.getNumericValue(s.charAt(i));
                } else break;
            }

            // 负数
            if (negative) {
                result = -result;
            }

            // int范围判断
            if (result > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (result < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            return (int) result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
