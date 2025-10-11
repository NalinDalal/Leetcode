//3186. Maximum Total Damage With Spell Casting
function maximumTotalDamage(power: number[]): number {
  // Step 1: Aggregate total damage for each unique power
  const total = new Map<number, number>();
  for (const p of power) {
    total.set(p, (total.get(p) ?? 0) + p);
  }

  // Step 2: Sort unique powers
  const keys = Array.from(total.keys()).sort((a, b) => a - b);
  const n = keys.length;
  const dp: number[] = new Array(n).fill(0);

  // Step 3: DP initialization
  dp[0] = total.get(keys[0])!;

  // Step 4: DP transition with binary search
  for (let i = 1; i < n; i++) {
    // Option 1: skip this damage
    const skip = dp[i - 1];

    // Option 2: take this damage
    // Find last valid j where keys[j] <= keys[i] - 3
    let left = 0,
      right = i - 1,
      j = -1;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (keys[mid] <= keys[i] - 3) {
        j = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    let take = total.get(keys[i])!;
    if (j !== -1) take += dp[j];

    dp[i] = Math.max(skip, take);
  }

  return dp[n - 1];
}

//sub:
//https://leetcode.com/problems/maximum-total-damage-with-spell-casting/submissions/1797917312/?envType=daily-question&envId=2025-10-11
//sol: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/solutions/7265836/3186-maximum-total-damage-with-spell-cas-2tnc/
