//1922. Count Good Numbers

const MOD = BigInt(1_000_000_007);

function power(base: bigint, exp: bigint): bigint {
  let result = BigInt(1);
  base = base % MOD;

  while (exp > 0) {
    if (exp % BigInt(2) === BigInt(1)) {
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
    exp = exp / BigInt(2);
  }

  return result;
}

function countGoodNumbers(n: number): number {
  const even = BigInt(Math.ceil(n / 2));
  const odd = BigInt(Math.floor(n / 2));

  const goodCount = (power(BigInt(5), even) * power(BigInt(4), odd)) % MOD;
  return Number(goodCount);
}
//sub:https://leetcode.com/problems/count-good-numbers/submissions/1605365164/?envType=daily-question&envId=2025-04-13
//sol: https://leetcode.com/problems/count-good-numbers/solutions/6645571/1922-count-good-numbers-by-nalindalal200-994j/
