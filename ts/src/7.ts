// Q1. Minimum Operations to Make Columns Strictly Increasing
// https://leetcode.com/contest/weekly-contest-430/problems/minimum-operations-to-make-columns-strictly-increasing/description/

/* class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        //given a 2d array of m*n size
        // 1 opr=grid[i][j]++
        //return min opr; make column of grid strictly increasing
        //for say ith column->
        //check i with i+1 and update i+1 by abs(arr[i+1]-arr[i])+1
        //continue till last, increase count at each iteration
        //return count
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        int operations = 0;

        // Process each column
        for (int col = 0; col < n; ++col) {
            for (int row = 0; row < m - 1; ++row) {
                // If current element is not less than the next element
                if (grid[row][col] >= grid[row + 1][col]) {
                    int increment = grid[row][col] - grid[row + 1][col] + 1;
                    grid[row + 1][col] += increment;
                    operations += increment;
                }
            }
        }

        return operations;
    }
};*/

function minimumOperations(grid: number[][]): number {
  let m: number = grid.length;
  let n: number = grid[0].length;
  let operations: number = 0;

  // Iterate over each column
  for (let col = 0; col < n; col++) {
    // Traverse the rows in the current column starting from the second row (index 1)
    for (let row = 1; row < m; row++) {
      // Compare the current cell with the cell above it
      if (grid[row][col] <= grid[row - 1][col]) {
        // Calculate how much increment is required to make grid[row][col] > grid[row - 1][col]
        let increment = grid[row - 1][col] - grid[row][col] + 1;
        grid[row][col] += increment;
        operations += increment;
      }
    }
  }

  return operations;
}

{
  /* submission: https://leetcode.com/contest/weekly-contest-430/problems/minimum-operations-to-make-columns-strictly-increasing/submissions/1491330240/ */
}
