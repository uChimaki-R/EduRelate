//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2481 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.HashMap;
import java.util.Map;

//Java：从前序与中序遍历序列构造二叉树
public class P105ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P105ConstructBinaryTreeFromPreorderAndInorderTraversal().new Solution();
        int[] preorder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};
        System.out.println(solution.buildTree(preorder, inorder));
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
        // 前序遍历 根左右 数组分布: [根[  左子树  ][  右子树  ]]
        // 中序遍历 左根右 数组分布: [[  左子树  ]根[  右子树  ]]
        // 从前序遍历的数组拿到根，因为保证了不重复元素，所以可以在中序遍历数组中找到根的位置
        // 进而确定左子树和右子树的节点数量，之后递归建树即可
        // 为了快速定位根节点，需要给中序数组初始化一个映射
        // 这样其实递归中就不需要inorder数组了，实际上因为递归出口用 preLeft>preRight 就足够了，也不需要inRight，但是为了好理解就都写上去
        private Map<Integer, Integer> valueToIndex;

        private void initMap(int[] inorder) {
            valueToIndex = new HashMap<>();
            for (int i = 0; i < inorder.length; i++) {
                valueToIndex.put(inorder[i], i);
            }
        }

        private TreeNode buildTree(int[] preorder, int[] inorder, int preLeft, int preRight, int inLeft, int inRight) {
            if (preLeft > preRight) return null;
            // 确定根节点
            TreeNode root = new TreeNode(preorder[preLeft]);
            // 获取中序数组根节点位置
            int index = valueToIndex.get(preorder[preLeft]);
            int leftCount = index - inLeft;
            // 递归构建左子树和右子树
            root.left = buildTree(preorder, inorder, preLeft + 1, preLeft + leftCount, inLeft, index - 1);
            root.right = buildTree(preorder, inorder, preLeft + leftCount + 1, preRight, index + 1, inRight);
            return root;
        }

        public TreeNode buildTree(int[] preorder, int[] inorder) {
            initMap(inorder);
            return buildTree(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
