//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4], k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 2675 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Collections;
import java.util.Random;

//Java：数组中的第K个最大元素
public class P215KthLargestElementInAnArray {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P215KthLargestElementInAnArray().new Solution();
        System.out.println(solution.findKthLargest(new int[]{3, 2, 1, 5, 6, 4}, 2));
        System.out.println(solution.findKthLargest(new int[]{2, 1}, 2));
        System.out.println(solution.findKthLargest(new int[]{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        //        // 直观想法，使用大根堆，弹出到第k个
//        // 显然是O(NlogN)的，不符合题意，但是可以练一下手写堆排序
//        public int findKthLargest(int[] nums, int k) {
//            // 对堆进行下沉初始化
//            int len = nums.length;
//            // 从 len/2-1 处，也就是最后一个点的父节点开始（最后一个点为 len-1 ，如果是左节点，父节点为(len-1-1)/2=len/2-1，如果是右节点，父节点为(len-1-2)/2=len/2-1）
//            for (int i = len / 2 - 1; i >= 0; i--) {
//                // 对i下标的点进行下沉操作
//                down(nums, i, len);
//            }
//            // 取出首元素，取k-1次
//            for (int i = 1; i < k; i++) {
//                // 取出放在末尾
//                swap(nums, 0, len - 1);
//                // 堆长度-1
//                len--;
//                // 下沉操作
//                down(nums, 0, len);
//            }
//            return nums[0];
//        }
//
//        // 注意！下沉操作的范围会变化（如果有结果出堆了的话）
//        // 因为结果放在数组后部分，所以需要限制下沉操作的范围，否则会把整个堆又初始化
//        private void down(int[] nums, int i, int nowLength) {
//            int left = i * 2 + 1, right = i * 2 + 2;
//            int largestIndex = i;
//            if (left < nowLength && nums[left] > nums[largestIndex]) {
//                largestIndex = left;
//            }
//            if (right < nowLength && nums[right] > nums[largestIndex]) {
//                largestIndex = right;
//            }
//            if (largestIndex != i) {
//                // 将i和较大的那个交换
//                swap(nums, largestIndex, i);
//                // 对换下去的那个点继续下沉操作
//                down(nums, largestIndex, nowLength);
//            }
//        }
//
//        private void swap(int[] nums, int i, int j) {
//            int temp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = temp;
//        }

//        // 然而下面的做法提交 1634 ms,击败了10.71%
//        // 上面堆排序 28 ms,击败了60.77%
//        // 看评论说应该是有大量连续相同的导致了算法效率下降，但是我改了之后还是提不起来
//        // 使用打乱思路也只提升了1%，可以忽略
//        // 题解思路
//        // 使用快排，当选定的pivot为第n-k个时返回结果
//        public int findKthLargest(int[] nums, int k) {
//            // O(n)随机打乱，让算法更高效（防测试样例）
//            shuffle(nums);
//            return fastSort(nums, 0, nums.length - 1, nums.length - k);
//        }
//
//        public static void shuffle(int[] array) {
//        Random rnd = new Random();
//        for (int i = array.length - 1; i > 0; i--) {
//            int j = rnd.nextInt(i + 1); // 生成0到i的随机索引
//            // 交换array[i]和array[j]
//            int temp = array[i];
//            array[i] = array[j];
//            array[j] = temp;
//        }
//    }
//
//        private int fastSort(int[] nums, int left, int right, int k) {
//            int pivot = nums[left]; // 选取最左边的为哨兵
//            int i = left, j = right;
//            while (i < j) {
//                while (i < j && nums[j] >= pivot) j--;
//                nums[i] = nums[j];
//                while (i < j && nums[i] <= pivot) i++;
//                nums[j] = nums[i];
//            }
//            // 放回哨兵
//            nums[j] = pivot;
//            // 结果判断
//            if (j == k) return nums[k];
//            // 本来需要递归左右全部排序，但是只要第k个，那就只递归k所在那边即可
//            if (k < j) return fastSort(nums, left, j - 1, k);
//            return fastSort(nums, j + 1, right, k);
//        }

        // 测试官方解的耗时
        // 11 ms,击败了86.29%
        int quickselect(int[] nums, int l, int r, int k) {
            if (l == r) return nums[k];
            int x = nums[l], i = l - 1, j = r + 1;
            while (i < j) {
                do i++; while (nums[i] < x);
                do j--; while (nums[j] > x);
                if (i < j) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
            if (k <= j) return quickselect(nums, l, j, k);
            else return quickselect(nums, j + 1, r, k);
        }

        public int findKthLargest(int[] _nums, int k) {
            int n = _nums.length;
            return quickselect(_nums, 0, n - 1, n - k);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
