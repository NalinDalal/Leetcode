//1716. Calculate Money in Leetcode Bank
function totalMoney(n: number): number {
  const weeks = Math.floor(n / 7);
  const rem = n % 7;

  let total = (7 * (weeks * (weeks + 1))) / 2 + 21 * weeks;
  total += rem * (weeks + 1) + (rem * (rem - 1)) / 2;

  return total;
}
//sub: https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/1811538043/?envType=daily-question&envId=2025-10-25
//sol: https://leetcode.com/problems/calculate-money-in-leetcode-bank/solutions/7300975/1716-calculate-money-in-leetcode-bank-by-ipit/
