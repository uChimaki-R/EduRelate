//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
//
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 2876 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Comparator;
import java.util.PriorityQueue;

//Java：合并 K 个升序链表
public class P23MergeKSortedLists {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P23MergeKSortedLists().new Solution();
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
        public ListNode mergeKLists(ListNode[] lists) {
            // 本来想和一般的归并一样用一个辅助数组的，但是链表合并之后不会覆盖原来的位置，就不需要了
            mSort(lists, 0, lists.length - 1);
            if (lists.length == 0) return null; // 空的不能访问0下标
            return lists[0];
        }

        private void mergeTwoLists(ListNode[] lists, int left, int right) {
            ListNode l1 = lists[left];
            ListNode l2 = lists[right];
            ListNode head = new ListNode(0);
            ListNode cur = head;
            while (l1 != null && l2 != null) {
                if (l1.val < l2.val) {
                    cur.next = l1;
                    l1 = l1.next;
                } else {
                    cur.next = l2;
                    l2 = l2.next;
                }
                cur = cur.next;
            }
            if (l1 != null) cur.next = l1;
            if (l2 != null) cur.next = l2;
            lists[left] = head.next;
        }

        private void mSort(ListNode[] lists, int left, int right) {
            if (left < right) {
                int mid = (left + right) / 2;
                // 一直划分数组
                mSort(lists, left, mid);
                mSort(lists, mid + 1, right);
                // 把两个点合并，并放到左边那个点的下标位置
                mergeTwoLists(lists, left, mid + 1);
            }
        }

//        // 使用堆解决
//        // 4ms，上面的1ms
//        // 先将节点都放入小顶堆，每次取出堆顶的链表首元素并把链表去掉头节点后返回，为空则不放
//        public ListNode mergeKLists(ListNode[] lists) {
//            // 声明堆，重写比较方法
//            PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {
//                @Override
//                public int compare(ListNode o1, ListNode o2) {
//                    return o1.val - o2.val;
//                }
//            });
//            for (ListNode node : lists) {
//                if (node != null) {
//                    pq.add(node);
//                }
//            }
//            ListNode head = new ListNode(0);
//            ListNode cur = head;
//            while (!pq.isEmpty()) {
//                ListNode node = pq.poll();
//                cur.next = node;
//                node = node.next;
//                if (node != null) {
//                    pq.add(node);
//                }
//                cur = cur.next;
//            }
//            return head.next;
//        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
