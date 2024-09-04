//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 10776 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：两数相加
public class P2AddTwoNumbers {
    public static void main(String[] args) {
        // TO TEST
        P2AddTwoNumbers p = new P2AddTwoNumbers();
        Solution solution = p.new Solution();
        ListNode l1 = p.new ListNode(2);
        ListNode l2 = p.new ListNode(4);
        l1.next = l2;
        ListNode l3 = p.new ListNode(3);
        l2.next = l3;
        ListNode l4 = p.new ListNode(5);
        ListNode l5 = p.new ListNode(6);
        l4.next = l5;
        ListNode l6 = p.new ListNode(4);
        l5.next = l6;
        ListNode result = solution.addTwoNumbers(l1, l4);
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
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode result = new ListNode(), temp = result;
            int carry = 0; // 进位
            while (l1 != null || l2 != null) {
                int x = l1 == null ? 0 : l1.val;
                int y = l2 == null ? 0 : l2.val;
                int sum = x + y + carry;
                carry = sum / 10;
                ListNode next = new ListNode(sum % 10);
                temp.next = next; // 保存下一点信息
                temp = next; // 指向下一点
                l1 = l1 == null ? null : l1.next;
                l2 = l2 == null ? null : l2.next;
            }
            if (carry > 0) {
                temp.next = new ListNode(carry); // 最高位进位多加个点
            }
            return result.next; // 第一位不存东西
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
