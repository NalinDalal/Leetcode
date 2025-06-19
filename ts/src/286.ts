//2294. Partition Array Such That Maximum Difference Is K
function partitionArray(nums: number[], k: number): number {
  nums.sort((a, b) => a - b); // Sort ascending

  let count = 1;
  let start = nums[0];

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] - start > k) {
      count++;
      start = nums[i];
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/submissions/1669025400/?envType=daily-question&envId=2025-06-19
//sol: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/solutions/6860292/2294-partition-array-such-that-maximum-d-16ky/
