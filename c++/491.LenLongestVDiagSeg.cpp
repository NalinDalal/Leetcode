/*3459. Length of Longest V-Shaped Diagonal Segment

You are given a 2D integer matrix grid of size n x m, where each element is
either 0, 1, or 2.

A V-shaped diagonal segment is defined as:

The segment starts with 1.
The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
The segment:
Starts along a diagonal direction (top-left to bottom-right, bottom-right to
top-left, top-right to bottom-left, or bottom-left to top-right). Continues the
sequence in the same diagonal direction. Makes at most one clockwise 90-degree
turn to another diagonal direction while maintaining the sequence.


Return the length of the longest V-shaped diagonal segment. If no valid segment
exists, return 0.



Example 1:

Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

Output: 5

Explanation:



The longest V-shaped diagonal segment has a length of 5 and follows these
coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4),
and continues as (3,3) → (4,2).

Example 2:

Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

Output: 4

Explanation:



The longest V-shaped diagonal segment has a length of 4 and follows these
coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and
continues as (2,1) → (1,0).

Example 3:

Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

Output: 5

Explanation:



The longest V-shaped diagonal segment has a length of 5 and follows these
coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).

Example 4:

Input: grid = [[1]]

Output: 1

Explanation:

The longest V-shaped diagonal segment has a length of 1 and follows these
coordinates: (0,0).



Constraints:

n == grid.length
m == grid[i].length
1 <= n, m <= 500
grid[i][j] is either 0, 1 or 2.



Hint 1
Use dynamic programming to determine the best point to make a 90-degree rotation
in the diagonal path while maintaining the required sequence.

Hint 2
Represent dynamic programming states as (row, col, currentDirection,
hasMadeTurnYet). Track the current position, direction of traversal, and whether
a turn has already been made, and take transitions accordingly to find the
longest V-shaped diagonal segment.
*/

/*find a 1 in the whole matrix
 * then find either a 0 or a 2 in diagonal of that 1
 * now find in same diagonal of that 0 or 2
 * or else make a anti-clockwise 90-degree turn, use dynamic programming
 * repeat
 * return largest pathway that can be made

• Start a search from every 1 in the grid.
• Explore all valid paths recursively (like a Depth-First Search).
• Use a cache (memoization) to store results and avoid re-calculating the same
sub-paths.

What do we need to track?
Our recursive function needs to know its "state":
• Current position: (x, y)
• Current direction •
• Have we already made a turn? (0 for no, 1 for yes)
• The next number we're looking for: target (0 or 2).
*/

class Solution {
public:
  int lenOfVDiagonal(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int memo[m][n][4][2];
    memset(memo, -1, sizeof(memo));

    function<int(int, int, int, bool, int)> dfs =
        [&](int cx, int cy, int direction, bool turn, int target) -> int {
      int nx = cx + dirs[direction][0];
      int ny = cy + dirs[direction][1];
      /* If it goes beyond the boundary or the next node's value is not
       * the target value, then return */
      if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
        return 0;
      }
      if (memo[nx][ny][direction][turn] != -1) {
        return memo[nx][ny][direction][turn];
      }

      /* Continue walking in the original direction. */
      int maxStep = dfs(nx, ny, direction, turn, 2 - target);
      if (turn) {
        /* Clockwise rotate 90 degrees turn */
        maxStep =
            fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
      }
      memo[nx][ny][direction][turn] = maxStep + 1;
      return maxStep + 1;
    };

    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          for (int direction = 0; direction < 4; ++direction) {
            res = fmax(res, dfs(i, j, direction, true, 2) + 1);
          }
        }
      }
    }

    return res;
  }
};

// Time: O(m*n)
// Space: O(m*n)
// sub:
// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/submissions/1749755926/
// sol:
// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/solutions/7126519/3459-length-of-longest-v-shaped-diagonal-nkd7/
