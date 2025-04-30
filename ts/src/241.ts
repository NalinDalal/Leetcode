//1295. Find Numbers with Even Number of Digits

function findNumbers(nums: number[]): number {
  let ans: number = 0;
  for (let num of nums) {
    if (countDigits(num) % 2 == 0) ans++;
  }
  return ans;
}

function countDigits(num: number): number {
  let digits = 0;
  while (num) {
    num = Math.floor(num / 10);
    digits++;
  }
  return digits;
}
//sub: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/1621656663/?envType=daily-question&envId=2025-04-30
