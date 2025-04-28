//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 数组 回溯 排序 👍 1681 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//Java：全排列 II
public class P47PermutationsIi {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P47PermutationsIi().new Solution();
        System.out.println(solution.permuteUnique(new int[]{1, 1, 3}));
        System.out.println(solution.permuteUnique(new int[]{1, 2, 3}));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private List<List<Integer>> result = new ArrayList<>();

        private void dfs(int[] nums, boolean[] visited, List<Integer> temp) {
            if (temp.size() == nums.length) {
                result.add(new ArrayList<>(temp));
                return;
            }
            for (int i = 0; i < nums.length; i++) {
                // 相比[46]全排列仅多了下面一行判断分支
                // 假设三个位置，第二第三相同，按顺序选出第一个结果后回溯到vis为 true false false 的情况
                // 正常情况下是准备选 一 三 二 的顺序的，但是这里判断到二和三相同，且二的位置为false，则要跳过这种情况，即二三交换的情况
                // （两个位置的情况想一下也一样，这里的一可以忽略，这里举例说三个位置是为了普遍情况）
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                if (!visited[i]) {
                    visited[i] = true;
                    temp.add(nums[i]);
                    dfs(nums, visited, temp);
                    temp.removeLast();
                    visited[i] = false;
                }
            }
        }

        public List<List<Integer>> permuteUnique(int[] nums) {
            Arrays.sort(nums);
            dfs(nums, new boolean[nums.length], new ArrayList<>());
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
