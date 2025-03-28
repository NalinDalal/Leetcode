/*2503. Maximum Number of Points From Grid Queries

You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start
in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you
are in, then you get one point if it is your first time visiting this cell, and
you can move to any adjacent cell in all 4 directions: up, down, left, and
right. Otherwise, you do not get any points, and you end this process. After the
process, answer[i] is the maximum number of points you can get. Note that for
each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.



Example 1:
Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each
query.

Example 2:
Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is
already greater than or equal to 3.


Constraints:
m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106


Hint 1: The queries are all given to you beforehand so you can answer them in
any order you want. Hint 2: Sort the queries knowing their original order to be
able to build the answer array. Hint 3: Run a BFS on the graph and answer the
queries in increasing order.
*/

#include <priority_queue>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    // start with iterating over the queries
    // start at grid[0][0]
    // so if queries[i]>grid[i][j] we can get points
    // else no points
    // return an ans array where ans[i] is maxPoints after queries[i] operation
    // use minHeap to process queries
    int m = grid.size(), n = grid[0].size();
    vector<int> ans(queries.size(), 0);
    vector<pair<int, int>> sorted_queries;

    for (int i = 0; i < queries.size(); i++) {
      sorted_queries.push_back({queries[i], i});
    }
    sort(sorted_queries.begin(), sorted_queries.end());

    // Min-heap: {grid_value, row, col}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        minHeap;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Direction vectors for moving up, down, left, and right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    minHeap.emplace(grid[0][0], 0, 0);
    visited[0][0] = true;
    int count = 0;

    for (auto& [query, index] : sorted_queries) {
      while (!minHeap.empty() && get<0>(minHeap.top()) < query) {
        auto [value, x, y] = minHeap.top();
        minHeap.pop();
        count++;

        for (auto [dx, dy] : directions) {
          int nx = x + dx, ny = y + dy;
          if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
            visited[nx][ny] = true;
            minHeap.emplace(grid[nx][ny], nx, ny);
          }
        }
      }
      ans[index] = count;
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/submissions/1588889293/?envType=daily-question&envId=2025-03-28
// sol:
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/solutions/6588563/2503-maximum-number-of-points-from-grid-804wd/
