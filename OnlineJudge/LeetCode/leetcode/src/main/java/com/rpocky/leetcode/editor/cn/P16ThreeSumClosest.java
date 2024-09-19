//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。 
//
// 返回这三个数的和。 
//
// 假定每组输入只存在恰好一个解。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,0,0], target = 1
//输出：0
//解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 1000 
// -1000 <= nums[i] <= 1000 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics 数组 双指针 排序 👍 1646 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.Arrays;

//Java：最接近的三数之和
public class P16ThreeSumClosest {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P16ThreeSumClosest().new Solution();
        System.out.println(solution.threeSumClosest(new int[]{0, 0, 0, 0}, 1));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int threeSumClosest(int[] nums, int target) {
            Arrays.sort(nums);
            int result = Integer.MAX_VALUE; // -10^4 <= target <= 10^4，取一个和target差比较大的，后面肯定会更新
            for (int i = 0; i < nums.length - 2; i++) {
                int left = i + 1, right = nums.length - 1;
                if (i > 0 && nums[i] == nums[i - 1]) continue; // 去除重复计算
                // 剪枝
                // 加上最小的两个数字还是大于目标值则不用再计算后面的了，肯定这个局部最优
                if (nums[i] + nums[left] + nums[left + 1] > target) {
                    // 更新数据
                    if (Math.abs(nums[i] + nums[left] + nums[left + 1] - target) < Math.abs(result - target)) {
                        result = nums[i] + nums[left] + nums[left + 1];
                    }
                    continue;
                }
                // 加上最大的两个数字还是小于目标值则不用再计算后面的了，肯定这个局部最优
                if (nums[i] + nums[right] + nums[right - 1] < target) {
                    // 更新数据
                    if (Math.abs(nums[i] + nums[right] + nums[right - 1] - target) < Math.abs(result - target)) {
                        result = nums[i] + nums[right] + nums[right - 1];
                    }
                    continue;
                }
                while (left < right) {
                    // 更新数据
                    if (Math.abs(nums[i] + nums[left] + nums[right] - target) < Math.abs(result - target)) {
                        result = nums[i] + nums[left] + nums[right];
                    }
                    if (nums[i] + nums[left] + nums[right] == target) {
                        // 直接等于target就是target，上面的if里 result=target
                        return result;
                    } else if (nums[i] + nums[left] + nums[right] < target) {
                        // 左指针右移，同时去重
                        do left++;
                        while (left < right && nums[left] == nums[left - 1]);
                    } else {
                        // 右指针左移，同时去重
                        do right--;
                        while (left < right && nums[right] == nums[right + 1]);
                    }
                }
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
