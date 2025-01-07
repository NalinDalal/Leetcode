//3413. Maximum Coins From K Consecutive Bags

function maximumCoins(coins: number[][], k: number): number {
  let ans = 0n; // Use BigInt for handling large numbers
  const n = coins.length;

  // Insert a dummy interval at the beginning
  coins.unshift([0, 0, 0]);
  coins.sort((a, b) => a[0] - b[0]); // Sort intervals by start position

  // Prefix sum array
  const pre = new Array<bigint>(n + 1).fill(0n);
  for (let i = 1; i <= n; i++) {
    const [li, ri, ci] = coins[i];
    pre[i] = pre[i - 1] + BigInt((ri - li + 1) * ci);
  }

  for (let i = 1; i <= n; i++) {
    // Binary search for right segments
    let l = i + 1,
      r = n,
      o = coins[i][0] + k - 1;
    while (l <= r) {
      const m = Math.floor((l + r) / 2);
      if (o >= coins[m][0]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    if (o >= coins[r][1]) {
      // Covers all intervals
      ans = ans > pre[r] - pre[i - 1] ? ans : pre[r] - pre[i - 1];
    } else {
      // Partially covers the interval
      ans =
        ans >
        pre[r - 1] -
          pre[i - 1] +
          BigInt(o - coins[r][0] + 1) * BigInt(coins[r][2])
          ? ans
          : pre[r - 1] -
            pre[i - 1] +
            BigInt(o - coins[r][0] + 1) * BigInt(coins[r][2]);
    }

    // Binary search for left segments
    l = 1;
    r = i - 1;
    o = coins[i][1] - k + 1;
    while (l <= r) {
      const m = Math.floor((l + r) / 2);
      if (o <= coins[m][1]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    if (o <= coins[l][0]) {
      // Covers all intervals
      ans = ans > pre[i] - pre[l - 1] ? ans : pre[i] - pre[l - 1];
    } else {
      // Partially covers the interval
      ans =
        ans >
        pre[i] - pre[l] + BigInt(coins[l][1] - o + 1) * BigInt(coins[l][2])
          ? ans
          : pre[i] - pre[l] + BigInt(coins[l][1] - o + 1) * BigInt(coins[l][2]);
    }
  }

  return Number(ans); // Convert BigInt back to number
}
// sub: https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/submissions/1500261221/
