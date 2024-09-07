//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。 
//
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下： 
//
// 
//P   A   H   N
//A P L S I I G
//Y   I   R 
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。 
//
// 请你实现这个将字符串进行指定行数变换的函数： 
//
// 
//string convert(string s, int numRows); 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
// 
//
//示例 2：
//
// 
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
// 
//
// 示例 3： 
//
// 
//输入：s = "A", numRows = 1
//输出："A"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由英文字母（小写和大写）、',' 和 '.' 组成 
// 1 <= numRows <= 1000 
// 
//
// Related Topics 字符串 👍 2367 👎 0


package com.rpocky.leetcode.editor.cn;

import java.util.LinkedList;
import java.util.List;

//Java：Z 字形变换
public class P6ZigzagConversion {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P6ZigzagConversion().new Solution();
        System.out.println(solution.convert("PAYPALISHIRING", 3));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public String convert(String s, int numRows) {
            // 特判一下numRows=1的情况
            if (numRows == 1) return s;

            List<StringBuilder> lists = new LinkedList<>();
            for (int i = 0; i < numRows; i++) {
                // 每行的字符串构造器
                lists.add(new StringBuilder());
            }
            int currRow = 0, plusNum = 1;
            // 遍历字符串，从前往后依次塞入到构造器中，到最后的构造器时就放过来塞直到第一个构造器，然后循环
            for (int i = 0; i < s.length(); i++) {
                lists.get(currRow).append(s.charAt(i)); // 存入构造器
                currRow += plusNum; // 到下一个构造器
                if (currRow == numRows - 1 || currRow == 0) {
                    // 到达边界，下次换个方向
                    plusNum = -plusNum;
                }
            }
            // 拼接结果
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < numRows; i++) {
                sb.append(lists.get(i));
            }
            return sb.toString();
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
