//1957. Delete Characters to Make Fancy String
function makeFancyString(s: string): string {
  let ans: string = "";
  for (let i = 0; i < s.length; i++) {
    if (i == s.length - 1 || s[i] != s[i + 1] || s[i] != s[i + 2]) ans += s[i];
  }
  return ans;
}
//sub: https://leetcode.com/problems/delete-characters-to-make-fancy-string/submissions/1705464734/?envType=daily-question&envId=2025-07-21
//sol: https://leetcode.com/problems/delete-characters-to-make-fancy-string/solutions/6984194/1957-delete-characters-to-make-fancy-str-jh4p/
