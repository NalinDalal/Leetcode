//68. Text Justification
function fullJustify(words: string[], maxWidth: number): string[] {
  const result: string[] = [];
  let currentLine: string[] = [];
  let currentLength = 0;

  for (const word of words) {
    // Check if adding the current word exceeds maxWidth
    if (currentLength + currentLine.length + word.length > maxWidth) {
      // Justify the current line and add it to the result
      result.push(buildLine(currentLine, maxWidth, false));
      currentLine = [];
      currentLength = 0;
    }

    // Add the word to the current line
    currentLine.push(word);
    currentLength += word.length;
  }

  // Handle the last line (left justified)
  if (currentLine.length > 0) {
    result.push(buildLine(currentLine, maxWidth, true));
  }

  return result;
}

function buildLine(
  words: string[],
  maxWidth: number,
  isLastLine: boolean,
): string {
  if (isLastLine || words.length === 1) {
    // Left-justify the last line or a line with only one word
    return words.join(" ") + " ".repeat(maxWidth - words.join(" ").length);
  }

  const totalSpaces =
    maxWidth - words.reduce((sum, word) => sum + word.length, 0);
  const gaps = words.length - 1;
  const spacePerGap = Math.floor(totalSpaces / gaps);
  let extraSpaces = totalSpaces % gaps;

  let line = words[0];
  for (let i = 1; i < words.length; i++) {
    const spaces = spacePerGap + (extraSpaces > 0 ? 1 : 0);
    line += " ".repeat(spaces) + words[i];
    if (extraSpaces > 0) extraSpaces--;
  }

  return line;
}
//sub: https://leetcode.com/problems/text-justification/submissions/1546841670/
//sol: https://leetcode.com/problems/text-justification/solutions/6435370/68-text-justification-by-nalindalal2004-3ozx/
