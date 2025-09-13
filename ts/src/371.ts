//3541. Find Most Frequent Vowel and Consonant
function maxFreqSum(s: string): number {
  const freq: Record<string, number> = {};

  for (const ch of s.toLowerCase()) {
    if (/[a-z]/.test(ch)) {
      freq[ch] = (freq[ch] || 0) + 1;
    }
  }

  const isVowel = (c: string) => "aeiou".includes(c);

  let maxVowel = 0;
  let maxConsonant = 0;

  for (const [ch, count] of Object.entries(freq)) {
    if (isVowel(ch)) {
      maxVowel = Math.max(maxVowel, count);
    } else {
      maxConsonant = Math.max(maxConsonant, count);
    }
  }

  return maxVowel + maxConsonant;
}
//sub: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/submissions/1768790793/?envType=daily-question&envId=2025-09-13
//sol: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/7183971/3541-find-most-frequent-vowel-and-conson-9rwe/
