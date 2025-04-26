//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 位运算 数组 回溯 👍 1304 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//Java：子集 II
public class P90SubsetsIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P90SubsetsIi().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            // 先进行排序，方便去重
            Arrays.sort(nums);
            dfs(0, nums);
            return res;
        }

        public void dfs(int start, int[] nums) {
            // 在每次递归的时候加入即可
            res.add(new ArrayList<>(path));
            for (int i = start; i < nums.length; ++i) {
                // 去重
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                path.add(nums[i]);
                dfs(i + 1, nums);
                path.removeLast();
            }
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
