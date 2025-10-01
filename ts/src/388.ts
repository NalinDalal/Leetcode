//1518. Water Bottles
function numWaterBottles(numBottles: number, numExchange: number): number {
  let ans = numBottles;
  let empty = numBottles;

  while (empty >= numExchange) {
    const newBottles = Math.floor(empty / numExchange);
    ans += newBottles;
    empty = newBottles + (empty % numExchange);
  }

  return ans;
}
//sub: https://leetcode.com/problems/water-bottles/submissions/1787961226/?envType=daily-question&envId=2025-10-01
//sol: https://leetcode.com/problems/water-bottles/solutions/7238540/1518-water-bottles-by-nalindalal2004-504n/
