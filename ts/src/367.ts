//2327. Number of People Aware of a Secret
function peopleAwareOfSecret(n: number, delay: number, forget: number): number {
  const MOD = 1_000_000_007;
  const dp = new Array(n + 1).fill(0);
  dp[1] = 1;

  let shareable = 0;
  let ans = 0;

  for (let day = 2; day <= n; day++) {
    // People who become able to share
    if (day - delay >= 1) {
      shareable = (shareable + dp[day - delay]) % MOD;
    }
    // People who forget today
    if (day - forget >= 1) {
      shareable = (shareable - dp[day - forget] + MOD) % MOD;
    }
    // New people learning today
    dp[day] = shareable;
  }

  for (let day = n - forget + 1; day <= n; day++) {
    if (day >= 1) ans = (ans + dp[day]) % MOD;
  }

  return ans;
}

//sub: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/1764470518/?envType=daily-question&envId=2025-09-09
//sol: https://leetcode.com/problems/number-of-people-aware-of-a-secret/solutions/7170972/2327-number-of-people-aware-of-a-secret-z4gd6/
