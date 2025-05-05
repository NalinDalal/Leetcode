//790. Domino and Tromino Tiling
const mod = 1e9 + 7;

function numTilings(n: number): number {
  const a = [1, 1, 2];
  if (n < 3) return a[n];

  let [a0, a1, a2] = a;
  for (let i = 3; i <= n; i++) {
    const x = (2 * a2 + a0) % mod;
    [a0, a1, a2] = [a1, a2, x];
  }

  return a2;
}
//sub: https://leetcode.com/problems/domino-and-tromino-tiling/submissions/1625824630/?envType=daily-question&envId=2025-05-05
