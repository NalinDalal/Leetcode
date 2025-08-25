//498. Diagonal Traverse
function findDiagonalOrder(mat: number[][]): number[] {
  const m = mat.length;
  if (m === 0) return [];
  const n = mat[0].length;

  const result: number[] = [];

  for (let d = 0; d < m + n - 1; d++) {
    const diagonal: number[] = [];

    let r = d < n ? 0 : d - n + 1;
    let c = d < n ? d : n - 1;

    while (r < m && c >= 0) {
      diagonal.push(mat[r][c]);
      r++;
      c--;
    }

    if (d % 2 === 0) {
      diagonal.reverse();
    }

    result.push(...diagonal);
  }

  return result;
}

//sub: https://leetcode.com/problems/diagonal-traverse/submissions/1747258977/?envType=daily-question&envId=2025-08-25
//sol: https://leetcode.com/problems/diagonal-traverse/solutions/7119143/498-diagonal-traverse-by-nalindalal2004-xmc8/
