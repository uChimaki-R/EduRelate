//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != 
//k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 双指针 排序 👍 7036 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.*;

//Java：三数之和
public class P15ThreeSum {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P15ThreeSum().new Solution();
        System.out.println(solution.threeSum(new int[]{-4,-2,-1}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            // 先排序
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            // 对于每个数字，在右侧使用双指针
            for (int i = 0; i < nums.length - 2; i++) {
                // 最左侧的数字是最小的，因为要三个数的和为0，如果最小的数是正数则不可能
                if (nums[i] > 0) return result;
                if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重
                int left = i + 1, right = nums.length - 1;
                // 剪枝
                // 最小数两倍仍大于目标值则剪枝
                if (nums[i] + nums[left] * 2 > 0) continue;
                // 最大数两倍仍小于目标值则剪枝
                if (nums[i] + nums[right] * 2 < 0) continue;
                while (left < right) {
                    if (nums[i] + nums[left] == -nums[right]) {
                        result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                        // 去重
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (nums[i] + nums[left] > -nums[right]) {
                        // 相加大于0，右边要减少
                        right--;
                    } else {
                        left++;
                    }
                }
            }
            return result;

//            // 使用二分，先选两个数字，第三个数字二分
//            // 但是这个需要手动去重，因为里面的while循环没有套两个while
//            // 然而这个跑出来时间是上面的10倍
//            Set<List<Integer>> set = new HashSet<>();
//            for (int i = 0; i < nums.length; i++) {
//                // 最左侧的数字是最小的，因为要三个数的和为0，如果最小的数是正数则不可能
//                if (nums[i] > 0){
//                    return new ArrayList<>(set);
//                }
//                if (i > 0 && nums[i] == nums[i - 1]) continue;
//                for (int j = i + 1; j < nums.length; j++) {
//                    int left = j + 1;
//                    int right = nums.length - 1;
//                    while (left <= right) {
//                        int mid = (left + right) / 2;
//                        if (nums[i] + nums[j] == -nums[mid]) {
//                            set.add(Arrays.asList(nums[i], nums[j], nums[mid]));
//                            break;
//                        } else if (nums[i] + nums[j] > -nums[mid]) right = mid - 1;
//                        else left = mid + 1;
//                    }
//                }
//            }
//            return new ArrayList<>(set);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
