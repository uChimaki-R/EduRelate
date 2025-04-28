//整数数组的一个 排列 就是将其所有成员以序列或线性顺序排列。 
//
// 
// 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。 
// 
//
// 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就
//是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。 
//
// 
// 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。 
// 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。 
// 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。 
// 
//
// 给你一个整数数组 nums ，找出 nums 的下一个排列。 
//
// 必须 原地 修改，只允许使用额外常数空间。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[1,2,3]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1,5]
//输出：[1,5,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
//
// Related Topics 数组 双指针 👍 2564 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：下一个排列
public class P31NextPermutation {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P31NextPermutation().new Solution();
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        private void swap(int[] arr, int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        public void nextPermutation(int[] nums) {
            // 第一想法是在数组的右侧部分操作，使得右边某个数值大一点的数和左边某个数值小一点的数交换
            // 这样肯定是大于nums序列的，再将交换后左边数的下一个位置到结尾修改为降序，此时就能更接近nums序列的下一个序列
            // 于是要求：1. 第一步选的左边的数字尽量靠右，这通过从右向左遍历满足
            //         2. 第一步选的右边的数字数值尽量小（但是不能够小于选择的左边的数）
            // 所以可以通过从右向左遍历，寻找第一个相邻的左数<右数的数字（右侧降序的高峰处），此时确定左数（降序前的第一个数）
            // 再次从右向左查找，找到第一个右数满足 选定的左数<右数，此时确定右数，交换，并将后面的数字逆序即可（右侧是降序，逆序即升序，保证序列最小，最接近nums的下一个序列）
            // 当没能找到第一个左数<右数的数字，即数组为降序数组时，会将数组逆序，成为升序数组，也满足题目要求
            if (nums.length < 2) {
                return;
            }
            if (nums.length == 2) {
                swap(nums, 0, 1);
                return;
            }
            int left = nums.length - 2, right = nums.length - 1;
            // 找到右侧降序的高峰位置，确定左侧的数
            while (left >= 0 && nums[left] >= nums[right]) {
                left--;
                right--;
            }
            if (left != -1) {
                // 找到了左侧的数，开始找右侧的数（第一个大于选好的左侧的数，确保数值尽量小）
                int leftNum = nums[left];
                right = nums.length - 1;
                while (right > 0 && nums[right] <= leftNum) {
                    right--;
                }
                // 交换两者
                swap(nums, left, right);
            }
            // 将后面的降序序列改为升序（直接两两交换即可）
            int l = left + 1;
            int r = nums.length - 1;
            while (l < r) {
                swap(nums, l, r);
                l++;
                r--;
            }
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
