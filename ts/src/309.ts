//1900. The Earliest and Latest Rounds Where Players Compete
function earliestAndLatest(
  n: number,
  firstPlayer: number,
  secondPlayer: number,
): number[] {
  const memo = new Map<string, [number, number]>();

  function dfs(n: number, a: number, b: number): [number, number] {
    if (a > b) [a, b] = [b, a];
    if (a + b === n + 1) return [1, 1];

    const key = `${n},${a},${b}`;
    if (memo.has(key)) return memo.get(key)!;

    let minRound = Infinity;
    let maxRound = -Infinity;

    const half = Math.floor(n / 2);
    const totalComb = 1 << half;

    for (let mask = 0; mask < totalComb; mask++) {
      let next: number[] = [];
      let aliveA = false,
        aliveB = false;

      for (let i = 1; i <= half; i++) {
        let left = i;
        let right = n - i + 1;
        let winner = mask & (1 << (i - 1)) ? left : right;

        if (winner === a) aliveA = true;
        if (winner === b) aliveB = true;
        next.push(winner);
      }

      if (n % 2 === 1) {
        let mid = Math.floor(n / 2) + 1;
        next.push(mid);
        if (mid === a) aliveA = true;
        if (mid === b) aliveB = true;
      }

      if (!aliveA || !aliveB) continue;

      next.sort((x, y) => x - y);
      let newA = next.indexOf(a) + 1;
      let newB = next.indexOf(b) + 1;

      const [earliest, latest] = dfs(next.length, newA, newB);
      minRound = Math.min(minRound, 1 + earliest);
      maxRound = Math.max(maxRound, 1 + latest);
    }

    const result: [number, number] = [minRound, maxRound];
    memo.set(key, result);
    return result;
  }

  return dfs(n, firstPlayer, secondPlayer);
}

//sub: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/submissions/1695459248/?envType=daily-question&envId=2025-07-12
//sol: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/solutions/6950405/1900-the-earliest-and-latest-rounds-wher-knph/
