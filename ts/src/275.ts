//386. Lexicographical Numbers
function lexicalOrder(n: number): number[] {
  const result: number[] = [];

  function dfs(current: number) {
    if (current > n) return;
    result.push(current);
    for (let i = 0; i <= 9; i++) {
      const next = current * 10 + i;
      if (next > n) return;
      dfs(next);
    }
  }

  for (let i = 1; i <= 9; i++) {
    dfs(i);
  }

  return result;
}
//sub: https://leetcode.com/problems/lexicographical-numbers/submissions/1657349156/
//sol: https://leetcode.com/problems/lexicographical-numbers/solutions/6822214/386-lexicographical-numbers/
