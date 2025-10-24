//2048. Next Greater Numerically Balanced Number
function isBalanced(num: number): boolean {
  const s = num.toString();
  const freq = new Array(10).fill(0);
  for (const c of s) freq[+c]++;
  for (let d = 0; d < 10; d++) {
    if (freq[d] > 0 && freq[d] !== d) return false;
  }
  return true;
}
function nextBeautifulNumber(n: number): number {
  let i = n + 1;
  while (true) {
    if (isBalanced(i)) return i;
    i++;
  }
}
//sub: https://leetcode.com/problems/next-greater-numerically-balanced-number/submissions/1809968383/?envType=daily-question&envId=2025-10-24
//sol: https://leetcode.com/problems/next-greater-numerically-balanced-number/solutions/7296274/2048-next-greater-numerically-balanced-n-pfei/
