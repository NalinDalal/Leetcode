/* 778. Swim in Rising Water

You are given an n x n integer matrix grid where each value grid[i][j]
represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You
can swim from a square to another 4-directionally adjacent square if and only if
the elevation of both squares individually are at most t. You can swim infinite
distances in zero time. Of course, you must stay within the boundaries of the
grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1)
if you start at the top left square (0, 0).


Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a
higher elevation than t = 0. You cannot reach point (1, 1) until time 3. When
the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: grid =
[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.


Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.

Hint: Use either Dijkstra's, or binary search for the best time T for which you
can reach the end if you only step on squares at most T.*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// you can move to any adjaent cell with elevation <=t
// return time to move from (0,0) to (n-1,n-1)

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Min Heap: {elevation, x, y}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;

    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      int elevation = top[0], x = top[1], y = top[2];

      ans = max(ans, elevation);
      if (x == n - 1 && y == n - 1)
        return ans; // Reached destination

      for (auto& dir : directions) {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
          visited[nx][ny] = true;
          pq.push({grid[nx][ny], nx, ny});
        }
      }
    }
    return -1;
  }
};
// sub:
// https://leetcode.com/problems/swim-in-rising-water/submissions/1545716471/
// sol:
// https://leetcode.com/problems/swim-in-rising-water/solutions/6431445/778-swim-in-rising-water-by-nalindalal20-axwl/
