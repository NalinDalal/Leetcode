//172. Factorial Trailing Zeroes

function trailingZeroes(n: number): number {
  let count: number = 0;
  while (n >= 5) {
    count += Math.floor(n / 5);
    n = Math.floor(n / 5); // Reduce n properly
  }

  return count;
}
//sub:https://leetcode.com/problems/factorial-trailing-zeroes/submissions/1587710980/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/factorial-trailing-zeroes/solutions/6584573/172-factorial-trailing-zeroes-by-nalinda-ckpm/
