// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

function longestMonotonicSubarray(nums: number[]): number {
  const n = nums.length;
  if (n === 0) return 0;

  let maxLength = 1;
  let incLength = 1;
  let decLength = 1;

  for (let i = 1; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      incLength++;
      decLength = 1; // Reset decreasing sequence
    } else if (nums[i] < nums[i - 1]) {
      decLength++;
      incLength = 1; // Reset increasing sequence
    } else {
      // Reset both if elements are equal
      incLength = 1;
      decLength = 1;
    }
    maxLength = Math.max(maxLength, incLength, decLength);
  }

  return maxLength;
}

// Example usage:
console.log(longestMonotonicSubarray([1, 2, 3, 2, 1, 4, 5])); // Output: 3
console.log(longestMonotonicSubarray([5, 4, 3, 2, 1])); // Output: 5
console.log(longestMonotonicSubarray([1, 1, 1, 1])); // Output: 1
//sb: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/submissions/1530029307/
//sol: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/solutions/6368887/3105-longest-strictly-increasing-or-stri-z2r1/
