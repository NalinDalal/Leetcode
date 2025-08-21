//1504. Count Submatrices With All Ones
function numSubmat(mat: number[][]): number {
  const m = mat.length;
  const n = mat[0].length;
  const height = new Array(n).fill(0);
  let result = 0;

  for (let i = 0; i < m; i++) {
    // update heights
    for (let j = 0; j < n; j++) {
      if (mat[i][j] === 0) height[j] = 0;
      else height[j] += 1;
    }

    // count rectangles ending at this row
    for (let j = 0; j < n; j++) {
      let minHeight = height[j];
      for (let k = j; k >= 0; k--) {
        minHeight = Math.min(minHeight, height[k]);
        if (minHeight === 0) break; // early stop
        result += minHeight;
      }
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/1742684899/?envType=daily-question&envId=2025-08-21
//sol: https://leetcode.com/problems/count-submatrices-with-all-ones/solutions/7104935/1504-count-submatrices-with-all-ones-by-10iv1/
