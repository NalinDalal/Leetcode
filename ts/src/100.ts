//2342. Max Sum of a Pair With Equal Sum of Digits
function sumOfDigits(num: number): number {
  let sum = 0;
  while (num > 0) {
    sum += num % 10;
    num = Math.floor(num / 10);
  }
  return sum;
}

function maximumSum(nums: number[]): number {
  const digitSumMap = new Map<number, number>(); // {sumOfDigits -> max num with that sum}
  let max_sum = -1;

  for (const num of nums) {
    const digitSum = sumOfDigits(num);

    if (digitSumMap.has(digitSum)) {
      max_sum = Math.max(max_sum, digitSumMap.get(digitSum)! + num);
    }

    digitSumMap.set(digitSum, Math.max(digitSumMap.get(digitSum) || 0, num));
  }

  return max_sum;
}

// Example usage
const nums = [51, 71, 17, 42];
console.log(maximumSum(nums)); // Output: 93 (51 + 42)
//sub: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/submissions/1540279907/?envType=daily-question&envId=2025-02-12
//sol: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/solutions/6412029/2342-max-sum-of-a-pair-with-equal-sum-of-maw0/
