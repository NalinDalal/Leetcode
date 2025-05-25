//2131. Longest Palindrome by Concatenating Two Letter Words
function longestPalindrome(words: string[]): number {
  const mpp = new Map<string, number>();

  for (const w of words) {
    mpp.set(w, (mpp.get(w) || 0) + 1);
  }

  let count = 0;
  let alreadyPalindrome = 0;

  for (const [w, freq] of mpp.entries()) {
    const reversed = w[1] + w[0];

    if (w === reversed) {
      count += Math.floor(freq / 2) * 4;
      if (freq % 2 === 1) {
        alreadyPalindrome = 1;
      }
    } else if (w < reversed && mpp.has(reversed)) {
      count += Math.min(freq, mpp.get(reversed)!) * 4;
    }
  }

  return count + alreadyPalindrome * 2;
}
//sub: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/1643722448/?envType=daily-question&envId=2025-05-25
//sol: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/solutions/6778561/2131-longest-palindrome-by-concatenating-allf/
