//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。 
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,1000] 
// 
// -10⁹ <= Node.val <= 10⁹ 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 2004 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashMap;
import java.util.Map;

//Java：路径总和 III
public class P437PathSumIii {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P437PathSumIii().new Solution();
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
//    class Solution {
//        /**
//         * 求出以root为起点的，总和为sum的路径个数
//         * 注意是连续的路径，这里不考虑中间断开的情况，中间断开的情况在pathSum的递归中实现
//         */
//        private int dfs(TreeNode root, long sum) {
//            if (root == null) return 0;
//            int count = 0;
//            if (root.val == sum) {
//                count++;
//            }
//            count += dfs(root.left, sum - root.val);
//            count += dfs(root.right, sum - root.val);
//            return count;
//        }
//
//        /**
//         * 求root树中，总和为targetSum的路径数
//         * 先求以root为起点的路径数（连续的，并且需要从root出发）
//         * 再求以左节点/右节点出发的路径数，也就是每个节点都求一次的意思
//         */
//        public int pathSum(TreeNode root, long targetSum) {
//            if (root == null) return 0;
//            int result = dfs(root, targetSum);
//            result += pathSum(root.left, targetSum);
//            result += pathSum(root.right, targetSum);
//            return result;
//        }
//    }
    // 由于题目说了路径只能从上往下，也就可以理解成一个数组，按前缀和来解题
    // 与普通数组不同的是数组在变化，前缀和数组是动态的
    class Solution {
        // prefix的含义是 前缀和为key的个数有value个
        private int dfs(TreeNode root, long targetSum, Map<Long, Integer> prefix, long cur) {
            if (root == null) return 0;
            // 新前缀和
            cur += root.val;
            // 查找走到现在，前面的节点是否出现过适合的前缀和
            // cur - ? = targetSum
            int count = prefix.getOrDefault(cur - targetSum, 0);
            // 更新和本节点相同的前缀和的个数
            prefix.put(cur, prefix.getOrDefault(cur, 0) + 1);
            // 递归让路径接着去到左右子树
            count += dfs(root.left, targetSum, prefix, cur);
            count += dfs(root.right, targetSum, prefix, cur);
            // 去掉本节点的前缀和记录
            prefix.put(cur, prefix.getOrDefault(cur, 0) - 1);
            // 理论上这里需要把前缀和修改回去，但是不起实际作用
            // cur -= root.val;
            return count;
        }

        public int pathSum(TreeNode root, long targetSum) {
            Map<Long, Integer> prefix = new HashMap<>();
            prefix.put(0L, 1); // 前缀和为0的个数有1个，这样节点val=sum时就可以更新
            return dfs(root, targetSum, prefix, 0);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
