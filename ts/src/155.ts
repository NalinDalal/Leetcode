//678. Valid Parenthesis String
function checkValidString(s: string): boolean {
  let minLeft: number = 0,
    maxLeft: number = 0;

  for (let c = 0; c < s.length; c++) {
    if (s[c] == "(") {
      minLeft++;
      maxLeft++;
    } else if (s[c] == ")") {
      if (minLeft > 0) minLeft--;
      maxLeft--;
    } else if (s[c] == "*") {
      if (minLeft > 0) minLeft--; // Treat '*' as ')'
      maxLeft++; // Treat '*' as '('
    }

    if (maxLeft < 0) return false; // Too many ')' without matching '('
  }
  return minLeft == 0;
}
//sub: https://leetcode.com/problems/valid-parenthesis-string/submissions/1569755682/
//sol: https://leetcode.com/problems/valid-parenthesis-string/solutions/6522267/678-valid-parenthesis-string-by-nalindal-30s8/
