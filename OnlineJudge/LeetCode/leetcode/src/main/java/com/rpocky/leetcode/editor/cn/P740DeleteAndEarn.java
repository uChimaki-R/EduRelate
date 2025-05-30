//给你一个整数数组 nums ，你可以对它进行一些操作。 
//
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i]
// + 1 的元素。 
//
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,4,2]
//输出：6
//解释：
//删除 4 获得 4 个点数，因此 3 也被删除。
//之后，删除 2 获得 2 个点数。总共获得 6 个点数。
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,3,3,3,4]
//输出：9
//解释：
//删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
//之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
//总共获得 9 个点数。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// 1 <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 哈希表 动态规划 👍 1113 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：删除并获得点数
public class P740DeleteAndEarn {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P740DeleteAndEarn().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        /**
         * 选了nums[i]后，nums[i]-1和nums[i]+1都不能选了
         * 这和小偷dp的 偷了这一家，周围两家都不能偷了是类似的
         * 于是我们可以把nums[i]转化为下标，即下标从0到max(nums[i])
         * 偷了下标为nums[i]的东西后，下标nums[i]-1和nums[i]+1都不能偷了
         * 那么每个下标偷的价值是多少呢？
         * 事实上选了nums[i]，所有的nums[i]都可以被选，因为nums[i]-1和nums[i]+1都不能选了，那么其他的nums[i]都可以累计进来
         * 于是每个下标偷的价值就是所有等于这个下标的nums[i]的总和
         */
        public int deleteAndEarn(int[] nums) {
            // 因为要知道数组长度，需要知道max(nums[i])
            int length = 0;
            for (int num : nums) {
                length = Math.max(length, num);
            }
            int[] values = new int[length + 1];
            for (int num : nums) {
                values[num] += num;
            }
            // 小偷dp
            // 头部补充两个空位方便迭代
            int[] dp = new int[2 + length + 1];
            for (int i = 2; i < dp.length; i++) {
                // 因为填了两个空位，values下标要-2
                dp[i] = Math.max(dp[i - 2] + values[i - 2], dp[i - 1]);
            }
            return dp[dp.length - 1];
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
