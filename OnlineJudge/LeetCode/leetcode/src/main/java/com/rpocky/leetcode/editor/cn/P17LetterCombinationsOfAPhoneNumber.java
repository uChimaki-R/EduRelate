//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2884 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

//Java：电话号码的字母组合
public class P17LetterCombinationsOfAPhoneNumber {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P17LetterCombinationsOfAPhoneNumber().new Solution();
        System.out.println(solution.letterCombinations("2"));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private final List<String> map = new ArrayList<>(Arrays.asList("", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"));
        private final List<String> result = new ArrayList<>();

        public List<String> letterCombinations(String digits) {
            if (digits == null || digits.isEmpty()) return result;
            init(digits, 0, "");
            return result;
        }

        private void init(String digits, int index, String buffer) {
            if (index == digits.length()) {
                if (!buffer.isEmpty()) result.add(buffer);
                return;
            }
            String letters = map.get(digits.charAt(index) - '0');
            for (int i = 0; i < letters.length(); i++) {
                init(digits, index + 1, buffer + letters.charAt(i));
            }
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
