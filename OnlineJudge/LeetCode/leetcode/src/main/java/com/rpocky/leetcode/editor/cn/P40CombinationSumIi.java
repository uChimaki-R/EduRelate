//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1616 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.*;

//Java：组合总和 II
public class P40CombinationSumIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P40CombinationSumIi().new Solution();
        System.out.println(solution.combinationSum2(new int[]{1}, 1));
//        System.out.println(solution.combinationSum2(new int[]{1, 2}, 4));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private final List<List<Integer>> result = new ArrayList<>();
        private final List<Integer> chosen = new ArrayList<>();
        private int[] nums;

        /**
         * @param pos    当前可以从candidates的pos位置向后选取数字，该参数是为了排除重复解
         * @param target 每次递归的target是除去chosen中选择的数字后，新的target
         */
        void combinationSum(int pos, int target) {
            if (target < 0) return;
            if (target == 0) {
                result.add(new ArrayList<>(chosen));
                return;
            }
            for (int i = pos; i < nums.length; i++) {
                // 如果本次递归中已经选取了 连续的相同数字 中的其中一个（事实上是第一个），则本次不需要再选这个数字了
                // 实际上选择一连串相同数字的情况会发生在很多次 递 的过程中，每次 递 就选一次该数字
                // 所以单次不能连续选一样的数字，会发生重复
                if (i > pos && nums[i] == nums[i - 1]) continue;
                chosen.addLast(nums[i]);
                combinationSum(i + 1, target - nums[i]);
                chosen.removeLast();
            }
        }

        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            this.nums = candidates;
            Arrays.sort(candidates);
            combinationSum(0, target);
            return new ArrayList<>(result);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
