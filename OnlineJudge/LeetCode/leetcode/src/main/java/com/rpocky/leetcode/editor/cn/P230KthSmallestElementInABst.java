//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,1,4,null,2], k = 1
//输出：1
// 
//
// 示例 2： 
// 
// 
//输入：root = [5,3,6,2,4,null,null,1], k = 3
//输出：3
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数为 n 。 
// 1 <= k <= n <= 10⁴ 
// 0 <= Node.val <= 10⁴ 
// 
//
// 
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？ 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 951 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

//Java：二叉搜索树中第 K 小的元素
public class P230KthSmallestElementInABst {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P230KthSmallestElementInABst().new Solution();
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
//        public int kthSmallest(TreeNode root, int k) {
//            if (root == null) return -1;
//            // 中序遍历找到第k个点
//            Deque<TreeNode> stack = new ArrayDeque<>();
//            int count = 0;
//            TreeNode cur = root;
//            while (cur != null || !stack.isEmpty()) {
//                // 所有左子树入栈
//                while (cur != null) {
//                    stack.push(cur);
//                    cur = cur.left;
//                }
//                // 遍历点
//                cur = stack.pop();
//                count++;
//                if (count == k) {
//                    return cur.val;
//                }
//                // 右子树进入下次迭代
//                cur = cur.right;
//            }
//            return -1;
//        }
//    }
    // 先找出每个根的左右子树节点个数情况，根据分布二分查找
    class Solution {
        private final Map<TreeNode, Integer> countMap = new HashMap<>();

        private int getCount(TreeNode root) {
            if (root == null) return 0;
            if (countMap.containsKey(root)) return countMap.get(root);
            int count = 1 + getCount(root.left) + getCount(root.right);
            countMap.put(root, count);
            return count;
        }

        public int kthSmallest(TreeNode root, int k) {
            while (true) {
                int count = getCount(root.left);
                if (count + 1 == k) {
                    return root.val;
                } else if (count + 1 < k) {
                    root = root.right;
                    k -= count + 1; // 记得更新k
                } else {
                    root = root.left;
                }
            }
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
