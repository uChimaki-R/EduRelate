//给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现
//在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。 
//
// 
//
// 示例 1: 
//
// 
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
// 
//
// 示例 2: 
//
// 
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
// 
//
// 示例 3: 
//
// 
//输入: temperatures = [30,60,90]
//输出: [1,1,0] 
//
// 
//
// 提示： 
//
// 
// 1 <= temperatures.length <= 10⁵ 
// 30 <= temperatures[i] <= 100 
// 
//
// Related Topics 栈 数组 单调栈 👍 1919 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayDeque;
import java.util.Deque;

//Java：每日温度
public class P739DailyTemperatures {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P739DailyTemperatures().new Solution();
        int[] temperatures = new int[]{73, 74, 75, 71, 69, 72, 76, 73};
        solution.dailyTemperatures(temperatures);
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 压栈，遇到比栈顶大的数字就一直更新栈里压着的内容，直到小于等于栈顶/栈空
        public int[] dailyTemperatures(int[] temperatures) {
            Deque<int[]> stack = new ArrayDeque<>();
            int[] result = new int[temperatures.length];
            for (int i = 0; i < temperatures.length; i++) {
                if (stack.isEmpty()) {
                    // 栈为空，直接压栈
                    stack.push(new int[]{i, temperatures[i]});
                } else {
                    while (!stack.isEmpty() && stack.peek()[1] < temperatures[i]) {
                        int[] pop = stack.pop();
                        // 更新这个温度较小的天数的结果
                        result[pop[0]] = i - pop[0];
                    }
                    // 压栈
                    stack.push(new int[]{i, temperatures[i]});
                }
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
