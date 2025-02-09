function majorityElement(nums: number[]): number {
  let candidate = 0,
    count = 0;

  for (const num of nums) {
    if (count === 0) {
      candidate = num;
    }
    count += num === candidate ? 1 : -1;
  }

  return candidate;
}
//sub: https://leetcode.com/problems/majority-element/submissions/1536829135/
//sol: https://leetcode.com/problems/majority-element/solutions/6397472/169-majority-element-by-nalindalal2004-ej27/
