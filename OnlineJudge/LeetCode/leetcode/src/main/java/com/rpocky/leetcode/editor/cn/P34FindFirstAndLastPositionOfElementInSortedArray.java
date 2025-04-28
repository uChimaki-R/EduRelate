//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums 是一个非递减数组 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 二分查找 👍 2794 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Arrays;

//Java：在排序数组中查找元素的第一个和最后一个位置
public class P34FindFirstAndLastPositionOfElementInSortedArray {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P34FindFirstAndLastPositionOfElementInSortedArray().new Solution();
        Arrays.stream(solution.searchRange(new int[]{5,7,7,8,8,10}, 7)).forEach(System.out::println);
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        int find(int[] nums, int target, int left, int right, boolean isLeftIndex) {
            // 二分找这个数字
            int mid = left;
            boolean found = false;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    found = true;
                    break;
                }
                if (nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
            // 找不到就返回-1
            if (!found) return -1;
            // 找到了就看想找最左边的这个数字还是右边的
            if (isLeftIndex) {
                // 找左边的就在左侧接着找，找到就返回找到的（会更边界），否则返回前面找到的位置mid
                int temp = find(nums, target, left, mid - 1, isLeftIndex);
                if (temp != -1) return temp;
                else return mid;
            } else {
                // 找右边的就在右侧接着找，找到就返回找到的（会更边界），否则返回前面找到的位置mid
                int temp = find(nums, target, mid + 1, right, isLeftIndex);
                if (temp != -1) return temp;
                else return mid;
            }
        }

        public int[] searchRange(int[] nums, int target) {
            int left = 0, right = nums.length - 1;
            return new int[]{find(nums, target, left, right, true), find(nums, target, left, right, false)};
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
