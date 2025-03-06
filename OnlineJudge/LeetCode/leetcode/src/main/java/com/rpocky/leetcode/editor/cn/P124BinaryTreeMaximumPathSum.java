//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定
//经过根节点。 
//
// 路径和 是路径中各节点值的总和。 
//
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3]
//输出：6
//解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6 
//
// 示例 2： 
// 
// 
//输入：root = [-10,9,20,null,null,15,7]
//输出：42
//解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围是 [1, 3 * 10⁴] 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 2361 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：二叉树中的最大路径和
public class P124BinaryTreeMaximumPathSum {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P124BinaryTreeMaximumPathSum().new Solution();
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
    class Solution {
        private int maxSum = Integer.MIN_VALUE;

        /**
         * 获取从root出发能获得的最大路径和
         * 注意一定是从root出发，返回的不是从左子树经过根到右子树这种
         * 但是上述这种情况可以在递归中用来更新maxSum
         */
        private int solve(TreeNode root) {
            if (root == null) return 0;
            // 左右子树中有最大是负值的就不要那棵子树
            int left = Math.max(solve(root.left), 0);
            int right = Math.max(solve(root.right), 0);
            // maxSum还要更新从左子树经过根到右子树这种情况
            maxSum = Math.max(maxSum, left + right + root.val);
            // 返回的值必须是从root出发这种的能获得的最大路径和
            return Math.max(left, right) + root.val;
        }

        public int maxPathSum(TreeNode root) {
            // 在递归获取从每个点出发能获得的最大路径和的时候会更新maxSum
            solve(root);
            return maxSum;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
