//1498. Number of Subsequences That Satisfy the Given Sum Condition
function numSubseq(nums: number[], target: number): number {
  const MOD = 1e9 + 7;
  nums.sort((a, b) => a - b);
  const n = nums.length;

  // Precompute powers of 2
  const power: number[] = new Array(n).fill(1);
  for (let i = 1; i < n; i++) {
    power[i] = (power[i - 1] * 2) % MOD;
  }

  let res = 0;
  let left = 0,
    right = n - 1;

  while (left <= right) {
    if (nums[left] + nums[right] <= target) {
      res = (res + power[right - left]) % MOD;
      left++;
    } else {
      right--;
    }
  }

  return res;
}
//sub: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/submissions/1680032334/?envType=daily-question&envId=2025-06-29
//sol: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/6897849/1498-number-of-subsequences-that-satisfy-mrap/
