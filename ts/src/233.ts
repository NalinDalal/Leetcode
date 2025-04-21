//2145. Count the Hidden Sequences

function numberOfArrays(
  differences: number[],
  lower: number,
  upper: number,
): number {
  let prefix = 0;
  let minPrefix = 0;
  let maxPrefix = 0;

  for (let diff of differences) {
    prefix += diff;
    minPrefix = Math.min(minPrefix, prefix);
    maxPrefix = Math.max(maxPrefix, prefix);
  }

  const minStart = lower - minPrefix;
  const maxStart = upper - maxPrefix;

  const count = maxStart - minStart + 1;
  return Math.max(0, count);
}
//sub: https://leetcode.com/problems/count-the-hidden-sequences/submissions/1613038651/?envType=daily-question&envId=2025-04-21
//sol: https://leetcode.com/problems/count-the-hidden-sequences/solutions/6672485/2145-count-the-hidden-sequences-by-nalin-vi26/
