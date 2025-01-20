/* https://leetcode.com/problems/set-matrix-zeroes/description/

73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and
column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Hint 1
If any cell of the matrix has a zero we can record its row and column number
using additional memory. But if you don't want to use extra memory then you can
manipulate the array instead. i.e. simulating exactly what the question says.
Hint 2
Setting cell values to zero on the fly while iterating might lead to
discrepancies. What if you use some other integer value as your marker? There is
still a better approach for this problem with 0(1) space.

Hint 3
We could have used 2 sets to keep a record of rows/columns which need to be set
to zero. But for an O(1) space solution, you can use one of the rows and and one
of the columns to keep track of this information.

Hint 4
We can use the first cell of every row and column as a flag. This flag would
determine whether a row or column has been set to zero.

*/
#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Flags to mark if the first row and first column should be zeroed
    bool firstRowZero = false, firstColZero = false;

    // Check if the first row has any zeros
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        firstRowZero = true;
        break;
      }
    }

    // Check if the first column has any zeros
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        firstColZero = true;
        break;
      }
    }

    // Use the first row and column to mark rows and columns to be zeroed
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0; // Mark the row
          matrix[0][j] = 0; // Mark the column
        }
      }
    }

    // Zero out cells based on the markers in the first row and column
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // Zero out the first row if needed
    if (firstRowZero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }

    // Zero out the first column if needed
    if (firstColZero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};
// m*n matrix
// if matrix[i][j] is zero then set matrix[0][j] to matrix[i][0] zero and
// matrix[i][0] to matrix[0][j] zero

// check if a row item is zero,
// check if a col item is zero
// if yes then set whole row to zero
// check for row with column combination and vice-versa

// helper function for 1st row and column

// Time: O(m*n)
// Space: O(1)

// Sub: https://leetcode.com/problems/set-matrix-zeroes/submissions/1514417722/
// sol:
// https://leetcode.com/problems/set-matrix-zeroes/solutions/6305900/73-set-matrix-zeroes100-by-nalindalal200-srnc/
