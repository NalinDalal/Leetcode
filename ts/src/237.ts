//2845. Count of Interesting Subarrays
function countInterestingSubarrays(
  nums: number[],
  modulo: number,
  k: number,
): number {
  const countMap = new Map<number, number>();
  countMap.set(0, 1); // Initial prefix count (like count[0] = 0)

  let count = 0;
  let result = 0;

  for (const num of nums) {
    if (num % modulo === k) {
      count++;
    }

    const key = (((count - k) % modulo) + modulo) % modulo;
    result += countMap.get(key) ?? 0;

    const modCount = count % modulo;
    countMap.set(modCount, (countMap.get(modCount) ?? 0) + 1);
  }

  return result;
}
//sub: https://leetcode.com/problems/count-of-interesting-subarrays/submissions/1617115699/?envType=daily-question&envId=2025-04-25
