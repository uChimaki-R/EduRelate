//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCCED"
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"SEE"
//输出：true
// 
//
// 示例 3： 
// 
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = 
//"ABCB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
//
// Related Topics 深度优先搜索 数组 字符串 回溯 矩阵 👍 1951 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashMap;
import java.util.Map;

//Java：单词搜索
public class P79WordSearch {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P79WordSearch().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private static final int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        private boolean dfs(char[][] board, int i, int j, String word, int pos, boolean[][] visited) {
            if (board[i][j] != word.charAt(pos)) return false; // 不相同，无法接着深搜
            else if (pos == word.length() - 1) return true; // 相同，且到了word最后，成功搜索到
            visited[i][j] = true;
            for (int[] direction : directions) {
                int x = i + direction[0];
                int y = j + direction[1];
                if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || visited[x][y]) continue;
                boolean flag = dfs(board, x, y, word, pos + 1, visited);
                if (flag) return true;
            }
            visited[i][j] = false;
            return false;
        }

        public boolean exist(char[][] board, String word) {
            // -------------剪枝一--------------
            // 168 ms,击败了43.89% 的Java用户 ----> 24 ms,击败了95.82% 的Java用户
            // word中某个字母多过board的某个字母，直接返回false
            // 大小字母都有，65-90、97-122
            int[] boardCharCount = new int[122 - 65 + 1];
            int[] wordCharCount = new int[122 - 65 + 1];
            for (char[] chars : board) {
                for (char c : chars) {
                    boardCharCount[c - 'A']++;
                }
            }
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                wordCharCount[c - 'A']++;
                if (wordCharCount[c - 'A'] > boardCharCount[c - 'A']) return false;
            }
            // ------------------------------
            // 测试样例里不加这个剪枝更快。。。
//            // -------------剪枝二------------
//            // 60 ms,击败了94.48% 的Java用户
//            // 如果board里word最后一个字母出现比较多，就将word反转，让多数递归在前面，减少递归次数
//            if (wordCharCount[word.charAt(word.length() - 1) - 'A'] > wordCharCount[word.charAt(0) - 'A']) {
//                word = new StringBuilder(word).reverse().toString();
//            }
//            // ------------------------------
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[0].length; j++) {
                    if (board[i][j] == word.charAt(0)) {
                        boolean[][] visited = new boolean[board.length][board[0].length];
                        // 是否能在board的i，j下标开始找到word0下标及之后的字符串
                        boolean flag = dfs(board, i, j, word, 0, visited);
                        if (flag) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
