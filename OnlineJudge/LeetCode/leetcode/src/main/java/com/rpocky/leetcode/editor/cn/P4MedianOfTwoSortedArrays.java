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
//        /**
//         * 在两个有序数组中找第k小的数字
//         */
//        private int getKthSmallest(int[] nums1, int start1, int[] nums2, int start2, int k) {
//            // 确保nums1是较短的数组
//            if (nums1.length - start1 > nums2.length - start2) {
//                return getKthSmallest(nums2, start2, nums1, start1, k);
//            }
//            // nums1数组为空，直接返回nums2的第k个数字
//            if (nums1.length == start1) return nums2[start2 + k - 1];
//            // 如果k为1就返回两个数组第一个下标下数字较小的那个
//            if (k == 1) return Math.min(nums1[start1], nums2[start2]);
//            // 比较第k/2个位置的数字
//            // 因为num1比较短，k/2可能会越界，需要和长度取min
//            int i = Math.min(nums1.length, start1 + k / 2);
//            int j = start2 + k - k / 2; // num1取k/2，num2就要取k-k/2，因为k有奇偶数之分，所以需要用减法确保相加为k
//            if (nums1[i - 1] < nums2[j - 1]) {
//                // nums1的start1到i-1的数字都要去掉
//                return getKthSmallest(nums1, i, nums2, start2, k - (i - start1)); // 因为i不一定是k/2，还可能是nums1.length，所以不能直接减k/2
//            } else {
//                // 同理nums2
//                return getKthSmallest(nums1, start1, nums2, j, k - (j - start2));
//            }
//        }
//
//        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
//            int n = nums1.length + nums2.length;
//            if (n % 2 == 0) {
//                // 总数为偶数中位数有两个，即第k个数和第k+1个数
//                return (getKthSmallest(nums1, 0, nums2, 0, n / 2) +
//                        getKthSmallest(nums1, 0, nums2, 0, n / 2 + 1)) / 2.0;
//            } else {
//                return getKthSmallest(nums1, 0, nums2, 0, n / 2 + 1);
//            }
//        }

        // 在两个有序数组A、B中取中位数，也就是要在两个数组中找到边界i和j （i、j是数组中的空隙，比如说数组开头的空隙i=0）
        // 使得 A中i左侧的数个数+B中j左侧的数的个数 = A中i右侧中的数个数+B中j右侧数的个数 （奇数情况下左侧会多一个数） 并且左侧的数字全部小于右侧的数字
        // 可以归纳得知 i+j = (m+n+1)/2  （m+n/2 可以理解为总数的一半，就是中位数的定义，+1让奇偶数情况都成立）
        // 也就是说，只需要求出i，j就可以用减法得出来
        // 假设较短的数组为A，我们对数组A的i进行猜测，也就是进行二分
        // 我们需要二分出i的位置，但是i的位置是有条件的，需要满足「左侧的数字小于右侧的数字」
        // 这个条件需要用以下判断来满足：
        // 1. 因为两个数组有序，所以同一个数组内，比如说A中i左右两个数字已经满足了左边小于右边，B的j同理
        // 2. 所以只需要确保：
        //    1. A左侧边界的数小于B右侧边界的数
        //       不满足则说明A左侧的数大了，i需要左移（等价j右移），也就是把二分的右边界左移（右侧不可能）
        //    2. A右侧边界的数大于B左侧边界的数
        //       不满足则说明A右侧的数小了，i需要右移（等价j左移），也就是把二分的左边界右移（左侧不可能）
        // 如果满足了上述的条件，说明找到了正确的位置（check()成功），开始计算中位数：
        // 1. 偶数情况下，中位数为 (左侧最大值+右侧最小值)/2
        // 2. 奇数情况下，中位数为 左侧的最大值 （左边多一个）
        // 对于左右侧最值的计算，显然最值就出现在边界（i、j）上的那四个数字
        // 需要处理一下i==0，i==n，j==0，j==m的情况
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            return find(nums1, nums2);
        }

        private double find(int[] a, int[] b) {
            int n = a.length;
            int m = b.length;
            if (n > m) {
                // 确保a比较小，因为时间复杂度取决于a的长度 O(log(n))
                return find(b, a);
            }
            // 边界是间隙，所以到n
            int left = 0, right = n;
            while (left <= right) {
                int i = left + (right - left) / 2;
                // j可以直接计算出来
                int j = (m + n + 1) / 2 - i;
                // 判断划分是否合法，不合法需要二分
                // 注意边界值，除了!=0之外，因为i和j可以取到右边界，但是数组不能访问到右边界的值（右侧无值），需要!=右边界
                if (i != 0 && j != m && a[i - 1] > b[j]) {
                    // 左上大于右下，左侧大了，i偏右，舍弃右边
                    right = i - 1;
                } else if (j != 0 && i != n && b[j - 1] > a[i]) {
                    // 左下大于右上，右侧小了，i偏左，舍弃左边
                    left = i + 1;
                } else {
                    // 满足条件，是合理的划分，计算中位数
                    int leftMax;
                    if (i == 0) {
                        // 没有左上，那就只能取左下
                        leftMax = b[j - 1];
                    } else if (j == 0) {
                        // 没有左下，那就只能取左上
                        leftMax = a[i - 1];
                    } else {
                        // 都有就取最大值
                        leftMax = Math.max(a[i - 1], b[j - 1]);
                    }
                    // 奇数情况直接返回这个左侧最大值即可
                    if ((m + n) % 2 == 1) {
                        return leftMax;
                    }
                    // 偶数还要计算右侧最小值
                    int rightMin;
                    if (i == n) {
                        // 没有右上，只能右下
                        rightMin = b[j];
                    } else if (j == m) {
                        // 没有右下，只能右上
                        rightMin = a[i];
                    } else {
                        // 都有取最小
                        rightMin = Math.min(a[i], b[j]);
                    }
                    return (leftMax + rightMin) / 2.0;
                }
            }
            // 理论上不会到达这里
            return 0;
        }

    }
//leetcode submit region end(Prohibit modification and deletion)

}
