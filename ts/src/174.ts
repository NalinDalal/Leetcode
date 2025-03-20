//3108. Minimum Cost Walk in Weighted Graph
class DSU {
  parent: number[];
  depth: number[];

  constructor(n: number) {
    this.parent = new Array(n).fill(-1);
    this.depth = new Array(n).fill(0);
  }

  find(node: number): number {
    if (this.parent[node] === -1) return node;
    return (this.parent[node] = this.find(this.parent[node])); // Path compression
  }

  union(node1: number, node2: number): void {
    let root1 = this.find(node1);
    let root2 = this.find(node2);

    if (root1 === root2) return;

    // Union by depth
    if (this.depth[root1] < this.depth[root2]) [root1, root2] = [root2, root1];

    this.parent[root2] = root1;
    if (this.depth[root1] === this.depth[root2]) this.depth[root1]++;
  }
}

function minimumCost(
  n: number,
  edges: number[][],
  queries: number[][],
): number[] {
  const dsu = new DSU(n);
  const componentCost = new Array<number>(n).fill(~0); // Equivalent to -1 in unsigned representation

  // Build connected components
  for (const [u, v] of edges) {
    dsu.union(u, v);
  }

  // Compute the AND-weight for each component
  for (const [u, v, w] of edges) {
    const root = dsu.find(u);
    componentCost[root] &= w;
  }

  // Answer queries
  return queries.map(([s, t]) =>
    dsu.find(s) === dsu.find(t) ? componentCost[dsu.find(s)] : -1,
  );
}

//sub: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/submissions/1579683649/?envType=daily-question&envId=2025-03-20
//sol: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/solutions/6557565/3108-minimum-cost-walk-in-weighted-graph-gbwo/
