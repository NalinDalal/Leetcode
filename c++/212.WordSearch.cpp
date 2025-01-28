/* https://leetcode.com/problems/word-search/description/
79. Word Search

Given an m x n grid of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.



Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCCED" Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"SEE" Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
"ABCB" Output: false


Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a
larger board?
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0] && isValid(word[0])) {
          if (dfs(board, word, i, j, 0)) {
            return true;
          }
        }
      }
    }

    return false;
  }

private:
  bool dfs(vector<vector<char>>& board, string& word, int row, int col,
           int index) {
    // Base case: Found all characters of the word
    if (index == word.size()) {
      return true;
    }

    // Check boundaries and if current cell matches the current character in
    // word
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
        board[row][col] != word[index]) {
      return false;
    }

    // Mark current cell as visited (optional, can use a visited array instead)
    char temp = board[row][col];
    board[row][col] = '#'; // Mark as visited

    // Explore neighbors
    if (dfs(board, word, row + 1, col, index + 1) ||
        dfs(board, word, row - 1, col, index + 1) ||
        dfs(board, word, row, col + 1, index + 1) ||
        dfs(board, word, row, col - 1, index + 1)) {
      return true;
    }

    // Restore the board
    board[row][col] = temp;

    return false;
  }
};

// so do it like this->
// first letter of word ins in board[i][j]
// then check if next letter od word is near board[i][j] like +-1 only
// if then move to next letter
// repeat recusrsively
// if not return false
// else return true

// Time: O(m*n)
// Space:O(1)

// sub: https://leetcode.com/problems/word-search/submissions/1523237207/
// sol:
// https://leetcode.com/problems/word-search/solutions/6339795/79-word-search8312-by-nalindalal2004-y2ap/
