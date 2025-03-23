//135. Candy
function candy(ratings: number[]): number {
  const n = ratings.length;
  if (n === 0) return 0;

  const candies: number[] = new Array(n).fill(1);

  // Left to Right pass
  for (let i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  // Right to Left pass
  for (let i = n - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = Math.max(candies[i], candies[i + 1] + 1);
    }
  }

  // Sum up candies
  return candies.reduce((sum, c) => sum + c, 0);
}
//sub: https://leetcode.com/problems/candy/submissions/1583189609/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/candy/solutions/6569867/135-candy-by-nalindalal2004-rwuo/
