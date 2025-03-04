//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 3670 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

//Java：括号生成
public class P22GenerateParentheses {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P22GenerateParentheses().new Solution();
        System.out.println(solution.generateParenthesis(4));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private final List<String> result = new ArrayList<>();

        public List<String> generateParenthesis(int n) {
            generate(n, 0, 0, "");
            return result;
        }

        private void generate(int n, int countLeft, int countRight, String buffer) {
            StringBuilder bufferBuilder = new StringBuilder(buffer);
            if (countLeft == n) {
                while (countRight++ != n) {
                    bufferBuilder.append(")");
                }
                buffer = bufferBuilder.toString();
                result.add(buffer);
                return;
            }
            if (countLeft < n) {
                bufferBuilder.append("(");
                generate(n, countLeft + 1, countRight, bufferBuilder.toString());
                bufferBuilder.deleteCharAt(bufferBuilder.length() - 1);
            }
            if (countRight < countLeft) {
                bufferBuilder.append(")");
                generate(n, countLeft, countRight + 1, bufferBuilder.toString());
                bufferBuilder.deleteCharAt(bufferBuilder.length() - 1);
            }
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
