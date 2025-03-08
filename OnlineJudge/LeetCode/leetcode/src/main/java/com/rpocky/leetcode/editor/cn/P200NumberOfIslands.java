//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2705 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：岛屿数量
public class P200NumberOfIslands {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P200NumberOfIslands().new Solution();
//        char[][] grid = new char[][]{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
//        char[][] grid = new char[][]{{'0'}};
        char[][] grid = new char[][]{{'1'}, {'1'}};
        System.out.println(solution.numIslands(grid));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private static final int[][] directions = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        //
//        private void dfs(char[][] grid, int row, int col) {
//            grid[row][col] = '0';
//            for (int[] direction : directions) {
//                int newRow = row + direction[0];
//                int newCol = col + direction[1];
//                if (newRow < 0 || newRow >= grid.length || newCol < 0 || newCol >= grid[0].length || grid[newRow][newCol] == '0')
//                    continue;
//                dfs(grid, newRow, newCol);
//            }
//        }
//
//        public int numIslands(char[][] grid) {
//            // 找到1就深搜把所有连接的1改为0，每深搜一次就说明有一个岛屿
//            int count = 0;
//            for (int i = 0; i < grid.length; i++) {
//                for (int j = 0; j < grid[i].length; j++) {
//                    if (grid[i][j] == '1') {
//                        count++;
//                        dfs(grid, i, j);
//                    }
//                }
//            }
//            return count;
//        }
        // 尝试使用并查集解决
        // 0号下标不能用，否则 [["0"]] 这种测试样例结果会是1
        private int[] parent;

        private void init(char[][] grid) {
            int n = grid.length, m = grid[0].length;
            parent = new int[n * (m + 1)]; // 每行多一个
            for (int i = 0; i < n * (m + 1); i++) {
                parent[i] = i;
            }
            parent[0] = -1; // 排除0号下标影响
        }

        private void union(int i, int j) {
            int pi = find(i);
            int pj = find(j);
            if (pi != pj) {
                // 以小的为父亲
                parent[pi] = parent[pj] = Math.min(pi, pj);
            }
        }

        private int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }

        public int numIslands(char[][] grid) {
            init(grid);
            int count = 0;
            int n = grid.length, m = grid[0].length;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // 每次找到1都把四周设为同一类
                    if (grid[i][j] == '1') {
                        for (int[] direction : directions) {
                            int newI = i + direction[0];
                            int newJ = j + direction[1];
                            if (newI < 0 || newI >= n || newJ < 0 || newJ >= m || grid[newI][newJ] == '0')
                                continue;
                            // 每一行都向后移动一个，每行有 m+1 个，跳过前面行的 i*(m+1) 个后加上j，因为每行向后移动一个所以还要+1，后续同理
                            union(i * (m + 1) + (j + 1), newI * (m + 1) + (newJ + 1));
                        }
                    } else {
                        // 非陆地
                        parent[i * (m + 1) + (j + 1)] = -1;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (parent[i * (m + 1) + (j + 1)] == i * (m + 1) + (j + 1)) count++;
                }
            }
            return count;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
