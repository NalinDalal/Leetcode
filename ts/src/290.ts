//2081. Sum of k-Mirror Numbers
function kMirror(k: number, n: number): number {
  const digit: number[] = new Array(100);
  let left = 1,
    count = 0,
    ans = 0n;
  while (count < n) {
    const right = left * 10;
    // op = 0 indicates enumerating odd-length palindromes
    // op = 1 indicates enumerating even-length palindromes
    for (let op = 0; op < 2; ++op) {
      // enumerate i'
      for (let i = left; i < right && count < n; ++i) {
        let combined = BigInt(i);
        let x = op === 0 ? Math.floor(i / 10) : i;
        while (x > 0) {
          combined = combined * 10n + BigInt(x % 10);
          x = Math.floor(x / 10);
        }
        if (isPalindrome(combined, k, digit)) {
          ++count;
          ans += combined;
        }
      }
    }
    left = right;
  }
  return Number(ans);
}

function isPalindrome(x: bigint, k: number, digit: number[]): boolean {
  let length = -1;
  while (x > 0n) {
    ++length;
    digit[length] = Number(x % BigInt(k));
    x /= BigInt(k);
  }
  for (let i = 0, j = length; i < j; ++i, --j) {
    if (digit[i] !== digit[j]) {
      return false;
    }
  }
  return true;
}
//sub: https://leetcode.com/problems/sum-of-k-mirror-numbers/submissions/1674025188/?envType=daily-question&envId=2025-06-23
//sol: https://leetcode.com/problems/sum-of-k-mirror-numbers/solutions/6877513/2081-sum-of-k-mirror-numbers-by-nalindal-jkn0/
