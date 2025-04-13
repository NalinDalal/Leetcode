//9. Palindrome Number
function isPalindrome(x: number): boolean {
  if (x < 0) return false;
  let n: number = x;
  let sum: number = 0;
  while (n > 0) {
    sum = sum * 10 + (n % 10);
    n = Math.floor(n / 10);
  }
  return sum == x;
}
//sub: https://leetcode.com/problems/palindrome-number/submissions/1605356492/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/palindrome-number/solutions/6645490/9-palindrome-number-by-nalindalal2004-fmgc/
