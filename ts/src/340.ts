//2787. Ways to Express an Integer as Sum of Powers
const MOD = 1_000_000_007;
function numberOfWays(n: number, x: number): number {
    // Find max base integer m such that m^x <= n
    let maxBase = 1;
    while (Math.pow(maxBase, x) <= n) maxBase++;
    maxBase--;

    // Precompute powers
    const powers = new Array(maxBase + 1).fill(0);
    for (let i = 1; i <= maxBase; i++) {
      powers[i] = Math.pow(i, x);
    }

    // dp[k][j]: number of ways to write k as sum of unique powers up to j-th power
    const dp: number[][] = Array.from({ length: n + 1 }, () => new Array(maxBase + 1).fill(0));

    // base case: ways to write 0 = 1 (use no numbers)
    for (let j = 0; j <= maxBase; j++) dp[0][j] = 1;

    for (let k = 1; k <= n; k++) {
      for (let j = 1; j <= maxBase; j++) {
        dp[k][j] = dp[k][j - 1];
        if (k - powers[j] >= 0) {
          dp[k][j] = (dp[k][j] + dp[k - powers[j]][j - 1]) % MOD;
        }
      }
    }

    return dp[n][maxBase];
};
//sub: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/submissions/1731898503/?envType=daily-question&envId=2025-08-12
//sol: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/solutions/7069842/2787-ways-to-express-an-integer-as-sum-o-900l/
