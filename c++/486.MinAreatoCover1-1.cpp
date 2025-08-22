/*3195. Find the Minimum Area to Cover All Ones I
You are given a 2D binary array grid. Find a rectangle with horizontal and
vertical sides with the smallest area, such that all the 1's in grid lie inside
this rectangle.

Return the minimum possible area of the rectangle.



Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:
The smallest rectangle has a height of 2 and a width of 3, so it has an area of
2 * 3 = 6.



Example 2:

Input: grid = [[1,0],[0,0]]

Output: 1

Explanation:
The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.



Constraints:
1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.

Hint 1
Find the minimum and maximum coordinates of a cell with a value of 1 in both
directions.
*/
/*1. Traverse the grid
 2. Track:
    - `minRow` = smallest row index with a `1`
    - `maxRow` = largest row index with a `1`
    - `minCol` = smallest col index with a `1`
    - `maxCol` = largest col index with a `1`

3. Once found, the rectangle is defined by:
    - Height = `maxRow - minRow + 1`
    - Width = `maxCol - minCol + 1`

4. Return `height * width`.
    */
class Solution {
public:
  int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int minRow = m, maxRow = -1;
    int minCol = n, maxCol = -1;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          minRow = min(minRow, i);
          maxRow = max(maxRow, i);
          minCol = min(minCol, j);
          maxCol = max(maxCol, j);
        }
      }
    }

    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;

    return height * width;
  }
};
// sub:
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/submissions/1743814268/?envType=daily-question&envId=2025-08-22
// sol:
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/solutions/7108103/3195-find-the-minimum-area-to-cover-all-eqxuw/
