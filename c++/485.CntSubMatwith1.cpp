/*1504. Count Submatrices With All Ones
Given an m x n binary matrix mat, return the number of submatrices that have all
ones.


Example 1:
Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:
Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.


Constraints:
1 <= m, n <= 150
mat[i][j] is either 0 or 1.

Hint 1
For each row i, create an array nums where: if mat[i][j] == 0 then nums[j] = 0
else nums[j] = nums[j-1] +1. Hint 2 In the row i, number of rectangles between
column j and k(inclusive) and ends in row i, is equal to SUM(min(nums[j, ..
idx])) where idx go from j to k. Expected solution is O(n^3).
*/

/* 1. build heights:
    - For each row, we treat it as the base of possible submatrices.
    - Define height[j] = number of consecutive 1s above (and including) the
current row at column j.
```
mat = [[1,0,1],
       [1,1,0],
       [1,1,0]]
```
Row 0 → heights = `[1,0,1]`
Row 1 → heights = `[2,1,0]`
Row 2 → heights = `[3,2,0]`

2. count rectangles
For each row’s `height[]`, we need to count how many submatrices end at this
row.

Trick: For every column j, expand leftwards, keep track of the minimum height,
and accumulate counts.
```
countRow(i):
    total = 0
    for j in [0..n-1]:
        minHeight = ∞
        for k in [j..0]:
            minHeight = min(minHeight, height[k])
            total += minHeight
```

This works because:
    - `minHeight` ensures the rectangle formed from `k..j` has all ones up to
current row.
    - Adding `minHeight` counts all valid submatrices ending at row `i` and
spanning columns `k..j`.
*/

class Solution {
public:
  int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> height(n, 0);
    int result = 0;

    for (int i = 0; i < m; i++) {
      // update heights
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          height[j] = 0;
        else
          height[j] += 1;
      }

      // count rectangles ending at this row
      for (int j = 0; j < n; j++) {
        int minHeight = height[j];
        for (int k = j; k >= 0; k--) {
          minHeight = min(minHeight, height[k]);
          if (minHeight == 0)
            break; // optimization
          result += minHeight;
        }
      }
    }

    return result;
  }
};

// sub:
// https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/1742684164/?envType=daily-question&envId=2025-08-21
// sol:
// https://leetcode.com/problems/count-submatrices-with-all-ones/solutions/7104935/1504-count-submatrices-with-all-ones-by-10iv1/
