//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xⁿ ）。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100
// 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// n 是一个整数 
// 要么 x 不为零，要么 n > 0 。 
// -104 <= xⁿ <= 104 
// 
//
// Related Topics 递归 数学 👍 1431 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：Pow(x, n)
public class P50PowxN {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P50PowxN().new Solution();
        System.out.println(solution.myPow(2.00000, -2));
        System.out.println(solution.myPow(1.00000, -2147483648));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public double myPow(double x, int n) {
            // Java 代码中 int32 变量 n∈[−2147483648,2147483647]
            // 当 n=−2147483648 时执行 n=−n 会因越界而赋值出错。
            // 所以用long将n保存下来计算
            long N = n;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            double result = 1;
            while (N > 0) {
                if ((N & 1) == 1) result *= x; // 奇数，结果乘一次底数
                N >>= 1; // 指数折半
                x *= x; // 底数平方
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
