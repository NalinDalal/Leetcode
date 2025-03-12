//268. Missing Number
function missingNumber(nums: number[]): number {
  let n = nums.length;
  let expectedSum = (n * (n + 1)) / 2;
  let actualSum = 0;
  for (let num of nums) actualSum += num;
  return expectedSum - actualSum;
}

//sub: https://leetcode.com/problems/missing-number/submissions/1570880105/
//sol: https://leetcode.com/problems/missing-number/solutions/6526404/268-missing-number-by-nalindalal2004-hpbp/
