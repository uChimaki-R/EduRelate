//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
// 
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 10⁹ 
// 
//
// Related Topics 链表 双指针 👍 1132 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：旋转链表
public class P61RotateList {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P61RotateList().new Solution();
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
        public ListNode rotateRight(ListNode head, int k) {
            if (head == null || head.next == null) {
                return head;
            }
            // 统计长度，找到最后一个点
            int length = 1;
            ListNode pre = head;
            ListNode cur = head.next;
            while (cur != null) {
                length++;
                pre = cur;
                cur = cur.next;
            }
            // 连成环
            pre.next = head;
            k %= length;
            // 断开 length-k 处的连接
            int p = length - k;
            cur = head;
            ListNode newHead = head.next;
            while (--p > 0) {
                cur = cur.next;
                newHead = cur.next;
            }
            cur.next = null;
            return newHead;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
