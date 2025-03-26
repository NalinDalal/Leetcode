/*2033. Minimum Operations to Make a Uni-Value Grid

You are given a 2D integer grid of size m x n and an integer x. In one
operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not
possible, return -1.



Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104
*/
/*
If all elements are to become the same, their differences must be multiples of
x. Hence need to have same remainder upon division with x. to minimize
operations is to make all values equal to the median of the sorted elements.
Convert each element to the median and count operations.
*/

class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> flat;
    for (const auto& row : grid) {
      for (int num : row) {
        flat.push_back(num);
      }
    }

    // Check if all elements have the same remainder when divided by x
    int remainder = flat[0] % x;
    for (int num : flat) {
      if (num % x != remainder)
        return -1;
    }

    // Find the median as target value
    sort(flat.begin(), flat.end());
    int median = flat[flat.size() / 2];

    // Calculate minimum operations
    int operations = 0;
    for (int num : flat) {
      operations += abs(num - median) / x;
    }

    return operations;
  }
};

// sub:https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1586293885/?envType=daily-question&envId=2025-03-26
// sol:
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/solutions/6579946/2033-minimum-operations-to-make-a-uni-va-yvuq/
