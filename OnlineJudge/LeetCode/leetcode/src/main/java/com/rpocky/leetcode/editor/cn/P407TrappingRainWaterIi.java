//给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
//输出: 4
//解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
// 
//
// 示例 2: 
//
// 
//
// 
//输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
//输出: 10
// 
//
// 
//
// 提示: 
//
// 
// m == heightMap.length 
// n == heightMap[i].length 
// 1 <= m, n <= 200 
// 0 <= heightMap[i][j] <= 2 * 10⁴ 
// 
//
// 
//
// Related Topics 广度优先搜索 数组 矩阵 堆（优先队列） 👍 772 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.PriorityQueue;

//Java：接雨水 II
public class P407TrappingRainWaterIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P407TrappingRainWaterIi().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)

    /**
     * 木桶是否会漏水取决于最矮的那根木板
     * 维护一个小顶堆，堆内是当前的木桶外围木板
     * 取出木桶的最短木板，获取四个方向的木板：
     * 1. 木板访问过，跳过
     * 2. 木板比自己高，将它加入堆，它来代替自己挡住水
     * 3. 木板比自己低，则这个高度差能够存水，更新结果，然后当做这个木板长高到了和自己一样高，加入到堆里
     * 相等高度在2/3都是加入自己高度的柱子，没区别
     * 不断执行直到堆为空
     */
    class Solution {
        public int trapRainWater(int[][] heightMap) {
            // 每个木板的信息有：高度、坐标，存入堆用数组
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
            int n = heightMap.length;
            int m = heightMap[0].length;
            // visit数组
            boolean[][] visited = new boolean[n][m];
            for (int i = 0; i < heightMap.length; i++) {
                for (int j = 0; j < heightMap[i].length; j++) {
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                        // 把四周的柱子加入
                        pq.offer(new int[]{heightMap[i][j], i, j});
                        visited[i][j] = true;
                    }
                }
            }
            final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            int total = 0;
            while (!pq.isEmpty()) {
                int[] lowest = pq.poll();
                for (int[] direction : directions) {
                    int ni = lowest[1] + direction[0];
                    int nj = lowest[2] + direction[1];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m || visited[ni][nj]) {
                        continue;
                    }
                    visited[ni][nj] = true;
                    int height = heightMap[ni][nj];
                    if (height >= lowest[0]) {
                        // 高过/等于自己
                        pq.offer(new int[]{height, ni, nj});
                    } else {
                        // 低于自己
                        total += (lowest[0] - height);
                        // 填入的是自己的高度
                        pq.offer(new int[]{lowest[0], ni, nj});
                    }
                }
            }
            return total;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
