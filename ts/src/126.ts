//2467. Most Profitable Path in a Tree
function mostProfitablePath(
  edges: number[][],
  bob: number,
  amount: number[],
): number {
  const n = edges.length + 1;
  const g: number[][] = Array.from({ length: n }, () => []);

  // Build graph as adjacency list
  for (const [a, b] of edges) {
    g[a].push(b);
    g[b].push(a);
  }

  // Step 1: Bob's Time of Arrival Calculation
  const ts: number[] = new Array(n).fill(n);

  const dfs1 = (i: number, fa: number, t: number): boolean => {
    if (i === 0) {
      ts[i] = t;
      return true;
    }
    for (const j of g[i]) {
      if (j !== fa && dfs1(j, i, t + 1)) {
        ts[j] = Math.min(ts[j], t + 1);
        return true;
      }
    }
    return false;
  };
  dfs1(bob, -1, 0);
  ts[bob] = 0;

  // Step 2: Alice's DFS to Find Max Profit
  let ans = Number.MIN_SAFE_INTEGER;

  const dfs2 = (i: number, fa: number, t: number, v: number): void => {
    if (t === ts[i])
      v += Math.floor(amount[i] / 2); // Split reward
    else if (t < ts[i]) v += amount[i]; // Alice reaches first

    if (g[i].length === 1 && g[i][0] === fa) {
      // Leaf node check
      ans = Math.max(ans, v);
      return;
    }
    for (const j of g[i]) {
      if (j !== fa) dfs2(j, i, t + 1, v);
    }
  };

  dfs2(0, -1, 0, 0);
  return ans;
}
//sub: https://leetcode.com/problems/most-profitable-path-in-a-tree/submissions/1553750722/?envType=daily-question&envId=2025-02-24
//sol: https://leetcode.com/problems/most-profitable-path-in-a-tree/solutions/6462305/2467-most-profitable-path-in-a-tree-by-n-5zmi/
