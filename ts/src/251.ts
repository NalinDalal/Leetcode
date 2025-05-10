//2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

function minSum(nums1: number[], nums2: number[]): number {
  let sum1 = 0,
    sum2 = 0;
  let zero1 = 0,
    zero2 = 0;

  for (let i of nums1) {
    sum1 += i;
    if (i === 0) {
      sum1++;
      zero1++;
    }
  }

  for (let i of nums2) {
    sum2 += i;
    if (i === 0) {
      sum2++;
      zero2++;
    }
  }

  if ((zero1 === 0 && sum2 > sum1) || (zero2 === 0 && sum1 > sum2)) {
    return -1;
  }

  return Math.max(sum1, sum2);
}
//sub: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/submissions/1629708969/?envType=daily-question&envId=2025-05-10
