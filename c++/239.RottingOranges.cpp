/* 994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten
orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh
orange. If this is impossible, return -1.



Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never
rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is
just 0.


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/

#include <iostream>
#include <vector>
using namespace std;

// 0 empty
// 1 fresh
// 2 rotten
// fresh if 4 directionally adjacent to rotten becomes rotten
// return -1 if impossible
// else return min minutes to rotten all

// so check 4 direction for each cell
// if all rot then return min minutes
// else return -1
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Directions for 4 possible movements (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> rottenQueue;
    int freshCount = 0;

    // Enqueue all initial rotten oranges and count fresh oranges
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2) {
          rottenQueue.push({i, j});
        } else if (grid[i][j] == 1) {
          ++freshCount;
        }
      }
    }

    int minutes = 0;

    while (!rottenQueue.empty() && freshCount > 0) {
      int queueSize = rottenQueue.size();
      for (int i = 0; i < queueSize; ++i) {
        auto [x, y] = rottenQueue.front();
        rottenQueue.pop();

        for (auto& dir : directions) {
          int nx = x + dir.first;
          int ny = y + dir.second;

          if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
            // Mark the fresh orange as rotten and push it to the queue
            grid[nx][ny] = 2;
            rottenQueue.push({nx, ny});
            --freshCount;
          }
        }
      }
      ++minutes;
    }

    // If there are still fresh oranges left, return -1 (impossible)
    return freshCount == 0 ? minutes : -1;
  }
};
// Time, Space: O(m*n)

int main() {
  vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  int testCase1 = 4;
  Solution obj;
  int ans1 = obj.orangesRotting(grid1);

  cout << "Case 1:" << endl;
  cout << "grid1: " << grid1 << endl;
  cout << "Expected: " << testCase1 << endl;
  cout << "Your ans:" << ans1 << endl;
  if (ans1 == testCase1) {
    cout << "Test Case 1 Passed" << endl;

  } else {
    cout << "Test Case 1 Failed" << endl;
  }
  return 0;
}

// Sub: https://leetcode.com/problems/rotting-oranges/submissions/1539340602/
// Sol:
// https://leetcode.com/problems/rotting-oranges/solutions/6408185/994-rotting-oranges-by-nalindalal2004-sn0v/
