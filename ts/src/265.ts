//1857. Largest Color Value in a Directed Graph
function largestPathValue(colors: string, edges: number[][]): number {
  const n = colors.length;
  const adj: number[][] = Array.from({ length: n }, () => []);
  const indegree: number[] = Array(n).fill(0);

  for (const [u, v] of edges) {
    adj[u].push(v);
    indegree[v]++;
  }

  const q: number[] = [];
  for (let i = 0; i < n; i++) {
    if (indegree[i] === 0) q.push(i);
  }

  const dp: number[][] = Array.from({ length: n }, () => Array(26).fill(0));
  let seen = 0;
  let ans = 0;

  while (q.length > 0) {
    const u = q.shift()!;
    seen++;
    const c = colors.charCodeAt(u) - 97;
    dp[u][c]++;
    ans = Math.max(ans, dp[u][c]);

    for (const v of adj[u]) {
      for (let k = 0; k < 26; k++) {
        dp[v][k] = Math.max(dp[v][k], dp[u][k]);
      }
      if (--indegree[v] === 0) {
        q.push(v);
      }
    }
  }

  return seen === n ? ans : -1;
}
//sub: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/submissions/1644628980/?envType=daily-question&envId=2025-05-26
