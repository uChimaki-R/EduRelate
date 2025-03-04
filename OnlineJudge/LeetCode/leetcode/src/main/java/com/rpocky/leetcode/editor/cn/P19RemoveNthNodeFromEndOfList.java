//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
//
// Related Topics 链表 双指针 👍 2929 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：删除链表的倒数第 N 个结点
public class P19RemoveNthNodeFromEndOfList {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P19RemoveNthNodeFromEndOfList().new Solution();
        ListNode listNode = new P19RemoveNthNodeFromEndOfList().new ListNode(1, null);
        ListNode result = solution.removeNthFromEnd(listNode, 1);
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
        public ListNode removeNthFromEnd(ListNode head, int n) {
            // 使用两个指针，一个先到第n个点，然后两个指针一起走，快指针到达末尾则慢指针到达倒数第n个点的位置
            // 有可能会删掉头指针，自己搞个头指针指向他给的头指针
            ListNode hHead = new ListNode(-1, head);
            ListNode slow = hHead;
            ListNode fast = hHead;
            while (n-- != 0) {
                fast = fast.next;
            }
            while (fast.next != null) {
                fast = fast.next;
                slow = slow.next;
            }
            slow.next = slow.next.next;
            // 返回的是自己的头指针的下一个而不是head
            // 删了head然后这里写返回head理论上应该是返回null，没问题才是，可能是测试的时候jvm还没回收head？写head可能算野指针？
            return hHead.next;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
