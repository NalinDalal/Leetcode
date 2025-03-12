//2529. Maximum Count of Positive Integer and Negative Integer
function maximumCount(nums: number[]): number {
  let posCnt = 0,
    negCnt = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] < 0) negCnt++;
    else if (nums[i] > 0) posCnt++;
    else continue;
  }
  return Math.max(posCnt, negCnt);
}
//sub: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/submissions/1570887900/?envType=daily-question&envId=2025-03-12
//sol: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/solutions/6526440/2529-maximum-count-of-positive-integer-a-8v3d/
