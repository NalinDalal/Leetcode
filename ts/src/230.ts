//228. Summary Ranges

function summaryRanges(nums: number[]): string[] {
  const result: string[] = [];
  const n = nums.length;
  if (n === 0) return result;

  let start = nums[0];

  for (let i = 1; i <= n; i++) {
    if (i === n || nums[i] !== nums[i - 1] + 1) {
      if (start === nums[i - 1]) {
        result.push(`${start}`);
      } else {
        result.push(`${start}->${nums[i - 1]}`);
      }

      if (i < n) {
        start = nums[i];
      }
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/summary-ranges/submissions/1611108763/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/summary-ranges/solutions/6665617/228-summary-ranges-by-nalindalal2004-y2hj/
