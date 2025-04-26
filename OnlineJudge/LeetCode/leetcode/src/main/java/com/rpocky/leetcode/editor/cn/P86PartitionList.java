//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。 
//
// 你应当 保留 两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [2,1], x = 2
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 200] 内 
// -100 <= Node.val <= 100 
// -200 <= x <= 200 
// 
//
// Related Topics 链表 双指针 👍 902 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：分隔链表
public class P86PartitionList {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P86PartitionList().new Solution();
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
        public ListNode partition(ListNode head, int x) {
            ListNode lessNode = new ListNode(), greaterNode = new ListNode();
            ListNode cur = head, ln = lessNode, gn = greaterNode;
            while (cur != null) {
                // 使用next保存，目的是断开cur的后续节点，否则会有环
                ListNode next = cur.next;
                cur.next = null;
                if (cur.val < x) {
                    lessNode.next = cur;
                    lessNode = cur;
                } else {
                    greaterNode.next = cur;
                    greaterNode = cur;
                }
                cur = next;
            }
            // 小的的最后连上大的的开始
            lessNode.next = gn.next;
            // 返回头节点
            return ln.next;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
