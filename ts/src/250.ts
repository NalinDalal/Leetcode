//3343. Count Number of Balanced Permutations

const MOD = 1_000_000_007n;

function countBalancedPermutations(num: string): number {
  const n = num.length;
  const cnt = Array(10).fill(0);
  let tot = 0;

  for (const ch of num) {
    const d = Number(ch);
    cnt[d]++;
    tot += d;
  }

  if (tot % 2 !== 0) return 0;

  const target = tot / 2;
  const maxOdd = Math.ceil(n / 2);

  // Combinations using Pascal's triangle
  const comb: bigint[][] = Array.from({ length: maxOdd + 1 }, (_, i) =>
    Array.from({ length: maxOdd + 1 }, (_, j) =>
      i === j || j === 0 ? 1n : 0n,
    ),
  );

  for (let i = 1; i <= maxOdd; i++) {
    for (let j = 1; j < i; j++) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
  }

  const psum = Array(11).fill(0);
  for (let i = 9; i >= 0; i--) {
    psum[i] = psum[i + 1] + cnt[i];
  }

  const memo = new Map<string, bigint>();

  function dfs(pos: number, curr: number, oddCnt: number): bigint {
    if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) return 0n;
    if (pos > 9) return curr === target && oddCnt === 0 ? 1n : 0n;

    const key = `${pos},${curr},${oddCnt}`;
    if (memo.has(key)) return memo.get(key)!;

    const evenCnt = psum[pos] - oddCnt;
    let res = 0n;

    for (
      let i = Math.max(0, cnt[pos] - evenCnt);
      i <= Math.min(cnt[pos], oddCnt);
      i++
    ) {
      const ways = (comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i]) % MOD;
      const sub = dfs(pos + 1, curr + i * pos, oddCnt - i);
      res = (res + ((ways * sub) % MOD)) % MOD;
    }

    memo.set(key, res);
    return res;
  }

  return Number(dfs(0, 0, maxOdd));
}

//sub: https://leetcode.com/problems/count-number-of-balanced-permutations/submissions/1629301569/?envType=daily-question&envId=2025-05-09
