//115. Distinct Subsequences
function numDistinct(s: string, t: string): number {
  let m = s.length;
  let n = t.length;
  const MOD = 1000000007n; // Use bigint

  const dp: bigint[][] = Array.from({ length: m + 1 }, () =>
    Array(n + 1).fill(0n),
  );
  for (let i = 0; i <= m; i++) dp[i][0] = 1n;

  for (let i = 1; i <= m; ++i) {
    for (let j = 1; j <= n; ++j) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
      else dp[i][j] = dp[i - 1][j];
    }
  }
  return Number(dp[m][n]);
}

//sub: https://leetcode.com/problems/distinct-subsequences/submissions/1557735139/
//sol: https://leetcode.com/problems/distinct-subsequences/solutions/6476059/115-distinct-subsequences-by-nalindalal2-8ksp/
