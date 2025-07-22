//1695. Maximum Erasure Value
function maximumUniqueSubarray(nums: number[]): number {
  const seen = new Set<number>();
  let left = 0;
  let currSum = 0;
  let maxSum = 0;

  for (let right = 0; right < nums.length; right++) {
    while (seen.has(nums[right])) {
      seen.delete(nums[left]);
      currSum -= nums[left];
      left++;
    }
    seen.add(nums[right]);
    currSum += nums[right];
    maxSum = Math.max(maxSum, currSum);
  }

  return maxSum;
}

// Example usage:
console.log(maximumUniqueSubarray([4, 2, 4, 5, 6])); // Output: 17

//sub: https://leetcode.com/problems/maximum-erasure-value/submissions/1707147313/?envType=daily-question&envId=2025-07-22
//sol: https://leetcode.com/problems/maximum-erasure-value/solutions/6990314/1695-maximum-erasure-value-by-nalindalal-l3ep/
