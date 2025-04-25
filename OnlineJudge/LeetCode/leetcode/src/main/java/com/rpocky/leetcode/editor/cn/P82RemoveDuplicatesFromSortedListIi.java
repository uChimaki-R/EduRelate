//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,3,4,4,5]
//输出：[1,2,5]
// 
//
// 示例 2： 
// 
// 
//输入：head = [1,1,1,2,3]
//输出：[2,3]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目在范围 [0, 300] 内 
// -100 <= Node.val <= 100 
// 题目数据保证链表已经按升序 排列 
// 
//
// Related Topics 链表 双指针 👍 1360 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：删除排序链表中的重复元素 II
public class P82RemoveDuplicatesFromSortedListIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P82RemoveDuplicatesFromSortedListIi().new Solution();
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
        public ListNode deleteDuplicates(ListNode head) {
            // 辅助节点
            ListNode beg = new ListNode(0, head);
            ListNode pre = beg, cur = head;
            while (cur != null) {
                // 因为有和自己相同的数的话自己也要删除，所以整一个标记
                boolean isDeleted = false;
                while (cur.next != null && cur.val == cur.next.val) {
                    isDeleted = true;
                    cur.next = cur.next.next;
                }
                if (isDeleted) {
                    // 有相同的，while循环里把后续相同的删除之后，这里将自己删除
                    pre.next = cur.next;
                    cur = pre.next;
                } else {
                    // 正常遍历链表
                    pre = cur;
                    cur = cur.next;
                }
            }
            // 返回头节点
            return beg.next;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
