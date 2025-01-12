// 2116. Check if a Parentheses String Can Be Valid
function canBeValid(s: string, locked: string): boolean {
  const n = s.length;
  if (n % 2 === 1) return false;

  let bMin = 0,
    bMax = 0;

  for (let i = 0; i < n; i++) {
    const op = s[i] === "(";
    const wild = locked[i] === "0";

    bMin += !op || wild ? -1 : 1;
    bMax += op || wild ? 1 : -1;

    if (bMax < 0) return false;
    bMin = Math.max(bMin, 0);
  }

  return bMin === 0;
}
//sub: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/submissions/1505804211/?envType=daily-question&envId=2025-01-12
//sol: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/solutions/6267601/2116-check-if-a-parentheses-string-can-b-3rmy/
