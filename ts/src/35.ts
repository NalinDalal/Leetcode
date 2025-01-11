// 1400. Construct K Palindrome Strings
/* class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        if (s.length() == k)
            return true;

        int odd = 0;

        for (char chr : s)
            odd ^= (1 << (chr - 'a'));

        return __builtin_popcount(odd) <= k;
    }
};*/

function canConstruct(s: string, k: number): boolean {
  if (s.length < k) return false;
  if (s.length === k) return true;

  const charCount: Record<string, number> = {};
  for (let char of s) {
    charCount[char] = (charCount[char] || 0) + 1;
  }

  // Count the number of characters with odd frequencies.
  let oddCount = 0;
  for (const count of Object.values(charCount)) {
    if (count % 2 !== 0) {
      oddCount++;
    }
  }

  // If the number of odd-frequency characters is less than or equal to k, we can construct the palindromes.
  return oddCount <= k;
}

//sub: https://leetcode.com/problems/construct-k-palindrome-strings/submissions/1505336331/
//sol: https://leetcode.com/problems/construct-k-palindrome-strings/solutions/6266091/1400-construct-k-palindrome-strings100-b-l57i/
