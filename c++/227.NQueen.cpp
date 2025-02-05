/* https://leetcode.com/problems/n-queens/description/
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You
may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space,
respectively.


Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown
above

Example 2:
Input: n = 1
Output: [["Q"]]


Constraints:1 <= n <= 9
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    // 1<=n<=9
    if (n == 1)
      return {{"Q"}};

    // for each row place a queen such that no other queen attacks it
    // return all possible combinations
    // if empty space use .
    // if queen placed use "Q" check for conflicts
    // return result vector

    vector<vector<string>> results;
    vector<string> board(n, string(n, '.')); // Initialize an empty board
    vector<bool> cols(n, false);             // Track columns with queens
    vector<bool> diag1(2 * n - 1, false);    // Track \ diagonals
    vector<bool> diag2(2 * n - 1, false);    // Track / diagonals

    backtrack(0, n, board, results, cols, diag1, diag2);
    return results;
  }

private:
  void backtrack(int row, int n, vector<string>& board,
                 vector<vector<string>>& results, vector<bool>& cols,
                 vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
      results.push_back(board); // Found a valid configuration
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
        continue; // Conflict detected, skip this position
      }

      // Place the queen
      board[row][col] = 'Q';
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

      // Recurse for the next row
      backtrack(row + 1, n, board, results, cols, diag1, diag2);

      // Backtrack: Remove the queen
      board[row][col] = '.';
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
  }
};

// sub: https://leetcode.com/problems/n-queens/submissions/1532130285/
// sol:
// https://leetcode.com/problems/n-queens/solutions/6378828/51-n-queens-by-nalindalal2004-5zac/
