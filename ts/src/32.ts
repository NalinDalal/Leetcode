// 916. Word Subsets

function wordSubsets(words1: string[], words2: string[]): string[] {
  // Helper function to count character frequencies
  const getCharFrequency = (word: string): number[] => {
    const freq = new Array(26).fill(0);
    for (const char of word) {
      freq[char.charCodeAt(0) - 97]++;
    }
    return freq;
  };

  // Step 1: Compute the maximum character frequency needed for all words in words2
  const maxFreq = new Array(26).fill(0);
  for (const word of words2) {
    const freq = getCharFrequency(word);
    for (let i = 0; i < 26; i++) {
      maxFreq[i] = Math.max(maxFreq[i], freq[i]);
    }
  }

  // Step 2: Filter words1 to include only universal words
  const result: string[] = [];
  for (const word of words1) {
    const freq = getCharFrequency(word);
    let isUniversal = true;
    for (let i = 0; i < 26; i++) {
      if (freq[i] < maxFreq[i]) {
        isUniversal = false;
        break;
      }
    }
    if (isUniversal) {
      result.push(word);
    }
  }

  return result;
}

// sub: https://leetcode.com/problems/word-subsets/submissions/1504022227/
