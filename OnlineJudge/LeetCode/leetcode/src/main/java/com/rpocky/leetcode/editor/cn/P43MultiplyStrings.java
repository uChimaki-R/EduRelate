//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 
//输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 和 num2 只能由数字组成。 
// num1 和 num2 都不包含任何前导零，除了数字0本身。 
// 
//
// Related Topics 数学 字符串 模拟 👍 1403 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.List;

//Java：字符串相乘
public class P43MultiplyStrings {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P43MultiplyStrings().new Solution();
        System.out.println(solution.multiply("3", "6"));
        System.out.println(solution.multiply("123", "456"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
//        /**
//         * 计算多位数乘一位数的结果
//         */
//        public String mulOne(String a, String b) {
//            assert b.length() == 1;
//            int toMul = b.charAt(0) - '0';
//            int carry = 0;
//            StringBuilder sb = new StringBuilder();
//            for (int i = a.length() - 1; i >= 0; i--) {
//                int num = a.charAt(i) - '0';
//                int result = carry + num * toMul;
//                carry = result / 10;
//                sb.append(result % 10);
//            }
//            if (carry != 0) sb.append(carry);
//            return sb.reverse().toString();
//        }
//
//        /**
//         * 计算两个数相加的结果
//         */
//        public String add(String num1, String num2) {
//            if (num1.length() < num2.length()) return add(num2, num1);
//            int count = num2.length();
//            StringBuilder sb = new StringBuilder();
//            // 从后往前一个个加
//            int pos1 = num1.length() - 1;
//            int pos2 = num2.length() - 1;
//            int carry = 0;
//            while (count-- > 0) {
//                int n1 = num1.charAt(pos1--) - '0';
//                int n2 = num2.charAt(pos2--) - '0';
//                int sum = carry + n1 + n2;
//                carry = sum / 10;
//                sb.append(sum % 10);
//            }
//            count = num1.length() - num2.length(); // 两个数相差几位
//            if (carry == 0) {
//                // 没有进位，直接把长的多出来的数字拼上去
//                for (int i = count - 1; i >= 0; i--) {
//                    sb.append(num1.charAt(i));
//                }
//                return sb.reverse().toString();
//            } else {
//                if (count == 0) {
//                    // 有进位，并且两个数一样长，直接把进位拼到结果上
//                    // 23 + 99
//                    return String.valueOf(carry) + sb.reverse().toString();
//                } else {
//                    // 有进位，并且两个数不一样长，把进位和长的多出来的数字相加后拼到结果上
//                    // 123 + 99
//                    return add(String.valueOf(carry), num1.substring(0, count)) + sb.reverse().toString();
//                }
//            }
//        }
//
//        public String multiply(String num1, String num2) {
//            if (num1.length() < num2.length()) return multiply(num2, num1);
//            List<String> numToAdd = new ArrayList<>();
//            for (int i = num2.length() - 1; i >= 0; i--) {
//                // num1乘上num2此时位上的数字
//                StringBuilder result = new StringBuilder(mulOne(num1, String.valueOf(num2.charAt(i) - '0')));
//                // 补充尾部的0（竖式）
//                int count = num2.length() - 1 - i;
//                while (count-- > 0) {
//                    result.append("0");
//                }
//                numToAdd.add(result.toString());
//            }
//            // 竖式全部相加
//            String result = "0";
//            for (String num : numToAdd) {
//                result = add(result, num);
//            }
//            // 如果首位是0，只保留一个0
//            // 9133 * 0
//            if (result.charAt(0) == '0') return "0";
//            else return result;
//        }

        // 优化版
        // 将竖式的每个纵向作为数组的一个位置，对数组内容不断更新即可
        public String multiply(String num1, String num2) {
            if (num1.equals("0") || num2.equals("0")) return "0";
            // 因为两个数相乘的结果的位数不会超过二者位数之和，所以数组就开这么大即可（999（三位数）* 999（三位数）< 999*1000 = 999000 < 999999（六位数））
            int[] places = new int[num1.length() + num2.length()];
            for (int i = num1.length() - 1; i >= 0; i--) {
                int n1 = num1.charAt(i) - '0';
                for (int j = num2.length() - 1; j >= 0; j--) {
                    int n2 = num2.charAt(j) - '0';
                    // i + j 即为这两个数相乘后的结果十位数所在的纵列的下标（相乘的结果都是两位数，0x 或 xy）
                    // i + j + 1 即为个位数所在的纵列的下标
                    // 更新这两个下标的值（因为竖式计算的时候除了首尾，一个纵列不止一个数字，该下标的值可能在之前的迭代中更新了数值）
                    int before = places[i + j] * 10 + places[i + j + 1];
                    int after = before + n1 * n2;
                    places[i + j] = after / 10;
                    places[i + j + 1] = after % 10;
                }
            }
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < places.length; i++) {
                // 最前面没有进位就忽略
                if (i == 0 && places[i] == 0) continue;
                result.append(places[i]);
            }
            return result.toString();
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
