/* https://leetcode.com/problems/spiral-matrix/description/

54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/

#include <vector>

using std::vector;

// 1. start from top left corner, define the boundaries of the matrix
// 2. loop through the matrix, along th boundaries
// 3. log the elements
// 4. adjust the boundaries
// 5. terminate condition

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty())
      return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
      // Traverse from left to right along the top row
      for (int i = left; i <= right; ++i) {
        result.push_back(matrix[top][i]);
      }
      top++;

      // Traverse from top to bottom along the right column
      for (int i = top; i <= bottom; ++i) {
        result.push_back(matrix[i][right]);
      }
      right--;

      if (top <= bottom) {
        // Traverse from right to left along the bottom row
        for (int i = right; i >= left; --i) {
          result.push_back(matrix[bottom][i]);
        }
        bottom--;
      }

      if (left <= right) {
        // Traverse from bottom to top along the left column
        for (int i = bottom; i >= top; --i) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }

    return result;
  }
};

// Time: O(m*n)
// Space: O(m*n)
// sub: https://leetcode.com/problems/spiral-matrix/submissions/1516899163/
// sol:
// https://leetcode.com/problems/spiral-matrix/solutions/6315491/54-spiral-matrix100-by-nalindalal2004-gv2a/
