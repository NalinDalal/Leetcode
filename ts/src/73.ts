//https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29
//684. Redundant Connection
function findRedundantConnection(edges: number[][]): number[] {
  const n = edges.length;
  const parent: number[] = Array(n + 1)
    .fill(0)
    .map((_, i) => i);
  const rank: number[] = Array(n + 1).fill(0);

  // Find function with path compression
  const find = (node: number): number => {
    if (parent[node] !== node) {
      parent[node] = find(parent[node]); // Path compression
    }
    return parent[node];
  };

  // Union function with union by rank
  const unionSets = (u: number, v: number): boolean => {
    const rootU = find(u);
    const rootV = find(v);
    if (rootU === rootV) return false; // Cycle detected

    if (rank[rootU] > rank[rootV]) {
      parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
      parent[rootU] = rootV;
    } else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
    return true;
  };

  for (const [u, v] of edges) {
    if (!unionSets(u, v)) {
      return [u, v]; // The redundant edge
    }
  }

  return []; // This should never be reached
}
//sub: https://leetcode.com/problems/redundant-connection/submissions/1524163708/?envType=daily-question&envId=2025-01-29
//sol:https://leetcode.com/problems/redundant-connection/solutions/6343501/684-redundant-connection100-by-nalindala-fhkk/
