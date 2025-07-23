//1717. Maximum Score From Removing Substrings
function removeSubstr(
  s: string,
  first: string,
  second: string,
  gain: number,
): [string, number] {
  const stack: string[] = [];
  let score = 0;

  for (const char of s) {
    if (
      stack.length > 0 &&
      stack[stack.length - 1] === first &&
      char === second
    ) {
      stack.pop();
      score += gain;
    } else {
      stack.push(char);
    }
  }

  return [stack.join(""), score];
}

function maximumGain(s: string, x: number, y: number): number {
  let totalScore = 0;

  if (x > y) {
    [s, totalScore] = ((): [string, number] => {
      let score1, score2;
      [s, score1] = removeSubstr(s, "a", "b", x);
      [s, score2] = removeSubstr(s, "b", "a", y);
      return [s, score1 + score2];
    })();
  } else {
    [s, totalScore] = ((): [string, number] => {
      let score1, score2;
      [s, score1] = removeSubstr(s, "b", "a", y);
      [s, score2] = removeSubstr(s, "a", "b", x);
      return [s, score1 + score2];
    })();
  }

  return totalScore;
}

// Example:
console.log(maximumGain("cdbcbbaaabab", 4, 5)); // Output: 19

//sub: https://leetcode.com/problems/maximum-score-from-removing-substrings/submissions/1708298843/?envType=daily-question&envId=2025-07-23
//sol: https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/6994176/1717-maximum-score-from-removing-substri-excy/
