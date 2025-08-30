/*
 * 36. Valid Sudoku
Medium
Topics
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without
repetition. Note:

A Sudoku board (partially filled) could be valid but is not necessarily
solvable. Only the filled cells need to be validated according to the mentioned
rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
invalid.

*/
/* Logic
 jese ki 5 h (1,1) pe, now we need to check ki 5 na to (1,x) na hi (x,1) me aaye
 matlab us particular row me sirf ek baar, aur us particular column me sirf ek
baar aayega 9x9 grid-> 0 to 8 index

 okay so initialise a num which is the traversed element
 now initialise new element index
 index=number-1;

 same logic for column

 for sub-grid->
 k=i/3*3+j/3;
 i=row
 j=column

 k represnt the subgrid number

 according to the following rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
without repetition.
* */

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    //         Three Cases so 3 condtions.
    int rowcase[9][9] = {0};
    int colcase[9][9] = {0};
    int gridcase[9][9] = {0};

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        // if it is number.
        if (board[i][j] != '.') {
          int number = board[i][j] - '0';
          int k = i / 3 * 3 + j / 3; // k denotes grid number

          // check for the 3 case.
          if (rowcase[i][number - 1]++ || colcase[j][number - 1]++ ||
              gridcase[k][number - 1]++)
            return false;
        }
      }
    }
    return true;
  }
};
// sub:
// https://leetcode.com/problems/valid-sudoku/submissions/1341062403/?envType=daily-question&envId=2025-08-30
// sol:
// https://leetcode.com/problems/valid-sudoku/solutions/5570731/36-valid-sudoku/?envType=daily-question&envId=2025-08-30
