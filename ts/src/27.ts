// 1408. String Matching in an Array
function stringMatching(words: string[]): string[] {
  const ans: string[] = [];

  // Iterate through all pairs of words
  for (let i = 0; i < words.length; i++) {
    for (let j = 0; j < words.length; j++) {
      // Check if words[i] is a substring of words[j]
      if (i !== j && words[j].includes(words[i])) {
        ans.push(words[i]);
        break; // Avoid duplicate entries
      }
    }
  }

  return ans;
}
