//在给定的 m x n 网格
// grid 中，每个单元格可以有以下三个值之一： 
//
// 
// 值 0 代表空单元格； 
// 值 1 代表新鲜橘子； 
// 值 2 代表腐烂的橘子。 
// 
//
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。 
//
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
//输出：-1
//解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
// 
//
// 示例 3： 
//
// 
//输入：grid = [[0,2]]
//输出：0
//解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 10 
// grid[i][j] 仅为 0、1 或 2 
// 
//
// Related Topics 广度优先搜索 数组 矩阵 👍 982 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

//Java：腐烂的橘子
public class P994RottingOranges {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P994RottingOranges().new Solution();
//        int[][] grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
//        int[][] grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
//        int[][] grid = {{0, 2}};
        int[][] grid = {{0}};
        System.out.println(solution.orangesRotting(grid));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

//        public int orangesRotting(int[][] grid) {
//            // 统计好坏橘子数量
//            int n = grid.length;
//            int m = grid[0].length;
//            int countGood = 0, countBad = 0;
//            for (int[] row : grid) {
//                for (int j = 0; j < m; j++) {
//                    if (row[j] == 1) countGood++;
//                    else if (row[j] == 2) countBad++;
//                }
//            }
//            // 没有好橘子，开局就是全坏的
//            // 这个判断要先于下面的判断，让 {{0}} 这种案例判定为已经全坏而不是不能全坏
//            if (countGood == 0) return 0;
//            // 没有坏橘子，不可能全变坏
//            if (countBad == 0) return -1;
//            int count = 0;
//            while (true) {
//                List<int[]> toBad = new ArrayList<>();
//                // 可能标记相同位置，用标记数组识别
//                boolean[][] visited = new boolean[n][m];
//                // 标记所有变坏的橘子
//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < m; j++) {
//                        if (grid[i][j] == 2) {
//                            for (int[] direction : directions) {
//                                int newRow = i + direction[0];
//                                int newCol = j + direction[1];
//                                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
//                                if (!visited[newRow][newCol] && grid[newRow][newCol] == 1) {
//                                    visited[newRow][newCol] = true;
//                                    toBad.add(new int[]{newRow, newCol});
//                                }
//                            }
//                        }
//                    }
//                }
//                // 没有变化，跳出循环
//                if (toBad.isEmpty()) break;
//                // 将标记的橘子变坏，更新好坏橘子数量
//                for (int[] t : toBad) {
//                    grid[t[0]][t[1]] = 2;
//                    countGood--;
//                    countBad++;
//                }
//                // 更新分钟数
//                count++;
//            }
//            // 还有没变坏的，说明不可能全变坏
//            if (countGood != 0) return -1;
//            // 返回耗时
//            return count;
//        }

        // 使用多源广搜法
        public int orangesRotting(int[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            int[][] badTimes = new int[n][m];
            int goodCount = 0;
            // 提前准备好队列，把坏橘子放进去
            Queue<int[]> queue = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // 初始化为-1
                    badTimes[i][j] = -1;
                    // 坏橘子腐烂时间为0，放入队列
                    if (grid[i][j] == 2) {
                        badTimes[i][j] = 0;
                        queue.add(new int[]{i, j});
                    }
                    // 记录好橘子数量
                    else if (grid[i][j] == 1) goodCount++;
                }
            }
            int ans = 0;
            while (!queue.isEmpty()) {
                int[] curr = queue.poll();
                for (int[] direction : directions) {
                    int x = curr[0] + direction[0];
                    int y = curr[1] + direction[1];
                    // 越界/空/已记录腐烂时间（已腐烂）
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || badTimes[x][y] != -1) continue;
                    // 肯定是好橘子，腐烂时间为当前坏橘子腐烂时间+1，ans不断更新这个最大值
                    ans = badTimes[x][y] = badTimes[curr[0]][curr[1]] + 1;
                    // （标记为烂橘子），可以不标，因为直接判断badTimes有没有被修改即可
//                    grid[x][y] = 2;
                    // 减少好橘子数量
                    goodCount--;
                    // 好橘子没了就break，或者没有坏橘子产生则while结束
                    if (goodCount == 0) break;
                    // 该橘子变坏，加入队列，下一批继续腐烂
                    queue.add(new int[]{x, y});
                }
            }
            // 还有好橘子说明不可能全坏，否则返回结果
            return goodCount == 0 ? ans : -1;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
