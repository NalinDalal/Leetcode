//518. Coin Change II
function change(amount: number, coins: number[]): number {
  const [m, n] = [coins.length, amount];
  const f: number[][] = Array.from({ length: m + 1 }, () =>
    Array(n + 1).fill(0),
  );
  f[0][0] = 1;
  for (let i = 1; i <= m; ++i) {
    for (let j = 0; j <= n; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= coins[i - 1]) {
        f[i][j] += f[i][j - coins[i - 1]];
      }
    }
  }
  return f[m][n];
}
//sub: https://leetcode.com/problems/coin-change-ii/submissions/1553546035/
//sol: https://leetcode.com/problems/coin-change-ii/solutions/6461576/518-coin-change-ii-by-nalindalal2004-26p0/
