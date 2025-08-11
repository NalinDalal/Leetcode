//2438. Range Product Queries of Powers
function productQueries(n: number, queries: number[][]): number[] {
  const MOD = 1000000007n;

  // 1) extract powers of two (as BigInt)
  const powers: bigint[] = [];
  let nb = BigInt(n);
  let cur = 1n;
  while (nb > 0n) {
    if ((nb & 1n) === 1n) powers.push(cur);
    cur <<= 1n;
    nb >>= 1n;
  }

  // 2) prefix products modulo MOD (BigInt)
  const prefix: bigint[] = [1n];
  for (const p of powers) {
    prefix.push((prefix[prefix.length - 1] * p) % MOD);
  }

  // 3) fast pow for BigInt (modular exponentiation)
  const modPow = (base: bigint, exp: bigint): bigint => {
    let b = base % MOD;
    let e = exp;
    let res = 1n;
    while (e > 0n) {
      if ((e & 1n) === 1n) res = (res * b) % MOD;
      b = (b * b) % MOD;
      e >>= 1n;
    }
    return res;
  };

  // 4) answer queries using modular inverse (a^(MOD-2) % MOD)
  const res: number[] = [];
  for (const [L, R] of queries) {
    const numerator = prefix[R + 1];
    const denomInv = modPow(prefix[L], MOD - 2n);
    const prod = (numerator * denomInv) % MOD;
    // safe to convert to Number because prod < MOD (1e9+7)
    res.push(Number(prod));
  }
  return res;
}





//sub: https://leetcode.com/problems/range-product-queries-of-powers/submissions/1730704111/?envType=daily-question&envId=2025-08-11
//sol: https://leetcode.com/problems/range-product-queries-of-powers/solutions/7066250/2438-range-product-queries-of-powers-by-lr4bn/
