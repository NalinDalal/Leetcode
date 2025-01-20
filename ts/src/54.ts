// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20
// 2661. First Completely Painted Row or Column

function firstCompleteIndex(arr: number[], mat: number[][]): number {
  const m = mat.length;
  const n = mat[0].length;

  // Create a mapping of number to its coordinates in the matrix
  const numToCoordinates: [number, number][] = new Array(m * n);
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      numToCoordinates[mat[r][c] - 1] = [r, c];
    }
  }

  // Tally arrays for rows and columns
  const rowTally: number[] = new Array(m).fill(0);
  const colTally: number[] = new Array(n).fill(0);

  // Process the array `arr`
  for (let i = 0; i < arr.length; i++) {
    const [r, c] = numToCoordinates[arr[i] - 1];
    rowTally[r]++;
    colTally[c]++;

    // Check if any row or column is completely filled
    if (rowTally[r] === n || colTally[c] === m) {
      return i;
    }
  }

  return arr.length;
}
//50%
//sub: https://leetcode.com/problems/first-completely-painted-row-or-column/submissions/1514818319/?envType=daily-question&envId=2025-01-20

//sol: https://leetcode.com/problems/first-completely-painted-row-or-column/solutions/6307553/2661-first-completely-painted-row-or-col-471u/
