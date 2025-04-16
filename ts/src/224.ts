//137. Single Number II

function singleNumber(nums: number[]): number {
  let ones = 0;
  let twos = 0;

  for (const num of nums) {
    ones ^= num & ~twos;
    twos ^= num & ~ones;
  }

  return ones;
}
//sub: https://leetcode.com/problems/single-number-ii/submissions/1608079307/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/single-number-ii/solutions/6654971/137-single-number-ii-by-nalindalal2004-u5qy/
