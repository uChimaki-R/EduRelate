//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
// 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。 
//
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
//
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。 
//
// 
//
// 示例 1： 
//
// 
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。 
//
// 示例 2： 
//
// 
//输入: candidates = [2,3,5], target = 8
//输出: [[2,2,2,2],[2,3,3],[3,5]] 
//
// 示例 3： 
//
// 
//输入: candidates = [2], target = 1
//输出: []
// 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 2 <= candidates[i] <= 40 
// candidates 的所有元素 互不相同 
// 1 <= target <= 40 
// 
//
// Related Topics 数组 回溯 👍 2948 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.*;

//Java：组合总和
public class P39CombinationSum {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P39CombinationSum().new Solution();
        System.out.println(solution.combinationSum(new int[]{2}, 1));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private final List<List<Integer>> listSet = new ArrayList<>();
        private final List<Integer> chosen = new ArrayList<>();
        private int[] candidates;

        /**
         * @param pos    当前可以从candidates的pos位置向后选取数字，该参数是为了排除重复解
         * @param target 每次递归的target是除去chosen中选择的数字后，新的target
         */
        private void combination(int pos, int target) {
            if (target < 0) return;
            if (target == 0) {
                // 递归终点其一，选取的数和是最初的target
                listSet.add(new ArrayList<>(chosen));
                return;
            }
            // 从pos开始遍历回溯选取数字
            for (int i = pos; i < candidates.length; i++) {
                chosen.add(candidates[i]);
                combination(i, target - candidates[i]); // 可以重复选，所以还是从i开始选
                chosen.removeLast();
            }
        }

        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            this.candidates = candidates;
            // 排序可以去除递归中target<0的部分，因为加上最小的都超过target了，后续的就不可能为解
            Arrays.sort(candidates);
            combination(0, target);
            return new ArrayList<>(listSet);
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
