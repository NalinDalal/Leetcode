//2322. Minimum Score After Removals on a Tree
function minimumScore(nums: number[], edges: number[][]): number {
  const n = nums.length;
  const tree: number[][] = Array.from({ length: n }, () => []);
  for (const [u, v] of edges) {
    tree[u].push(v);
    tree[v].push(u);
  }

  const subtreeXor = new Array(n).fill(0);
  const inTime = new Array(n).fill(0);
  const outTime = new Array(n).fill(0);
  let time = 0;

  function dfs(node: number, parent: number): void {
    subtreeXor[node] = nums[node];
    inTime[node] = time++;
    for (const nei of tree[node]) {
      if (nei !== parent) {
        dfs(nei, node);
        subtreeXor[node] ^= subtreeXor[nei];
      }
    }
    outTime[node] = time++;
  }

  function isAncestor(u: number, v: number): boolean {
    return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
  }

  dfs(0, -1);
  const totalXor = subtreeXor[0];
  let res = Number.MAX_SAFE_INTEGER;

  const directedEdges: [number, number][] = [];
  for (const [u, v] of edges) {
    if (isAncestor(u, v)) {
      directedEdges.push([v, u]); // child, parent
    } else {
      directedEdges.push([u, v]);
    }
  }

  for (let i = 0; i < directedEdges.length; i++) {
    const a = directedEdges[i][0];
    for (let j = i + 1; j < directedEdges.length; j++) {
      const b = directedEdges[j][0];

      let x = 0,
        y = 0,
        z = 0;
      if (isAncestor(a, b)) {
        x = subtreeXor[b];
        y = subtreeXor[a] ^ subtreeXor[b];
        z = totalXor ^ subtreeXor[a];
      } else if (isAncestor(b, a)) {
        x = subtreeXor[a];
        y = subtreeXor[b] ^ subtreeXor[a];
        z = totalXor ^ subtreeXor[b];
      } else {
        x = subtreeXor[a];
        y = subtreeXor[b];
        z = totalXor ^ x ^ y;
      }

      const maxVal = Math.max(x, y, z);
      const minVal = Math.min(x, y, z);
      res = Math.min(res, maxVal - minVal);
    }
  }

  return res;
}

//sub: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/submissions/1709258253/?envType=daily-question&envId=2025-07-24
//sol: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/solutions/6997315/2322-minimum-score-after-removals-on-a-t-tkhx/
