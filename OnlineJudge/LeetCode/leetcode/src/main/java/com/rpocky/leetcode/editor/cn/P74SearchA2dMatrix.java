//给你一个满足下述两条属性的 m x n 整数矩阵： 
//
// 
// 每行中的整数从左到右按非严格递增顺序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -10⁴ <= matrix[i][j], target <= 10⁴ 
// 
//
// Related Topics 数组 二分查找 矩阵 👍 1025 👎 0

package com.rpocky.leetcode.editor.cn;

//Java：搜索二维矩阵
public class P74SearchA2dMatrix {
    public static void main(String[] args) {
        // TO TEST
        Solution solution = new P74SearchA2dMatrix().new Solution();
        int[][] matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        System.out.println(solution.searchMatrix(matrix, 13));
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        // 直观的想法就是两次二分，先行二分找到所在的行，再列二分找到行中的值
        public boolean searchMatrix(int[][] matrix, int target) {
            int n = matrix.length, m = matrix[0].length;
            // 行二分
            for (int i = 0; i < n; i++) {
                // 行遍历第一列，目标是：找到最后一个不大于目标值的元素
                // 所以二分里left更新为mid而不是mid+1，left是最后进入那个if里的mid
                // mid也不是二者/2，而是要+1/2，否则会因为left不移动而死循环
                int left = 0, right = n - 1;
                while (left < right) {
                    int mid = (left + right + 1) / 2;
                    if (matrix[mid][0] <= target) {
                        left = mid;
                    } else {
                        right = mid - 1;
                    }
                }
                // 列二分就是正常二分找具体数字
                int l = 0, r = m - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (matrix[left][mid] == target) {
                        return true;
                    } else if (matrix[left][mid] > target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            return false;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
