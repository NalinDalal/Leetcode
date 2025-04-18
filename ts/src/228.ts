//30. Substring with Concatenation of All Words

function findSubstring(s: string, words: string[]): number[] {
  const res: number[] = [];
  if (words.length === 0 || s.length === 0) return res;

  const wordLen = words[0].length;
  const wordCount = words.length;
  const totalLen = wordLen * wordCount;

  const wordMap = new Map<string, number>();
  for (const word of words) {
    wordMap.set(word, (wordMap.get(word) || 0) + 1);
  }

  for (let i = 0; i < wordLen; i++) {
    let left = i;
    let count = 0;
    const window = new Map<string, number>();

    for (let j = i; j + wordLen <= s.length; j += wordLen) {
      const word = s.slice(j, j + wordLen);

      if (wordMap.has(word)) {
        window.set(word, (window.get(word) || 0) + 1);
        count++;

        while ((window.get(word) || 0) > (wordMap.get(word) || 0)) {
          const leftWord = s.slice(left, left + wordLen);
          window.set(leftWord, (window.get(leftWord) || 1) - 1);
          count--;
          left += wordLen;
        }

        if (count === wordCount) {
          res.push(left);
        }
      } else {
        window.clear();
        count = 0;
        left = j + wordLen;
      }
    }
  }

  return res;
}
//sub: https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/1610121332/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/6662226/30-substring-with-concatenation-of-all-w-wzh0/
