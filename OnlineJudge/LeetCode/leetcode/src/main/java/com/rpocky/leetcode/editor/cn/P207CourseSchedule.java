//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。 
//
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表
//示如果要学习课程 ai 则 必须 先学习课程 bi 。 
//
// 
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。 
// 
//
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。 
//
// 示例 2： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。 
//
// 
//
// 提示： 
//
// 
// 1 <= numCourses <= 2000 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// prerequisites[i] 中的所有课程对 互不相同 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 2100 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

//Java：课程表
public class P207CourseSchedule {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P207CourseSchedule().new Solution();
//        int[][] prerequisites = new int[][]{{1, 0}, {0, 1}};
//        System.out.println(solution.canFinish(2, prerequisites));
        int[][] prerequisites = new int[][]{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
        System.out.println(solution.canFinish(5, prerequisites));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 拓扑排序
//        // 解法一：深度优先搜索
//        // 把自己的子节点全部搜索完毕后（加入了拓扑结果），将自己加入结果，保证了自己的出点在自己之前
//        // 为了记录是否有环，不能只是记录visited，要出点改为三种情况：
//        // 1、未搜索：标记点为搜索中，对点进行深搜
//        // 2、搜索中：出点有搜索中的点，即出现了环，无结果
//        // 3、已搜索：该出点已经加入结果，即出点及之后的点都处理完毕了，无需处理
//
//        // 邻接矩阵
//        private List<List<Integer>> graph;
//        int[] visitType;
//        private boolean valid;
//
//        void dfs(int index) {
//            if (!valid) return;
//            // 标记点为搜索中
//            visitType[index] = 1;
//            // 遍历所有出点
//            for (Integer toNode : graph.get(index)) {
//                if (visitType[toNode] == 0) {
//                    dfs(toNode);
//                } else if (visitType[toNode] == 1) {
//                    valid = false;
//                    return;
//                } // else 已搜索
//            }
//            // 节点遍历结束，标记自己为已搜索
//            visitType[index] = 2;
//        }
//
//        public boolean canFinish(int numCourses, int[][] prerequisites) {
//            valid = true;
//            // 初始化邻接表
//            graph = new ArrayList<>();
//            visitType = new int[numCourses];
//            for (int i = 0; i < numCourses; i++) {
//                graph.add(new ArrayList<>());
//            }
//            for (int[] prerequisite : prerequisites) {
//                graph.get(prerequisite[0]).add(prerequisite[1]);
//            }
//            // 每个点深搜
//            for (int i = 0; i < numCourses; i++) {
//                if (visitType[i] == 0) {
//                    dfs(i);
//                }
//            }
//            return valid;
//        }

        // 解法2，广度优先搜索
        // 记录每个点的入度，把所有入度为0的点入队
        // 每次出队一个点，（加入结果集），将该点所连的所有点入度减一
        // 查看是否有入度为0的点，有则入栈
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            int[] ins = new int[numCourses];
            // 初始化
            List<List<Integer>> graph = new ArrayList<>();
            for (int i = 0; i < numCourses; i++) {
                graph.add(new ArrayList<>());
            }
            for (int[] prerequisite : prerequisites) {
                ins[prerequisite[1]]++;
                graph.get(prerequisite[0]).add(prerequisite[1]);
            }
            // 入度为0，入队
            Queue<Integer> queue = new LinkedList<>();
            for (int i = 0; i < ins.length; i++) {
                if (ins[i] == 0) {
                    queue.add(i);
                }
            }
            while (!queue.isEmpty()) {
                int cur = queue.poll();
                List<Integer> neighbours = graph.get(cur);
                // 出点入度减一
                for (Integer neighbour : neighbours) {
                    ins[neighbour]--;
                    // 入度为0，加入队列
                    if (ins[neighbour] == 0) {
                        queue.add(neighbour);
                    }
                }
            }
            // 全部入度为0则可以有拓扑排序
            for (int in : ins) {
                if (in != 0) return false;
            }
            return true;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
