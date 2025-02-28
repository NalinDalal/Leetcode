//1092. Shortest Common Supersequence

function shortestCommonSupersequence(a: string, b: string): string {
  const m = a.length,
    n = b.length;
  const dp: number[][] = Array.from({ length: m + 1 }, () =>
    Array(n + 1).fill(0),
  );

  // Fill DP table for longest common subsequence (LCS)
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      dp[i + 1][j + 1] =
        a[i] === b[j] ? dp[i][j] + 1 : Math.max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  let res = "";
  let i = m,
    j = n;

  // Construct the shortest common supersequence
  while (i > 0 && j > 0) {
    if (dp[i][j] === dp[i - 1][j]) {
      res += a[--i];
    } else if (dp[i][j] === dp[i][j - 1]) {
      res += b[--j];
    } else {
      res += a[--i];
      j--;
    }
  }

  // Append remaining parts of a and b
  return a.slice(0, i) + b.slice(0, j) + res.split("").reverse().join("");
}
//sub: https://leetcode.com/problems/shortest-common-supersequence/submissions/1557741872/?envType=daily-question&envId=2025-02-28
//sol: https://leetcode.com/problems/shortest-common-supersequence/solutions/6476094/1092-shortest-common-supersequence-by-na-tt01/
