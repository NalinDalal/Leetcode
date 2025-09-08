//1317. Convert Integer to the Sum of Two No-Zero Integers
function getNoZeroIntegers(n: number): number[] {
  for (let i = 1; i < n; i++) {
    let a = i,
      b = n - i;
    if (isNoZero(a) && isNoZero(b)) {
      return [a, b];
    }
  }
  return [];
}

function isNoZero(x: number): boolean {
  while (x > 0) {
    if (x % 10 === 0) return false;
    x = Math.floor(x / 10);
  }
  return true;
}
//sub: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/1763232492/?envType=daily-question&envId=2025-09-08
//sol: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/solutions/7167137/1317-convert-integer-to-the-sum-of-two-n-7mop/
