//136. Single Number
function singleNumber(nums: number[]): number {
  let result = 0;
  for (let num of nums) {
    result ^= num;
  }
  return result;
}
//sub: https://leetcode.com/problems/single-number/submissions/1576382396/
//sol: https://leetcode.com/problems/single-number/solutions/6545649/136-single-number-by-nalindalal2004-5sfc/
