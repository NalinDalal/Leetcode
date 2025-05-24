//2942. Find Words Containing Character

function findWordsContaining(words: string[], x: string): number[] {
  const result: number[] = [];
  for (let i = 0; i < words.length; i++) {
    if (words[i].includes(x)) {
      result.push(i);
    }
  }
  return result;
}

// Example usage
const words = ["apple", "banana", "cherry"];
const x = "a";
console.log(findWordsContaining(words, x)); // Output: [0, 1]
//sub:https://leetcode.com/problems/find-words-containing-character/submissions/1642682319/?envType=daily-question&envId=2025-05-24
//sol:https://leetcode.com/problems/find-words-containing-character/solutions/6775087/2942-find-words-containing-character-by-00nq4/
