//58. Length of Last Word
function lengthOfLastWord(s: string): number {
  let length: number = 0;
  let i: number = s.length - 1;

  while (i >= 0 && s[i] == " ") i--;

  while (i >= 0 && s[i] != " ") {
    length++;
    i--;
  }

  return length;
}
//sub: https://leetcode.com/problems/length-of-last-word/submissions/1595478748/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/length-of-last-word/solutions/6610941/58-length-of-last-word-by-nalindalal2004-yzbw/
