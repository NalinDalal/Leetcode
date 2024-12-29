/* 3402. Minimum Operations to Make Columns Strictly Increasing
User Accepted:13236
User Tried:13612
Total Accepted:13980
Total Submissions:19374
Difficulty:Easy
You are given a m x n matrix grid consisting of non-negative integers.

In one operation, you can increment the value of any grid[i][j] by 1.

Return the minimum number of operations needed to make all columns of grid
strictly increasing.



Example 1:

Input: grid = [[3,2],[1,3],[3,4],[0,1]]

Output: 15

Explanation:

To make the 0th column strictly increasing, we can apply 3 operations on
grid[1][0], 2 operations on grid[2][0], and 6 operations on grid[3][0]. To make
the 1st column strictly increasing, we can apply 4 operations on grid[3][1].

Example 2:

Input: grid = [[3,2,1],[2,1,0],[1,2,3]]

Output: 12

Explanation:

To make the 0th column strictly increasing, we can apply 2 operations on
grid[1][0], and 4 operations on grid[2][0]. To make the 1st column strictly
increasing, we can apply 2 operations on grid[1][1], and 2 operations on
grid[2][1]. To make the 2nd column strictly increasing, we can apply 2
operations on grid[1][2].



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
0 <= grid[i][j] < 2500*/

class Solution {
public:
  int minimumOperations(vector<vector<int>>& grid) {
    // given a 2d array of m*n size
    //  1 opr=grid[i][j]++
    // return min opr; make column of grid strictly increasing
    // for say ith column->
    // check i with i+1 and update i+1 by abs(arr[i+1]-arr[i])+1
    // continue till last, increase count at each iteration
    // return count
    int m = grid.size();    // Number of rows
    int n = grid[0].size(); // Number of columns
    int operations = 0;

    // Process each column
    for (int col = 0; col < n; ++col) {
      for (int row = 0; row < m - 1; ++row) {
        // If current element is not less than the next element
        if (grid[row][col] >= grid[row + 1][col]) {
          int increment = grid[row][col] - grid[row + 1][col] + 1;
          grid[row + 1][col] += increment;
          operations += increment;
        }
      }
    }

    return operations;
  }
};

// 100%
// O(n^2)
// O(1)
// Solution:
// https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/solutions/6199588/3402-minimum-operations-to-make-columns-yq8fk/
// Submission:
// https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/submissions/1491138516/
