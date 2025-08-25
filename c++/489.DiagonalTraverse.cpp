/*498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a
diagonal order.



Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
*/

// intuition
/*create a vector
then traverse the matrix in the order
push elements into vector
return the vector
*/

// approach
/*A matrix of size m x n has m + n - 1 diagonals.

For each diagonal d:
    - Start from top row or rightmost column depending on d.
    - Traverse down-left.
    - Reverse the diagonal elements when d is even (to match the zig-zag order).
    - Append to result.
*/

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

    int m = mat.size();
    if (m == 0)
      return {};
    int n = mat[0].size();

    vector<int> result;
    result.reserve(m * n);

    // There are m+n-1 diagonals
    for (int d = 0; d < m + n - 1; d++) {
      vector<int> diagonal;

      // Row index of the first element in this diagonal
      int r = (d < n) ? 0 : d - n + 1;
      // Column index of the first element
      int c = (d < n) ? d : n - 1;

      while (r < m && c >= 0) {
        diagonal.push_back(mat[r][c]);
        r++;
        c--;
      }

      // Reverse every other diagonal
      if (d % 2 == 0) {
        reverse(diagonal.begin(), diagonal.end());
      }

      result.insert(result.end(), diagonal.begin(), diagonal.end());
    }

    return result;
  }
};

// Time: O(m+n)
// Space: O(m+n)
// sub:
// https://leetcode.com/problems/diagonal-traverse/submissions/1747255937/?envType=daily-question&envId=2025-08-25
// sol:
// https://leetcode.com/problems/diagonal-traverse/solutions/7119143/498-diagonal-traverse-by-nalindalal2004-xmc8/
