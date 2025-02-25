//编写一个程序，通过填充空格来解决数独问题。 
//
// 数独的解法需 遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 
//
// 
// 
// 
// 示例 1： 
// 
// 
//输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".
//",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".
//","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6
//"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[
//".",".",".",".","8",".",".","7","9"]]
//输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8
//"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],[
//"4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9",
//"6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4",
//"5","2","8","6","1","7","9"]]
//解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
// 
// 
// 
// 
//
//
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 题目数据 保证 输入数独仅有一个解 
// 
//
// Related Topics 数组 哈希表 回溯 矩阵 👍 1900 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.List;

//Java：解数独
public class P37SudokuSolver {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P37SudokuSolver().new Solution();
        char[][] matrix = {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
        solution.solveSudoku(matrix);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private final boolean[][] row = new boolean[10][10];
        private final boolean[][] column = new boolean[10][10];
        private final boolean[][][] block = new boolean[3][3][10];
        private final List<int[]> blanks = new ArrayList<>();
        private boolean ok = false;

        /**
         * 初始化四个数组
         */
        private void init(char[][] board) {
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[i].length; j++) {
                    if (board[i][j] == '.') {
                        // 记录空格位置，深搜的时候就不用遍历来找空格
                        blanks.add(new int[]{i, j});
                    } else {
                        // 记录数字填写情况
                        int num = board[i][j] - '0';
                        row[i][num] = column[j][num] = block[i / 3][j / 3][num] = true;
                    }
                }
            }
        }

        /**
         * 深搜
         */
        private void dfs(char[][] board, int blankIndex) {
            if (ok) return;
            if (blankIndex == blanks.size()) {
                ok = true;
                return;
            }
            int[] position = blanks.get(blankIndex);
            int r = position[0], c = position[1];
            // 注意！！判断条件需要有 !ok ，否则归回去的时候某些循环还会把数组某些元素置为false
            // 导致后续进入某些循环时，会进入到if分支修改掉最终结果，导致错误
            // 所以需要在获得最终结果后让所有循环终止
            for (int v = 1; v <= 9 && !ok; v++) {
                if (!(row[r][v] || column[c][v] || block[r / 3][c / 3][v])) {
                    row[r][v] = column[c][v] = block[r / 3][c / 3][v] = true;
                    board[r][c] = (char) (v + '0');
                    dfs(board, blankIndex + 1);
                    row[r][v] = column[c][v] = block[r / 3][c / 3][v] = false;
                }
            }
        }

        public void solveSudoku(char[][] board) {
            init(board);
            dfs(board, 0);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
