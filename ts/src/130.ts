//1749. Maximum Absolute Sum of Any Subarray
function maxAbsoluteSum(nums: number[]): number {
  let sum: number = 0,
    minSum: number = 0,
    maxSum: number = 0;
  for (let num of nums) {
    sum += num;
    if (sum > maxSum) maxSum = sum;
    if (sum < minSum) minSum = sum;
  }
  return Math.abs(maxSum - minSum);
}

//sub: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/submissions/1556143388/?envType=daily-question&envId=2025-02-26
//sol: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/solutions/6470853/1749-maximum-absolute-sum-of-any-subarra-ld5t/
