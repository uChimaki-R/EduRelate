//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。 请你实现时间复杂度为 
//O(n) 并且只使用常数级别额外空间的解决方案。
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,0]
//输出：3
//解释：范围 [1,2] 中的数字都在数组中。 
//
// 示例 2： 
//
// 
//输入：nums = [3,4,-1,1]
//输出：2
//解释：1 在数组中，但 2 没有。 
//
// 示例 3： 
//
// 
//输入：nums = [7,8,9,11,12]
//输出：1
//解释：最小的正数 1 没有出现。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// Related Topics 数组 哈希表 👍 2295 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：缺失的第一个正数
public class P41FirstMissingPositive {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P41FirstMissingPositive().new Solution();
        int[] nums = {1, 1};
        System.out.println(solution.firstMissingPositive(nums));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        public int firstMissingPositive(int[] nums) {
            // （难点在于原地解决问题）
            // 结果的最大值是 nums.length+1
            // 在这个极端情况下，每个下标都放了 下标+1 这个数字，把最小的那些正整数都用了
            // 所以遍历nums的时候，将在[1, length]区间的数num[i]，放到下标i-1处，即先让这些小数字占座
            // 之后再次从头到尾遍历，第一次出现下标 i!=num[i]-1 时，即i+1这个小数字nums没有包含，返回这个数即是答案
            // 遍历发现都符合说明nums是上述的极端情况，此时返回 length+1
            int length = nums.length;
            for (int i = 0; i < length; i++) {
                while (nums[i] >= 1 && nums[i] <= length && i != nums[i] - 1) {
                    // 不符合摆放规则，换到符合规则的 nums[i]-1 下标
                    if (nums[i] == nums[nums[i] - 1]) break; // 如果两者一样，说明要换过去的下标 nums[i]-1 上的数字已经是合理数字了，说明给了重复的数字，如[1, 1]，没有这个判断条件的话第二个1会死循环（换回来还是1，还是满足while条件）
                    swap(nums, i, nums[i] - 1);
                    // 使用if只判断一次是不行的，换过来i下标的数字也可能不符合规则，要while一直换
                }
            }
            for (int i = 0; i < length; i++) {
                if (nums[i] - 1 != i) return i + 1;
            }
            return length + 1;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
