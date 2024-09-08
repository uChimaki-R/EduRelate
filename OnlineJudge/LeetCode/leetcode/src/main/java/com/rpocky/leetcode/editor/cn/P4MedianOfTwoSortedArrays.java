//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
//
// Related Topics 数组 二分查找 分治 👍 7210 👎 0

package com.rpocky.leetcode.editor.cn;

import java.text.DecimalFormat;
import java.util.Arrays;

//Java：寻找两个正序数组的中位数
public class P4MedianOfTwoSortedArrays {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P4MedianOfTwoSortedArrays().new Solution();
        System.out.println(solution.findMedianSortedArrays(new int[]{1, 3, 6, 9}, new int[]{2, 4, 8, 9}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)


    class Solution {
        /**
         * 在两个有序数组中找第k小的数字
         */
        private int getKthSmallest(int[] nums1, int start1, int[] nums2, int start2, int k) {
            // 确保nums1是较短的数组
            if (nums1.length - start1 > nums2.length - start2) {
                return getKthSmallest(nums2, start2, nums1, start1, k);
            }
            // nums1数组为空，直接返回nums2的第k个数字
            if (nums1.length == start1) return nums2[start2 + k - 1];
            // 如果k为1就返回两个数组第一个下标下数字较小的那个
            if (k == 1) return Math.min(nums1[start1], nums2[start2]);
            // 比较第k/2个位置的数字
            // 因为num1比较短，k/2可能会越界，需要和长度取min
            int i = Math.min(nums1.length, start1 + k / 2);
            int j = start2 + k - k / 2; // num1取k/2，num2就要取k-k/2，因为k有奇偶数之分，所以需要用减法确保相加为k
            if (nums1[i - 1] < nums2[j - 1]) {
                // nums1的start1到i-1的数字都要去掉
                return getKthSmallest(nums1, i, nums2, start2, k - (i - start1)); // 因为i不一定是k/2，还可能是nums1.length，所以不能直接减k/2
            } else {
                // 同理nums2
                return getKthSmallest(nums1, start1, nums2, j, k - (j - start2));
            }
        }

        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int n = nums1.length + nums2.length;
            if (n % 2 == 0) {
                // 总数为偶数中位数有两个，即第k个数和第k+1个数
                return (getKthSmallest(nums1, 0, nums2, 0, n / 2) +
                        getKthSmallest(nums1, 0, nums2, 0, n / 2 + 1)) / 2.0;
            } else {
                return getKthSmallest(nums1, 0, nums2, 0, n / 2 + 1);
            }
        }

    }
//leetcode submit region end(Prohibit modification and deletion)

}
