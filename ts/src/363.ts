//2749. Minimum Operations to Make the Integer Zero
function makeTheIntegerZero(num1: number, num2: number): number {
  for (let k = 1; k <= 60; k++) {
    const x = BigInt(num1) - BigInt(k) * BigInt(num2);
    if (x < BigInt(k)) continue;

    let ones = 0n;
    let y = x;
    while (y > 0n) {
      ones += y & 1n;
      y >>= 1n;
    }

    if (ones <= BigInt(k)) return k;
  }
  return -1;
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/submissions/1760032844/?envType=daily-question&envId=2025-09-05
//sol: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157044/2749-minimum-operations-to-make-the-inte-t23n/
