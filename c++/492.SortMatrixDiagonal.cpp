/*3446. Sort Matrix by Diagonals
You are given an n x n square matrix of integers grid. Return the matrix such
that:

The diagonals in the bottom-left triangle (including the middle diagonal) are
sorted in non-increasing order. The diagonals in the top-right triangle are
sorted in non-decreasing order.


Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in
non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in
non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:

Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]

Explanation:



The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to
[2, 0]. The other diagonals are already in the correct order.

Example 3:

Input: grid = [[1]]

Output: [[1]]

Explanation:

Diagonals with exactly one element are already in order, so no changes are
needed.



Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105

Hint 1
Use a data structure to store all values in each diagonal.
Hint 2
Sort and replace them in the matrix.
*/

/*hmm, so first take the original matrix,
 * then traverse it diagonally.
 * incorporate them into a new matrix
 * then sort the individual diagonals which are now a vector in new matrix
 * then replace them accordingly into original matrix
 * return original matrix
 *
 lower left triangle(including the diagonal) in non-increasing order
upper right in non-decreasing order
 */

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    map<int, vector<int>> diag;

    // Step 1: collect diagonals
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        diag[i - j].push_back(grid[i][j]);
      }
    }

    // Step 2: sort diagonals conditionally
    for (auto& [key, vec] : diag) {
      if (key >= 0) {
        // lower-left (including main) → non-increasing
        sort(vec.begin(), vec.end(), greater<int>());
      } else {
        // upper-right → non-decreasing
        sort(vec.begin(), vec.end());
      }
    }

    // Step 3: write back
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = diag[i - j].front();
        diag[i - j].erase(diag[i - j].begin());
      }
    }

    return grid;
  }
};

// sub:
// https://leetcode.com/problems/sort-matrix-by-diagonals/submissions/1750971015/?envType=daily-question&envId=2025-08-28
// sol:
// https://leetcode.com/problems/sort-matrix-by-diagonals/solutions/7130153/3446-sort-matrix-by-diagonals-by-nalinda-mtm3/
