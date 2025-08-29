//3021. Alice and Bob Playing Flower Game
function flowerGame(n: number, m: number): number {
  const oddN = Math.floor((n + 1) / 2);
  const evenN = Math.floor(n / 2);
  const oddM = Math.floor((m + 1) / 2);
  const evenM = Math.floor(m / 2);

  return oddN * evenM + evenN * oddM;
}
//sub: https://leetcode.com/problems/alice-and-bob-playing-flower-game/submissions/1751934982/?envType=daily-question&envId=2025-08-29
//sol: https://leetcode.com/problems/alice-and-bob-playing-flower-game/solutions/7133219/3021-alice-and-bob-playing-flower-game-b-na3r/
