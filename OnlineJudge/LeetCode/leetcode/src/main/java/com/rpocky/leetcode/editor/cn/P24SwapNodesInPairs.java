//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
// Related Topics 递归 链表 👍 2274 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：两两交换链表中的节点
public class P24SwapNodesInPairs {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P24SwapNodesInPairs().new Solution();
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 递归思想：假设除了前两个点，后面都交换好了，接着交换前两个点，把后一个点的next指向后面即可
        public ListNode swapPairs(ListNode head) {
            // 递归终止条件：不足两个点
            if (head == null || head.next == null) return head;
            // 交换两个点
            ListNode newHead = head.next;
            head.next = swapPairs(newHead.next); // 认为后面交换好了，直接获取（让后面的先处理）
            newHead.next = head;
            return newHead;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
