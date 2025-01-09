// 127. Word Ladder
//
function ladderLength(
  beginWord: string,
  endWord: string,
  wordList: string[],
): number {
  const wordSet: Set<string> = new Set(wordList);
  if (!wordSet.has(endWord)) return 0;

  const queue: [string, number][] = [[beginWord, 1]]; // [currentWord, transformationCount]

  while (queue.length > 0) {
    const [currentWord, level] = queue.shift()!;

    if (currentWord === endWord) return level;

    // Try all possible one-character transformations
    for (let i = 0; i < currentWord.length; i++) {
      const currentWordArray = currentWord.split("");

      for (let charCode = 97; charCode <= 122; charCode++) {
        // 'a' to 'z'
        const char = String.fromCharCode(charCode);
        currentWordArray[i] = char;
        const newWord = currentWordArray.join("");

        if (wordSet.has(newWord)) {
          queue.push([newWord, level + 1]);
          wordSet.delete(newWord); // Avoid revisiting
        }
      }
    }
  }

  return 0; // If no transformation sequence is found
}
//36.91
//https://leetcode.com/problems/word-ladder/submissions/1502746650/
