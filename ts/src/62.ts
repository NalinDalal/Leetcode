// 802. Find Eventual Safe States
function eventualSafeNodes(graph: number[][]): number[] {
  const n = graph.length;
  const outdegree = new Array<number>(n).fill(0); // Track the outdegree of each node
  const reverseGraph: number[][] = Array.from({ length: n }, () => []); // Reverse graph

  // Build the reverse graph and calculate outdegrees
  for (let i = 0; i < n; i++) {
    for (const neighbor of graph[i]) {
      reverseGraph[neighbor].push(i);
    }
    outdegree[i] = graph[i].length;
  }

  // Queue for nodes with zero outdegree (terminal nodes)
  const queue: number[] = [];
  for (let i = 0; i < n; i++) {
    if (outdegree[i] === 0) {
      queue.push(i);
    }
  }

  // Process the queue
  const safeNodes: number[] = [];
  while (queue.length > 0) {
    const node = queue.shift()!;
    safeNodes.push(node);

    // Reduce the outdegree of neighbors in the reverse graph
    for (const neighbor of reverseGraph[node]) {
      outdegree[neighbor]--;
      if (outdegree[neighbor] === 0) {
        queue.push(neighbor);
      }
    }
  }

  // Sort the safe nodes before returning
  safeNodes.sort((a, b) => a - b);
  return safeNodes;
}
//sub:https://leetcode.com/problems/find-eventual-safe-states/submissions/1518744272/?envType=daily-question&envId=2025-01-24
//sol: https://leetcode.com/problems/find-eventual-safe-states/solutions/6322808/802-find-eventual-safe-states72-by-nalin-hl0x/
