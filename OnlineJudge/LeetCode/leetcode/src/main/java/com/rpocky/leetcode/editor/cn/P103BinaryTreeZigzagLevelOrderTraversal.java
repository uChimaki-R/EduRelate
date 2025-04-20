//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 955 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.*;

//Java：二叉树的锯齿形层序遍历
public class P103BinaryTreeZigzagLevelOrderTraversal {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P103BinaryTreeZigzagLevelOrderTraversal().new Solution();
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
        // 正常层序遍历，在插入结果的时候使用头插/尾插
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            boolean isLeftToRight = true;
            List<List<Integer>> result = new ArrayList<>();
            if (root == null) {
                return result;
            }
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                // 当前层的节点
                int count = queue.size();
                Integer[] nodes = new Integer[count];
                for (int i = 0; i < count; i++) {
                    TreeNode node = queue.poll();
                    if (isLeftToRight) {
                        nodes[i] = node.val;
                    } else {
                        nodes[count - 1 - i] = node.val;
                    }
                    // 存入下一层节点
                    if (node.left != null) {
                        queue.offer(node.left);
                    }
                    if (node.right != null) {
                        queue.offer(node.right);
                    }
                }
                // 保存结果
                result.add(Arrays.asList(nodes));
                // 切换顺序
                isLeftToRight = !isLeftToRight;
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
