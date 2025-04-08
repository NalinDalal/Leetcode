//3396. Minimum Number of Operations to Make Elements in Array Distinct
function minimumOperations(nums: number[]): number {
  let ops = 0;
  let start = 0;

  while (start < nums.length) {
    const seen = new Set<number>();
    let hasDuplicates = false;

    for (let i = start; i < nums.length; i++) {
      if (seen.has(nums[i])) {
        hasDuplicates = true;
        break;
      }
      seen.add(nums[i]);
    }

    if (!hasDuplicates) break;

    start += 3;
    ops++;
  }

  return ops;
}
//sub: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/submissions/1600177839/?envType=daily-question&envId=2025-04-08
//sol: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/solutions/6627455/3396-minimum-number-of-operations-to-mak-4fwt/
