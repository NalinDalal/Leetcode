//966. Vowel Spellchecker
function spellchecker(wordlist: string[], queries: string[]): string[] {
  const exact = new Set(wordlist);
  const caseMap = new Map<string, string>();
  const vowelMap = new Map<string, string>();

  const toLower = (s: string) => s.toLowerCase();
  const maskVowels = (s: string) => s.toLowerCase().replace(/[aeiou]/g, "*");

  // Preprocess
  for (const w of wordlist) {
    const lower = toLower(w);
    if (!caseMap.has(lower)) caseMap.set(lower, w);

    const masked = maskVowels(w);
    if (!vowelMap.has(masked)) vowelMap.set(masked, w);
  }

  const ans: string[] = [];
  for (const q of queries) {
    if (exact.has(q)) {
      ans.push(q);
    } else {
      const lower = toLower(q);
      if (caseMap.has(lower)) {
        ans.push(caseMap.get(lower)!);
      } else {
        const masked = maskVowels(q);
        if (vowelMap.has(masked)) {
          ans.push(vowelMap.get(masked)!);
        } else {
          ans.push("");
        }
      }
    }
  }
  return ans;
}

// Example usage
console.log(
  spellchecker(["YellOw"], ["yollow", "yeellow", "YellOw", "yellow"]),
);
// Output: [ 'YellOw', '', 'YellOw', 'YellOw' ]

//sub: https://leetcode.com/problems/vowel-spellchecker/submissions/1770061345/?envType=daily-question&envId=2025-09-14
//sol: https://leetcode.com/problems/vowel-spellchecker/solutions/7187589/966-vowel-spellchecker-by-nalindalal2004-m86e/
