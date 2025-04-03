//2874. Maximum Value of an Ordered Triplet II
function maximumTripletValue(nums: number[]): number {
  let n = nums.length;
  if (n < 3) return 0;

  let max_before: number[] = new Array(n).fill(0);
  let max_after: number[] = new Array(n).fill(0);

  // Compute max_before[j]: max value before index j
  max_before[0] = nums[0];
  for (let j = 1; j < n; j++) {
    max_before[j] = Math.max(max_before[j - 1], nums[j - 1]);
  }

  // Compute max_after[j]: max value after index j
  max_after[n - 1] = nums[n - 1];
  for (let j = n - 2; j >= 0; j--) {
    max_after[j] = Math.max(max_after[j + 1], nums[j + 1]);
  }

  let max_value: number = 0;

  // Iterate over j
  for (let j = 1; j < n - 1; j++) {
    let left = max_before[j];
    let mid = nums[j];
    let right = max_after[j];

    let value = (left - mid) * right;
    max_value = Math.max(max_value, value);
  }

  return max_value;
}
//sub: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/submissions/1595491114/?envType=daily-question&envId=2025-04-03
//sol: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/solutions/6610983/2874-maximum-value-of-an-ordered-triplet-xkqh/
