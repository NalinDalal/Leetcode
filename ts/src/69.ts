// 79. Word Search

function exist(board: string[][], word: string): boolean {
  const m = board.length;
  const n = board[0].length;

  // Iterate through the board to find the starting point
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (board[i][j] === word[0] && isValid(word[0])) {
        if (dfs(board, word, i, j, 0)) {
          return true;
        }
      }
    }
  }

  return false;
}

function isValid(c: string): boolean {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

function dfs(
  board: string[][],
  word: string,
  row: number,
  col: number,
  index: number
): boolean {
  // Base case: all characters matched
  if (index === word.length) {
    return true;
  }

  // Boundary and character mismatch check
  if (
    row < 0 ||
    row >= board.length ||
    col < 0 ||
    col >= board[0].length ||
    board[row][col] !== word[index]
  ) {
    return false;
  }

  // Temporarily mark the cell as visited
  const temp = board[row][col];
  board[row][col] = '#';

  // Explore neighbors (up, down, left, right)
  const found =
    dfs(board, word, row + 1, col, index + 1) ||
    dfs(board, word, row - 1, col, index + 1) ||
    dfs(board, word, row, col + 1, index + 1) ||
    dfs(board, word, row, col - 1, index + 1);

  // Restore the original value of the cell
  board[row][col] = temp;

  return found;
}

// Example usage:
const board = [
  ['A', 'B', 'C', 'E'],
  ['S', 'F', 'C', 'S'],
  ['A', 'D', 'E', 'E'],
];

console.log(exist(board,
//sub: https://leetcode.com/problems/word-search/submissions/1523242711/
//sol: https://leetcode.com/problems/word-search/solutions/6339795/79-word-search8312-by-nalindalal2004-y2ap/
