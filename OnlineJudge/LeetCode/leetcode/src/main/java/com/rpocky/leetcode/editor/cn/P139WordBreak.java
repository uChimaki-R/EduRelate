//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅由小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
//
// Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2726 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Arrays;
import java.util.List;

//Java：单词拆分
public class P139WordBreak {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P139WordBreak().new Solution();
        System.out.println(solution.wordBreak("leetcode", Arrays.asList("leet", "code")));
        System.out.println(solution.wordBreak("applepenapple", Arrays.asList("apple", "pen")));
        System.out.println(solution.wordBreak("catsandog", Arrays.asList("cats", "dog", "sand", "and", "cat")));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // dp[i] s的前i个字符是否能由字典构成
        // 从0-i枚举中间点j，则 dp[i] = dp[j] && s(j-i)存在于字典中
        public boolean wordBreak(String s, List<String> wordDict) {
            boolean[] dp = new boolean[s.length() + 1];
            // 空字符串可以从字典中构成
            dp[0] = true;
            // i是子串结尾下标，所以从1到length
            for (int i = 1; i <= s.length(); i++) {
                // j是子串开始下标，所以从0到i-1
                for (int j = 0; j < i; j++) {
                    if (dp[j] && wordDict.contains(s.substring(j, i))) {
                        dp[i] = true;
                        // 有一个成立就行，break
                        break;
                    }
                }
            }
            return dp[s.length()];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
