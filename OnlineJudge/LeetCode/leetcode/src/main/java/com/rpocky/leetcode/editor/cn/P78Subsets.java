//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
// nums 中的所有元素 互不相同 
// 
//
// Related Topics 位运算 数组 回溯 👍 2450 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.List;

//Java：子集
public class P78Subsets {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P78Subsets().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private boolean[] visited;
        List<List<Integer>> result;

        // 不能重复(如[1, 2], [2, 1])，所以用pos限制不能选前面的
        private void dfs(int[] nums, int pos, int count, List<Integer> chosen) {
            if (count == 0) {
                result.add(new ArrayList<>(chosen));
                return;
            }
            for (int i = pos; i < nums.length; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    chosen.add(nums[i]);
                    dfs(nums, i + 1, count - 1, chosen);
                    visited[i] = false;
                    chosen.removeLast();
                }
            }
        }

        public List<List<Integer>> subsets(int[] nums) {
            visited = new boolean[nums.length];
            result = new ArrayList<>();
            for (int count = 0; count <= nums.length; count++) {
                dfs(nums, 0, count, new ArrayList<>());
            }
            return result;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
