/* https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

2661. First Completely Painted Row or Column

You are given a 0-indexed integer array arr, and an m x n integer matrix mat.
arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat
containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely
painted in mat.



Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second
column of the matrix become fully painted at arr[2]. Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].


Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.*/

// colour the 2d array mat as per array arr
// if at ith index either a row or column get fully painted
// return the ith index

#include <vector>
using namespace std;

// track the painting progress of each row and column efficiently by using a
// hashmap to store positions and counter arrays.

// Approach:
/*1. Create a hashmap to store positions of numbers in matrix
2. Use two arrays to count painted cells in each row and column
3. For each number in arr:
    - Get its position from hashmap
    - Increment row and column counts
    - Check if any row or column is complete*/
class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    unordered_map<int, pair<int, int>> pos;

    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        pos[mat[i][j]] = {i, j};

    vector<int> rCnt(row, 0);
    vector<int> cCnt(col, 0);

    for (int i = 0; i < arr.size(); i++) {
      auto [r, c] = pos[arr[i]];
      rCnt[r]++;
      cCnt[c]++;
      if (rCnt[r] == col || cCnt[c] == row)
        return i;
    }
    return arr.size() - 1;
  }
};

// Time Complexity:O(m*n)
// Space Complexity: O(m*n)
// 51.22%
// sub:
// https://leetcode.com/problems/first-completely-painted-row-or-column/submissions/1514809313/?envType=daily-question&envId=2025-01-20

// 100%
class Solution1 {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

    int m = mat.size(), n = mat[0].size();

    vector<pair<int, int>> num_to_coordinates(m * n);
    for (int r = 0; r < m; r++)
      for (int c = 0; c < n; c++)
        num_to_coordinates[mat[r][c] - 1] = make_pair(r, c);

    vector<int> row_tally(m, 0);
    vector<int> col_tally(n, 0);

    for (int i = 0; i < arr.size(); i++) {
      auto& [r, c] = num_to_coordinates[arr[i] - 1];
      if (++row_tally[r] == n || ++col_tally[c] == m)
        return i;
    }

    return arr.size();
  }
};
// sub:
// https://leetcode.com/problems/first-completely-painted-row-or-column/submissions/1514810834/?envType=daily-question&envId=2025-01-20
// sol:
// https://leetcode.com/problems/first-completely-painted-row-or-column/solutions/6307553/2661-first-completely-painted-row-or-col-471u/
