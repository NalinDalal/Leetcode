//17. Letter Combinations of a Phone Number
function letterCombinations(digits: string): string[] {
  if (!digits.length) return [];

  const digitToLetters: string[] = [
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
  ];

  let res: string[] = [""];

  for (const digit of digits) {
    const letters = digitToLetters[parseInt(digit)];
    const temp: string[] = [];

    for (const combination of res) {
      for (const letter of letters) {
        temp.push(combination + letter);
      }
    }

    res = temp; // Update res with the new combinations
  }

  return res;
}
//sub: https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1531291584/
//sol: https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/6375024/17-letter-combinations-of-a-phone-number-0sdm/
