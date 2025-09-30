//2221. Find Triangular Sum of an Array
function triangularSum(nums: number[]): number {
  const n = nums.length;
  const C = new Array(n).fill(0);
  C[0] = 1;

  // Build binomial coefficients mod 10
  for (let i = 1; i < n; i++) {
    for (let j = i; j > 0; j--) {
      C[j] = (C[j] + C[j - 1]) % 10;
    }
  }

  let result = 0;
  for (let i = 0; i < n; i++) {
    result = (result + C[i] * nums[i]) % 10;
  }

  return result;
}
//sub: https://leetcode.com/problems/find-triangular-sum-of-an-array/submissions/1787022490/?envType=daily-question&envId=2025-09-30
//sol: https://leetcode.com/problems/find-triangular-sum-of-an-array/solutions/7235693/2221-find-triangular-sum-of-an-array-by-2cyt7/
