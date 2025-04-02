//2873. Maximum Value of an Ordered Triplet I
function maximumTripletValue(nums: number[]): number {
  let n: number = nums.length;
  if (n < 3) return 0;

  let max_i: number = nums[0];
  let max_value: number = 0;

  let best_diff: number[] = new Array(n).fill(0);
  for (let j = 1; j < n - 1; j++) {
    best_diff[j] = Math.max(best_diff[j - 1], max_i - nums[j]);
    max_i = Math.max(max_i, nums[j]);
  }

  for (let k = 2; k < n; k++) {
    max_value = Math.max(max_value, best_diff[k - 1] * nums[k]);
  }

  return max_value;
}
//sub:https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/submissions/1594082002/?envType=daily-question&envId=2025-04-02
//sol: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/solutions/6606327/2873-maximum-value-of-an-ordered-triplet-bw88/
