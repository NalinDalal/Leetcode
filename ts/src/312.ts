//3136. Valid Word
function isValid(word: string): boolean {
  if (word.length < 3) return false;

  let hasVowel = false,
    hasConsonant = false;
  for (const ch of word) {
    if (!/^[a-zA-Z0-9]$/.test(ch)) return false;

    if (/[a-zA-Z]/.test(ch)) {
      const lower = ch.toLowerCase();
      if ("aeiou".includes(lower)) {
        hasVowel = true;
      } else {
        hasConsonant = true;
      }
    }
  }
  return hasVowel && hasConsonant;
}
//sub: https://leetcode.com/problems/valid-word/submissions/1698428623/?envType=daily-question&envId=2025-07-15
//sol: https://leetcode.com/problems/valid-word/solutions/6960738/3136-valid-word-by-nalindalal2004-cdo5/
