//2598. Smallest Missing Non-negative Integer After Operations
function findSmallestInteger(nums: number[], value: number): number {
  const freq = new Map<number, number>();

  // Count frequency of each remainder (normalized to 0..value-1)
  for (const x of nums) {
    const r = ((x % value) + value) % value; // handle negatives
    freq.set(r, (freq.get(r) ?? 0) + 1);
  }

  let m = 0;
  while (true) {
    const r = m % value;
    const count = freq.get(r) ?? 0;

    if (count === 0) return m; // can't represent this number

    // consume one number with this remainder
    freq.set(r, count - 1);
    m++;
  }
}

//sub: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/submissions/1803123106/?envType=daily-question&envId=2025-10-16
//sol: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/solutions/7279095/2598-smallest-missing-non-negative-integ-xvdp/
