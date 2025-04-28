//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
//
// Related Topics 链表 👍 1961 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：反转链表 II
public class P92ReverseLinkedListIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P92ReverseLinkedListIi().new Solution();
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
        public ListNode reverseBetween(ListNode head, int left, int right) {
            int curPos = 1;
            ListNode pivot = new ListNode(0, head);
            ListNode cur = head, pre = pivot;
            // 找到反转区域的前一个节点pre
            for (int i = 0; i < left - 1; i++) {
                pre = pre.next;
                cur = cur.next;
            }
            // 对于后续的链表，遍历 right-left 次，使用头插法插入到pre后面实现反转
            for (int i = 0; i < right - left; i++) {
                ListNode next = cur.next;
                ListNode nnext = next.next;
                ListNode preNext = pre.next;
                // 把next头插到pre后面
                pre.next = next;
                next.next = preNext;
                cur.next = nnext;
                // 头插后cur自然后移了，一直是同一个点
            }
            return pivot.next;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
