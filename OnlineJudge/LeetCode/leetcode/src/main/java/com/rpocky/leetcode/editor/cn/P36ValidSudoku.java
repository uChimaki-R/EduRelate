//请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 
//
// 注意： 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 空白格用 '.' 表示。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：board = 
//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = 
//[["8","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//输出：false
//解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无
//效的。 
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字（1-9）或者 '.' 
// 
//
// Related Topics 数组 哈希表 矩阵 👍 1267 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：有效的数独
public class P36ValidSudoku {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P36ValidSudoku().new Solution();
        System.out.println(solution.isValidSudoku(new char[][]{new char[]{'5', '3', '.', '.', '7', '.', '.', '.', '.' }, new char[]{'6', '.', '.', '1', '9', '5', '.', '.', '.' }, new char[]{'.', '9', '8', '.', '.', '.', '.', '6', '.' }, new char[]{'8', '.', '.', '.', '6', '.', '.', '.', '3' }, new char[]{'4', '.', '.', '8', '.', '3', '.', '.', '1' }, new char[]{'7', '.', '.', '.', '2', '.', '.', '.', '6' }, new char[]{'.', '6', '.', '.', '.', '.', '2', '8', '.' }, new char[]{'.', '.', '.', '4', '1', '9', '.', '.', '5' }, new char[]{'.', '.', '.', '.', '8', '.', '.', '7', '9' }}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public boolean isValidSudoku(char[][] board) {
            for (int i = 0; i < 9; i++) {
                // 三种都是判断9次
                if (!checkRow(board, i)) return false;
                if (!checkCol(board, i)) return false;
                if (!checkBox(board, i)) return false;
            }
            return true;
        }

        private boolean checkRow(char[][] board, int index) {
            int bin = 0;
            for (int i = 0; i < 9; i++) {
                if (board[index][i] == '.') continue;
                int b = 1 << (board[index][i] - '0');
                // 有重复的数字
                if ((b & bin) != 0) return false;
                bin |= b;
            }
            return true;
        }

        private boolean checkCol(char[][] board, int index) {
            int bin = 0;
            for (int i = 0; i < 9; i++) {
                if (board[i][index] == '.') continue;
                int b = 1 << (board[i][index] - '0');
                // 有重复的数字
                if ((b & bin) != 0) return false;
                bin |= b;
            }
            return true;
        }

        private boolean checkBox(char[][] board, int index) {
            int row = index / 3 * 3;
            int col = index % 3 * 3;
            int bin = 0;
            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    if (board[i][j] == '.') continue;
                    int b = 1 << (board[i][j] - '0');
                    // 有重复的数字
                    if ((b & bin) != 0) return false;
                    bin |= b;
                }
            }
            return true;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
