/*1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have
all ones.


Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.


Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

Hint 1
Create an additive table that counts the sum of elements of submatrix with the
superior corner at (0,0). Hint 2 Loop over all subsquares in O(n^3) and check if
the sum make the whole array to be ones, if it checks then add 1 to the answer.
*/

class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int total = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          if (i == 0 || j == 0) {
            dp[i][j] = 1; // first row or col, only 1x1 squares
          } else {
            dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
          }
          total += dp[i][j]; // add all squares ending here
        }
      }
    }
    return total;
  }
};
// sub:
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1741542462/?envType=daily-question&envId=2025-08-20
// sol:
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/7101654/1277-count-square-submatrices-with-all-o-t6k5/
