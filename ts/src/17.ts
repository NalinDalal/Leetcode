// 2559. Count Vowel Strings in Ranges

function vowelStrings(words: string[], queries: number[][]): number[] {
  // Step 1: Function to check if a string starts and ends with vowels
  const isVowelString = (word: string): boolean => {
    const vowels = new Set(["a", "e", "i", "o", "u"]);
    const start = word[0];
    const end = word[word.length - 1];
    return vowels.has(start) && vowels.has(end);
  };

  // Step 2: Create a prefix sum array
  const n = words.length;
  const prefixSum: number[] = new Array(n + 1).fill(0);

  for (let i = 0; i < n; ++i) {
    prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
  }

  // Step 3: Process each query
  const ans: number[] = new Array(queries.length);

  for (let i = 0; i < queries.length; ++i) {
    const [left, right] = queries[i];
    ans[i] = prefixSum[right + 1] - prefixSum[left];
  }

  return ans;
}

// submission: https://leetcode.com/problems/count-vowel-strings-in-ranges/submissions/1495273908/?envType=daily-question&envId=2025-01-02
