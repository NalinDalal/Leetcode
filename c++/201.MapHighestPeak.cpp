/* https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22

1765. Map of Highest Peak

You are given an integer matrix isWater of size m x n that represents a map of
land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A
cell is adjacent to another cell if the former is directly north, east, south,
or west of the latter (i.e., their sides are touching). Find an assignment of
heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i,
j)'s height. If there are multiple solutions, return any of them.



Example 1:
Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Example 2:
Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the
rules will also be accepted.


Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.


Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/
*/

#include <vector>

using namespace std;

// Intitution:
/* create 2d array
traverse
if land cell incrase height
if neighbour also land then increase more
if water cell set height to 0

return height*/

// Approach:
/*1. Use a BFS to propagate heights from all water cells.
2. Start with all water cells `(isWater[i][j] == 1)` having a height of 0.
3. Assign increasing heights to neighboring cells as we move further away from
water cells.
4. Use a queue to perform the BFS and ensure all adjacent cells satisfy the
height difference condition. */
class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    vector<vector<int>> height(
        isWater[0].size(),
        vector<int>(isWater.size(), 0)); // 2 d array not sure for
    // initialisatiob
    int m = isWater.size(), n = isWater[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = ; j < n; j++) {
        if (isWater[i][j] == 0) { // land cell
          // increase height, if neighbour also have land, then increase 1
          // from there
        } else {
          // water cell so height is 0
        }
      }
    }
    return height;
  }
};

// 88.83%
// sub:
// https://leetcode.com/problems/map-of-highest-peak/submissions/1516940579/?envType=daily-question&envId=2025-01-22
// sol:
// https://leetcode.com/problems/map-of-highest-peak/solutions/6315649/1765-map-of-highest-peak8883-by-nalindal-2kbj/
