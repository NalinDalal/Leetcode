//3100. Water Bottles II
function maxBottlesDrunk(numBottles: number, numExchange: number): number {
  let total = 0;
  let empty = 0;

  while (numBottles > 0) {
    // Drink all current bottles
    total += numBottles;
    empty += numBottles;
    numBottles = 0;

    // Exchange if possible
    if (empty >= numExchange) {
      empty -= numExchange; // use up empties
      numBottles = 1; // gain 1 new full bottle
      numExchange++; // harder next time
    }
  }

  return total;
}

//sub: https://leetcode.com/problems/water-bottles-ii/submissions/1789012886/?envType=daily-question&envId=2025-10-02
//sol: https://leetcode.com/problems/water-bottles-ii/solutions/7242122/3100-water-bottles-ii-by-nalindalal2004-1361/
