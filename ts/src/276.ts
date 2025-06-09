//440. K-th Smallest in Lexicographical Order
function findKthNumber(n: number, k: number): number {
  let curr = 1;
  k--; // start from 1

  while (k > 0) {
    const steps = countSteps(n, curr, curr + 1);
    if (steps <= k) {
      curr++;
      k -= steps;
    } else {
      curr *= 10;
      k--;
    }
  }
  return curr;
}

function countSteps(n: number, curr: number, next: number): number {
  let steps = 0;
  while (curr <= n) {
    steps += Math.min(n + 1, next) - curr;
    curr *= 10;
    next *= 10;
  }
  return steps;
}

//sub: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/submissions/1658227263/?envType=daily-question&envId=2025-06-09
