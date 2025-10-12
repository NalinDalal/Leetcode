//3539. Find Sum of Array Product of Magical Sequences
function magicalSum(m: number, k: number, nums: number[]): number {
  const MOD = BigInt(1000000007);
  const M = m;
  const K = k;
  const n = nums.length;

  // factorials and inverse factorials (BigInt)
  const fact: bigint[] = Array(M + 1).fill(0n);
  const invfact: bigint[] = Array(M + 1).fill(0n);
  fact[0] = 1n;
  for (let i = 1; i <= M; ++i) fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
  const modPow = (base: bigint, exp: bigint) => {
    let b = base % MOD;
    let e = exp;
    let r = 1n;
    while (e > 0n) {
      if (e & 1n) r = (r * b) % MOD;
      b = (b * b) % MOD;
      e >>= 1n;
    }
    return r;
  };
  invfact[M] = modPow(fact[M], BigInt(Number(MOD - 2n))); // Fermat
  for (let i = M; i >= 1; --i) invfact[i - 1] = (invfact[i] * BigInt(i)) % MOD;

  // pow_nums[pos][c] = nums[pos]^c % MOD
  const pow_nums: bigint[][] = Array(n);
  for (let i = 0; i < n; ++i) {
    pow_nums[i] = Array(M + 1).fill(0n);
    pow_nums[i][0] = 1n;
    const val = BigInt(nums[i]) % MOD;
    for (let c = 1; c <= M; ++c)
      pow_nums[i][c] = (pow_nums[i][c - 1] * val) % MOD;
  }

  // extra bits to let carries die out
  const extra = Math.floor(Math.log2(Math.max(1, M))) + 3; // safe margin
  const total_bits = n + extra;

  // dp[used][carry][ones] = bigint
  const dp: bigint[][][] = Array(M + 1);
  for (let u = 0; u <= M; ++u) {
    dp[u] = Array(M + 1);
    for (let c = 0; c <= M; ++c) {
      dp[u][c] = Array(K + 1).fill(0n);
    }
  }
  dp[0][0][0] = 1n;

  for (let pos = 0; pos < total_bits; ++pos) {
    const ndp: bigint[][][] = Array(M + 1);
    for (let u = 0; u <= M; ++u) {
      ndp[u] = Array(M + 1);
      for (let c = 0; c <= M; ++c) ndp[u][c] = Array(K + 1).fill(0n);
    }

    for (let used = 0; used <= M; ++used) {
      for (let carry = 0; carry <= M; ++carry) {
        for (let ones = 0; ones <= K; ++ones) {
          const cur = dp[used][carry][ones];
          if (cur === 0n) continue;
          const maxc = pos < n ? M - used : 0;
          for (let take = 0; take <= maxc; ++take) {
            const total = carry + take;
            const bit = total & 1;
            const carryNext = total >> 1;
            if (carryNext > M) continue;
            const onesNext = ones + bit;
            if (onesNext > K) continue;

            // weight multiplier = nums[pos]^take * invfact[take]
            let mult = cur;
            if (take > 0) {
              mult = (mult * pow_nums[pos][take]) % MOD;
              mult = (mult * invfact[take]) % MOD;
            }
            ndp[used + take][carryNext][onesNext] =
              (ndp[used + take][carryNext][onesNext] + mult) % MOD;
          }
        }
      }
    }
    // swap
    for (let u = 0; u <= M; ++u) {
      for (let c = 0; c <= M; ++c) {
        for (let o = 0; o <= K; ++o) dp[u][c][o] = ndp[u][c][o];
      }
    }
  }

  const ans_unordered = dp[M][0][K];
  const ans = (ans_unordered * fact[M]) % MOD;
  // return as number (fits in 32-bit mod)
  return Number(ans);
}

//sub: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/submissions/1799128322/?envType=daily-question&envId=2025-10-12
//sol: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/solutions/7268694/3539-find-sum-of-array-product-of-magica-0509/
