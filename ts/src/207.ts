//918. Maximum Sum Circular Subarray
function maxSubarraySumCircular(nums: number[]): number {
  let total = 0;
  let maxSum = nums[0],
    curMax = 0;
  let minSum = nums[0],
    curMin = 0;

  for (let num of nums) {
    curMax = Math.max(num, curMax + num);
    maxSum = Math.max(maxSum, curMax);

    curMin = Math.min(num, curMin + num);
    minSum = Math.min(minSum, curMin);

    total += num;
  }

  // All numbers are negative — return max element
  if (maxSum < 0) return maxSum;

  return Math.max(maxSum, total - minSum);
}
//sub: https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/1599074474/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/6623843/918-maximum-sum-circular-subarray-by-nal-009f/
