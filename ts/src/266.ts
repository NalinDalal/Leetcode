//2894. Divisible and Non-divisible Sums Difference
function differenceOfSums(n: number, m: number): number {
  let num1: number = 0,
    num2: number = 0;
  for (let i = 0; i <= n; i++) {
    if (i % m) num1 += i;
    else num2 += i;
  }
  return num1 - num2;
}
//sub: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/submissions/1645570140/?envType=daily-question&envId=2025-05-27
//sol: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/solutions/6785007/2894-divisible-and-non-divisible-sums-di-qwpv/
