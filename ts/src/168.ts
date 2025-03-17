//2206. Divide Array Into Equal Pairs
function divideArray(nums: number[]): boolean {
  nums.sort((a, b) => a - b); // Sort the array
  for (let i = 0; i < nums.length; i += 2) {
    if (nums[i] !== nums[i + 1]) return false;
  }
  return true;
}
//sub: https://leetcode.com/problems/divide-array-into-equal-pairs/submissions/1576403355/?envType=daily-question&envId=2025-03-17
//sol: https://leetcode.com/problems/divide-array-into-equal-pairs/solutions/6545739/2206-divide-array-into-equal-pairs-by-na-bn4y/
