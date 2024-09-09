//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。 
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−2³¹, 231 − 1] ，就返回 0。 
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
// 
//
// 示例 1： 
//
// 
//输入：x = 123
//输出：321
// 
//
// 示例 2： 
//
// 
//输入：x = -123
//输出：-321
// 
//
// 示例 3： 
//
// 
//输入：x = 120
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：x = 0
//输出：0
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
// Related Topics 数学 👍 4018 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;

//Java：整数反转
public class P7ReverseInteger {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P7ReverseInteger().new Solution();
        System.out.println(solution.reverse(-2147483648));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int reverse(int x) {
            boolean negative = false;
            if (x < 0) {
                negative = true;
                x = -x;
            }
            long result = 0;
            while (x != 0) {
                int digit = x % 10;
                result = result * 10 + digit;
                if (result > Integer.MAX_VALUE || result < -Integer.MAX_VALUE) return 0;
                x /= 10;
            }
            return negative ? (int) -result : (int) result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
