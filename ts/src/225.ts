//2537. Count the Number of Good Subarrays

function countGood(nums: number[], k: number): number {
  const freq = new Map<number, number>();
  let res = 0;
  let countPairs = 0;
  let left = 0;

  for (let right = 0; right < nums.length; right++) {
    const val = nums[right];
    const prev = freq.get(val) || 0;
    countPairs += prev;
    freq.set(val, prev + 1);

    while (countPairs >= k) {
      res += nums.length - right;
      const lval = nums[left];
      const lcount = freq.get(lval)! - 1;
      freq.set(lval, lcount);
      countPairs -= lcount;
      left++;
    }
  }

  return res;
}
//sub: https://leetcode.com/problems/count-the-number-of-good-subarrays/submissions/1608088704/?envType=daily-question&envId=2025-04-16
//sol: https://leetcode.com/problems/count-the-number-of-good-subarrays/solutions/6655003/2537-count-the-number-of-good-subarrays-z0rgf/
