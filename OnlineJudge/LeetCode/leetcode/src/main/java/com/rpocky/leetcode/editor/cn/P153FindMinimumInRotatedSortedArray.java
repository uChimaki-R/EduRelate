//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变
//化后可能得到：
//
// 
// 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2] 
// 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7] 
// 
//
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], 
//..., a[n-2]] 。 
//
// 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。 
//
// 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,4,5,1,2]
//输出：1
//解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,5,6,7,0,1,2]
//输出：0
//解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
// 
//
// 示例 3： 
//
// 
//输入：nums = [11,13,15,17]
//输出：11
//解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 5000 
// -5000 <= nums[i] <= 5000 
// nums 中的所有整数 互不相同 
// nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转 
// 
//
// Related Topics 数组 二分查找 👍 1215 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：寻找旋转排序数组中的最小值
public class P153FindMinimumInRotatedSortedArray {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P153FindMinimumInRotatedSortedArray().new Solution();
        int[] nums = new int[]{2, 1};
        System.out.println(solution.findMin(nums));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // nums只有两种可能性：
        // 1、整体为升序，即旋转之后还是和原来一样
        // 2、两段升序，且前一段升序最左侧的最小值大于后一段升序最右侧的最大值（图像类似二四象限对称的两道 / ）
        // 而且每次二分之后也依旧满足是上面两种情况中的其中一种
        public int findMin(int[] nums) {
            int left = 0, right = nums.length - 1;
            int result = nums[left]; // 用数组中的元素初始化就不用Integer.MAX_VALUE这种
            while (left <= right) {
                int mid = left + (right - left + 1) / 2; // 向上取整，避免mid和left是同一个
                // 比较中间值和左边的值
                if (nums[left] < nums[mid]) {
                    // 左边的值小于中间的值
                    // 在情况1中，明显最小值就是最左边那个，但是还要考虑情况2
                    // 在情况2中，因为有右边那个比较低的升序序列，最小值显然在右侧
                    // 综合两种情况，可以选择先用left的值更新最小值满足情况1，然后去右侧继续二分满足情况2
                    result = Math.min(result, nums[left]);
                    left = mid + 1;
                } else {
                    // nums[left] > nums[mid]
                    // 因为元素互不相同，所以这里只可能是左边大于右边
                    // 这种情况下不可能是情况1，只考虑情况2
                    // 情况2下，显然mid处于右侧升序的中间部分，所以mid右侧都是大于最小值的，可以排除
                    // 当然mid的位置可能不是中间而是最左边的最小值，可以尝试更新一下
                    result = Math.min(result, nums[mid]);
                    right = mid - 1;
                }
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
