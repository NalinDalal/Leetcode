//1128. Number of Equivalent Domino Pairs

function numEquivDominoPairs(dominoes: number[][]): number {
  const count = new Map<number, number>();
  let result = 0;

  for (const [a, b] of dominoes) {
    const key = a < b ? a * 10 + b : b * 10 + a; // normalize
    result += count.get(key) || 0;
    count.set(key, (count.get(key) || 0) + 1);
  }

  return result;
}
//sub: https://leetcode.com/problems/number-of-equivalent-domino-pairs/submissions/1624874490/?envType=daily-question&envId=2025-05-04
