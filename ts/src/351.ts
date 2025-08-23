//3197. Find the Minimum Area to Cover All Ones II
function minimumSum(grid: number[][]): number {
  const n = grid.length,
    m = grid[0].length;
  const INF = 1e9;

  const rectArea = (r1: number, r2: number, c1: number, c2: number): number => {
    let minr = n,
      maxr = -1,
      minc = m,
      maxc = -1;
    for (let i = r1; i <= r2; i++) {
      for (let j = c1; j <= c2; j++) {
        if (grid[i][j] === 1) {
          minr = Math.min(minr, i);
          maxr = Math.max(maxr, i);
          minc = Math.min(minc, j);
          maxc = Math.max(maxc, j);
        }
      }
    }
    if (maxr === -1) return INF;
    return (maxr - minr + 1) * (maxc - minc + 1);
  };

  let ans = INF;

  // Case 1: vertical stripes
  for (let c1 = 0; c1 < m - 2; c1++) {
    for (let c2 = c1 + 1; c2 < m - 1; c2++) {
      const a1 = rectArea(0, n - 1, 0, c1);
      const a2 = rectArea(0, n - 1, c1 + 1, c2);
      const a3 = rectArea(0, n - 1, c2 + 1, m - 1);
      if (a1 < INF && a2 < INF && a3 < INF) ans = Math.min(ans, a1 + a2 + a3);
    }
  }

  // Case 2: horizontal stripes
  for (let r1 = 0; r1 < n - 2; r1++) {
    for (let r2 = r1 + 1; r2 < n - 1; r2++) {
      const a1 = rectArea(0, r1, 0, m - 1);
      const a2 = rectArea(r1 + 1, r2, 0, m - 1);
      const a3 = rectArea(r2 + 1, n - 1, 0, m - 1);
      if (a1 < INF && a2 < INF && a3 < INF) ans = Math.min(ans, a1 + a2 + a3);
    }
  }

  // Case 3: vertical cut + right split horizontally
  for (let c = 0; c < m - 1; c++) {
    const left = rectArea(0, n - 1, 0, c);
    if (left === INF) continue;
    for (let r = 0; r < n - 1; r++) {
      const a2 = rectArea(0, r, c + 1, m - 1);
      const a3 = rectArea(r + 1, n - 1, c + 1, m - 1);
      if (a2 < INF && a3 < INF) ans = Math.min(ans, left + a2 + a3);
    }
  }

  // Case 4: vertical cut + left split horizontally
  for (let c = 0; c < m - 1; c++) {
    const right = rectArea(0, n - 1, c + 1, m - 1);
    if (right === INF) continue;
    for (let r = 0; r < n - 1; r++) {
      const a2 = rectArea(0, r, 0, c);
      const a3 = rectArea(r + 1, n - 1, 0, c);
      if (a2 < INF && a3 < INF) ans = Math.min(ans, right + a2 + a3);
    }
  }

  // Case 5: horizontal cut + bottom split vertically
  for (let r = 0; r < n - 1; r++) {
    const top = rectArea(0, r, 0, m - 1);
    if (top === INF) continue;
    for (let c = 0; c < m - 1; c++) {
      const a2 = rectArea(r + 1, n - 1, 0, c);
      const a3 = rectArea(r + 1, n - 1, c + 1, m - 1);
      if (a2 < INF && a3 < INF) ans = Math.min(ans, top + a2 + a3);
    }
  }

  // Case 6: horizontal cut + top split vertically
  for (let r = 0; r < n - 1; r++) {
    const bottom = rectArea(r + 1, n - 1, 0, m - 1);
    if (bottom === INF) continue;
    for (let c = 0; c < m - 1; c++) {
      const a2 = rectArea(0, r, 0, c);
      const a3 = rectArea(0, r, c + 1, m - 1);
      if (a2 < INF && a3 < INF) ans = Math.min(ans, bottom + a2 + a3);
    }
  }

  return ans;
}

//sub: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/submissions/1744908297/?envType=daily-question&envId=2025-08-23
//sol: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/solutions/7111782/3197-find-the-minimum-area-to-cover-all-3gb6n/
