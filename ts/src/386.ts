//1039. Minimum Score Triangulation of Polygon
function minScoreTriangulation(values: number[]): number {
  const n = values.length;
  const dp: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

  for (let gap = 2; gap < n; gap++) {
    for (let i = 0; i + gap < n; i++) {
      const j = i + gap;
      dp[i][j] = Number.MAX_SAFE_INTEGER;
      for (let k = i + 1; k < j; k++) {
        dp[i][j] = Math.min(
          dp[i][j],
          dp[i][k] + dp[k][j] + values[i] * values[j] * values[k],
        );
      }
    }
  }
  return dp[0][n - 1];
}
//sub: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/submissions/1786013484/?envType=daily-question&envId=2025-09-29
//sol: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/7232926/1039-minimum-score-triangulation-of-poly-66z1/
