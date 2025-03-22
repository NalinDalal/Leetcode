//2685. Count the Number of Complete Components
function countCompleteComponents(n: number, edges: number[][]): number {
  const adj: Map<number, number[]> = new Map();
  const visited: boolean[] = new Array(n).fill(false);

  // Build adjacency list
  for (const [u, v] of edges) {
    if (!adj.has(u)) adj.set(u, []);
    if (!adj.has(v)) adj.set(v, []);
    adj.get(u)!.push(v);
    adj.get(v)!.push(u);
  }

  let count = 0;

  const dfs = (node: number, nodes: number[], edgeCount: { value: number }) => {
    visited[node] = true;
    nodes.push(node);
    for (const neighbor of adj.get(node) || []) {
      edgeCount.value++;
      if (!visited[neighbor]) {
        dfs(neighbor, nodes, edgeCount);
      }
    }
  };

  for (let i = 0; i < n; i++) {
    if (!visited[i]) {
      let nodes: number[] = [];
      let edgeCount = { value: 0 };
      dfs(i, nodes, edgeCount);

      let m = nodes.length;
      if (edgeCount.value / 2 === (m * (m - 1)) / 2) {
        count++;
      }
    }
  }
  return count;
}

// Example usage:
console.log(
  countCompleteComponents(6, [
    [0, 1],
    [0, 2],
    [1, 2],
    [3, 4],
  ]),
); // Output: 2
//sub: https://leetcode.com/problems/count-the-number-of-complete-components/submissions/1581853266/?envType=daily-question&envId=2025-03-22
//sol: https://leetcode.com/problems/count-the-number-of-complete-components/solutions/6564867/2685-count-the-number-of-complete-compon-h2tp/
