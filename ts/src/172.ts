//3191. Minimum Operations to Make Binary Array Elements Equal to One I
function minOperations(nums: number[]): number {
  let flips = 0;
  let n = nums.length;

  for (let i = 0; i <= n - 3; i++) {
    if (nums[i] === 0) {
      // Flip current element and next two
      nums[i] ^= 1;
      nums[i + 1] ^= 1;
      nums[i + 2] ^= 1;
      flips++;
    }
  }

  // Check if last two elements contain a 0, making it impossible
  for (let i = n - 2; i < n; i++) {
    if (i >= 0 && nums[i] === 0) return -1;
  }

  return flips;
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/submissions/1578700372/?envType=daily-question&envId=2025-03-19
//sol: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/solutions/6554078/3191-minimum-operations-to-make-binary-a-ql6r/
