//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出：3
//解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
// 
//
// 示例 2： 
// 
// 
//输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出：5
//解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], p = 1, q = 2
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [2, 10⁵] 内。 
// -10⁹ <= Node.val <= 10⁹ 
// 所有 Node.val 互不相同 。 
// p != q 
// p 和 q 均存在于给定的二叉树中。 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 2911 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：二叉树的最近公共祖先
public class P236LowestCommonAncestorOfABinaryTree {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P236LowestCommonAncestorOfABinaryTree().new Solution();
    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 在root这棵树上找p和q的最近公共祖先
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null) return null; // 树都没有，返回null
            if (root == p || root == q) return root; // 其中一个是根，最近祖先就是这个根
            // 到这里说明二者都不是根，尝试在左右子树上找公共祖先
            TreeNode left = lowestCommonAncestor(root.left, p, q);
            TreeNode right = lowestCommonAncestor(root.right, p, q);
            // 点的分布有三种情况：都在左边、都在右边、一个在左一个在右
            // left和right都为null，即点肯定是一个在左一个在右，这说明root就是他们的公共祖先
            if (left != null && right != null) return root;
            // 否则left和right肯定有一个不是null，即p和q要么同时在左，要么同时在右
            // 那么就直接返回递归结果即可
            return left != null ? left : right;
        }

        // 另一种方法：
        // 遍历树一遍，记录每个节点到他父节点的映射
        // 主函数里先调用遍历，然后遍历p的所有父节点，用set标记已访问，遍历q的父节点找到第一个已访问的节点返回，没有就返回null
    }
//leetcode submit region end(Prohibit modification and deletion)

}
