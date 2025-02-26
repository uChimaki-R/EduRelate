//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
//
// Related Topics 递归 链表 👍 2391 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：K 个一组翻转链表
public class P25ReverseNodesInKGroup {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P25ReverseNodesInKGroup().new Solution();
        ListNode node5 = new P25ReverseNodesInKGroup().new ListNode(5);
        ListNode node4 = new P25ReverseNodesInKGroup().new ListNode(4, node5);
        ListNode node3 = new P25ReverseNodesInKGroup().new ListNode(3, node4);
        ListNode node2 = new P25ReverseNodesInKGroup().new ListNode(2, node3);
        ListNode node1 = new P25ReverseNodesInKGroup().new ListNode(1, node2);
        ListNode result = solution.reverseKGroup(node1, 3);
        while (result != null) {
            System.out.println(result.val);
            result = result.next;
        }
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
        public ListNode reverseKGroup(ListNode head, int k) {
            // 看够不够k个
            ListNode cur = head;
            for (int i = 0; i < k; i++) {
                if (cur == null) return head;
                if (i != k - 1) cur = cur.next; //最后一个不移动，后面反转链表要用
            }
            // 递归先处理好了后续链表
            ListNode follow = reverseKGroup(cur.next, k);
            // 把head到cur的链表反转
            cur.next = null; // 先把链表断开，然后就可以按链表反转处理这段链表（cur现在指着要反转的最后一个点）
            cur = head;
            ListNode pre = null;
            while (cur != null) {
                // 暂存链表后续
                ListNode temp = cur.next;
                // 把cur指向前面
                cur.next = pre;
                // cur和pre同时后移
                pre = cur;
                cur = temp;
            }
            // head现在是这段链表的结尾，接上递归处理好的后续链表follow
            head.next = follow;
            return pre; // pre现在是这段链表的开头，返回头节点，即这段链表处理好了，会成为别人的follow
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
