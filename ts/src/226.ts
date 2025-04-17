//909. Snakes and Ladders

function snakesAndLadders(board: number[][]): number {
  const N = board.length;
  const mboard: number[] = [];

  // Flatten the board
  for (let i = N - 1; i >= 0; i--) {
    const row = (N - 1 - i) % 2 === 0 ? board[i] : [...board[i]].reverse();
    mboard.push(...row);
  }

  const best: (number | null)[] = new Array(N * N).fill(null);
  best[0] = 0;
  const queue: number[] = [0];

  while (queue.length > 0) {
    const current = queue.shift()!;
    for (let i = 1; i <= 6; i++) {
      let next = current + i;
      if (next >= N * N) continue;

      if (mboard[next] !== -1) {
        next = mboard[next] - 1;
      }

      if (next === N * N - 1) {
        return best[current]! + 1;
      }

      if (best[next] === null) {
        best[next] = best[current]! + 1;
        queue.push(next);
      }
    }
  }
  return -1;
}
//sub: https://leetcode.com/problems/snakes-and-ladders/submissions/1609170510/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/snakes-and-ladders/solutions/6658694/909-snakes-and-ladders-by-nalindalal2004-yi7i/
