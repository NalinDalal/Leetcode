//2176. Count Equal and Divisible Pairs in an Array

function countPairs(nums: number[], k: number): number {
  let pair: number = 0;
  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] == nums[j] && (i * j) % k == 0) pair++;
    }
  }

  return pair;
}
//sub: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/submissions/1609185264/?envType=daily-question&envId=2025-04-17
//sol: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/solutions/6658763/2176-count-equal-and-divisible-pairs-in-m6vth/
