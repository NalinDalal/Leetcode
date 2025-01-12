/* 3417. Zigzag Grid Traversal With Skip
Solved
Easy
Companies
You are given an m x n 2D array grid of positive integers.

Your task is to traverse grid in a zigzag pattern while skipping every alternate
cell.

Zigzag pattern traversal is defined as following the below actions:

Start at the top-left cell (0, 0).
Move right within a row until the end of the row is reached.
Drop down to the next row, then traverse left until the beginning of the row is
reached. Continue alternating between right and left traversal until every row
has been traversed. Note that you must skip every alternate cell during the
traversal.

Return an array of integers result containing, in order, the value of the cells
visited during the zigzag traversal with skips.



Example 1:

Input: grid = [[1,2],[3,4]]

Output: [1,4]

Explanation:



Example 2:

Input: grid = [[2,1],[2,1],[2,1]]

Output: [2,1,2]

Explanation:



Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]

Output: [1,3,5,7,9]

Explanation:





Constraints:

2 <= n == grid.length <= 50
2 <= m == grid[i].length <= 50
1 <= grid[i][j] <= 2500
*/

// # Approach
/*task is to traverse grid in zigzag pattern while skipping every alternate cell
so do like skip every alt cell and then while moving to next row
if i%2=0 then left to right
else right to left also
if j%2!=0 skip
else add to result*/

class Solution {
public:
  vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    vector<int> result;
    int n = grid.size(); // Number of rows
    if (n == 0)
      return result;
    int m = grid[0].size(); // Number of columns

    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) { // Left to right
        for (int j = 0; j < m; ++j) {
          if (j % 2 == 0) { // Include only even-indexed cells
            result.push_back(grid[i][j]);
          }
        }
      } else { // Right to left
        for (int j = m - 1; j >= 0; --j) {
          if (j % 2 != 0) { // Include only even-indexed cells
            result.push_back(grid[i][j]);
          }
        }
      }
    }

    return result;
  }
};

// Time : O(n^2)
// Space: O(1)
// sol:
// https://leetcode.com/problems/zigzag-grid-traversal-with-skip/solutions/6267543/3417-zigzag-grid-traversal-with-skip40-b-9vq0/
// sub:
// https://leetcode.com/problems/zigzag-grid-traversal-with-skip/submissions/1505784887/
