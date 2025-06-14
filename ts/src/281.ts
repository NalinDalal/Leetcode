//2566. Maximum Difference by Remapping a Digit
function minMaxDifference(num: number): number {
  let s = num.toString();
  let t = s;
  let pos = 0;
  while (pos < s.length && s[pos] === "9") {
    pos++;
  }
  if (pos < s.length) {
    s = s.replace(new RegExp(s[pos], "g"), "9");
  }
  t = t.replace(new RegExp(t[0], "g"), "0");
  return parseInt(s) - parseInt(t);
}
//sub: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/submissions/1663518015/?envType=daily-question&envId=2025-06-14
//sol: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/solutions/6841541/2566-maximum-difference-by-remapping-a-d-rcw2/
