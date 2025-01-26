/* https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
329. Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path
in matrix.

From each cell, you can either move in four directions: left, right, up, or
down. You may not move diagonally or move outside the boundary (i.e.,
wrap-around is not allowed).



Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

*/

// at a particular cell, we can move in 4 direction
// path must be increasing
// so i.e. at a[i][j] select max of 4 direction
// keep cell of matrix as a node
// directed adge from x to y if x<y;x,y are adjacent
// find longest path in Directed Assymmetric Graph

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> indegree(m, vector<int>(n, 0));

    vector dir = {-1, 0, 1, 0, -1};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 4; k++) {
          int next_i = i + dir[k];
          int next_j = j + dir[k + 1];
          if (next_i >= 0 && next_j >= 0 && next_i < m && next_j < n &&
              matrix[next_i][next_j] > matrix[i][j]) {
            indegree[next_i][next_j]++;
          }
        }
      }
    }

    queue<pair<int, int>> Q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (indegree[i][j] == 0) {
          Q.push({i, j});
        }
      }
    }

    int maxlen = 0;

    while (!Q.empty()) {
      int size = Q.size();
      for (int i = 0; i < size; i++) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
          int nx = x + dir[k];
          int ny = y + dir[k + 1];
          if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
              matrix[nx][ny] > matrix[x][y]) {
            indegree[nx][ny]--;
            if (indegree[nx][ny] == 0) {
              Q.push({nx, ny});
            }
          }
        }
      }
      maxlen++;
    }

    return maxlen;
  }
};

// sub:
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/1520811073/
// sol:
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/solutions/6332134/329-longest-increasing-path-in-a-matrix7-xxj0/
