//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
//
// Related Topics 栈 数组 单调栈 👍 2885 👎 0

package com.rpocky.leetcode.editor.cn;

import java.util.ArrayDeque;
import java.util.Deque;

//Java：柱状图中最大的矩形
public class P84LargestRectangleInHistogram {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P84LargestRectangleInHistogram().new Solution();
//        int[] nums = new int[]{2, 1, 5, 6, 2, 3};
        int[] nums = new int[]{2, 4};
        System.out.println(solution.largestRectangleArea(nums));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
//        // 超时
//        // 遍历每个柱子，左右拓展直到遇到第一个小于自己的柱子，计算宽度
//        public int largestRectangleArea(int[] heights) {
//            int maxArea = 0;
//            for (int i = 0; i < heights.length; i++) {
//                int height = heights[i];
//                int width = 1;
//                int pos = i - 1;
//                while (pos >= 0 && heights[pos] >= height) {
//                    pos--;
//                    width++;
//                }
//                pos = i + 1;
//                while (pos < heights.length && heights[pos] >= height) {
//                    pos++;
//                    width++;
//                }
//                maxArea = Math.max(maxArea, width * height);
//            }
//            return maxArea;
//        }

        // 使用单调栈
        // 因为每个柱子左右延伸的极限取决于左右第一个小于自己的柱子
        // 所以使用单调栈，每次保证栈中单调递增
        //
        // 对于每个元素，当发现小于栈顶的元素时，说明能够确定此时栈中所有比当前柱子高的柱子的右边界（换句话说，递增的栈中所有比当前柱子高的找到了右边第一个比自己矮的）
        // 所以一直弹出栈中元素，直到栈空或者小于当前元素，对于这些元素，都能够知道他们的右边界就是当前元素i下标-1
        // 而当前元素也就知道了自己的左边界，就是此时栈中剩下的第一个小于自己的元素的下标，所以能够知道当前元素的左边界
        //
        // 由此可见，元素入栈，能够知道自己左边界，元素出栈，能够知道自己右边界，面积在出栈时可以计算出来
        //
        // 接着考虑特殊情况，就是栈空的情况，这里可以安排哨兵，也就是假设-1下标有个高度为0的柱子
        // 这样栈中元素进来时能够按同样的逻辑确定左边界而不用判断栈是否为空
        //
        // 接着考虑连续入栈的相同高度的柱子（考虑到单调栈，实际上二者下标不一定是连续的）
        // 应该把后一个柱子当作小于前一个柱子来处理，这样前一个相同柱子就会走计算的逻辑，虽然这个不是他左右延申的极限
        // 但是后来的这个相同柱子（当前柱子）会替代他的位置，和他记录到相同的左边界，不会影响自己的计算（相同高度，记录了相同左边界，肯定是右侧这个计算出来的结果大）
        // 假设当作大于钱一个柱子而不进行弹出操作，会把后面这个柱子（当前柱子）的左边界设定为自己（因为认为左边比较小），从而导致错误
        //
        // 接着考虑到最后对栈中剩余内容的处理，可以用右哨兵，通过加入一个高度为0的柱子，这样肯定会把所有内容（包括左哨兵）全部弹出（左哨兵高度和右哨兵高度相同，为0，结合前面的讨论，会弹出）
        // 从而一次遍历计算了所有可能
        public int largestRectangleArea(int[] heights) {
            // 栈用数组存三个内容：柱子高度、柱子所在下标、该柱子的左延申边界下标
            Deque<int[]> stack = new ArrayDeque<>();
            // 加入左哨兵
            int[] leftPoint = new int[]{0, -1, -1};
            stack.push(leftPoint);
            // 加入右哨兵，需要创建新数组
            int[] newHeights = new int[heights.length + 1];
            System.arraycopy(heights, 0, newHeights, 0, heights.length);
            newHeights[newHeights.length - 1] = 0;
            // 引用直接修改
            heights = newHeights;
            int ans = 0;
            for (int i = 0; i < heights.length; i++) {
                // 对于每个柱子，执行上述逻辑，保证栈中单调
                // 由于加入了哨兵，不用判断非空
                int[] back = stack.peek();
                int height = back[0], index = back[1], left = back[2];
                if (heights[i] > height) {
                    // 高过栈顶柱子，直接加入，可以保持单调
                    // 左边界是这个栈顶元素，因为他是左侧第一个小于自己的
                    stack.push(new int[]{heights[i], i, index});
                } else {
                    // 比自己小或者等于自己，都要进行弹出计算，直到遇到比自己小的
                    while (heights[i] <= height) {
                        // 弹出
                        stack.pop();
                        // 因为右哨兵的存在，会把栈弄空，这里需要跳出（或者直接return也许）
                        if (stack.isEmpty()) break;
                        // 自己的下标就是他们的右边界
                        int width = (index - left - 1) + (i - index - 1) + 1; // +1是柱子本身
                        ans = Math.max(ans, width * height);
                        // 继续peek下一个元素判断
                        back = stack.peek();
                        height = back[0];
                        index = back[1];
                        left = back[2];
                    }
                    // 此时栈中剩下的就是比自己小的，他的下标就是自己的左边界
                    // 把自己存入
                    stack.push(new int[]{heights[i], i, index});
                }
            }
            return ans;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
