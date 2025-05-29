//3373. Maximize the Number of Target Nodes After Connecting Trees II

function maxTargetNodes(edges1: number[][], edges2: number[][]): number[] {
  const n = edges1.length + 1;
  const m = edges2.length + 1;

  const buildGraph = (edges: number[][], size: number): number[][] => {
    const graph: number[][] = Array.from({ length: size }, () => []);
    for (const [u, v] of edges) {
      graph[u].push(v);
      graph[v].push(u);
    }
    return graph;
  };

  const dfs = (
    node: number,
    parent: number,
    depth: number,
    graph: number[][],
    parity: number[],
  ): [number, number] => {
    parity[node] = depth % 2;
    let even = parity[node] === 0 ? 1 : 0;
    let odd = parity[node] === 1 ? 1 : 0;

    for (const neighbor of graph[node]) {
      if (neighbor !== parent) {
        const [e, o] = dfs(neighbor, node, depth + 1, graph, parity);
        even += e;
        odd += o;
      }
    }
    return [even, odd];
  };

  const graph1 = buildGraph(edges1, n);
  const graph2 = buildGraph(edges2, m);

  const parity1: number[] = new Array(n).fill(0);
  const parity2: number[] = new Array(m).fill(0);

  const [even1, odd1] = dfs(0, -1, 0, graph1, parity1);
  const [even2, odd2] = dfs(0, -1, 0, graph2, parity2);

  const result: number[] = [];

  for (let i = 0; i < n; ++i) {
    if (parity1[i] === 0) {
      result[i] = even1 + Math.max(even2, odd2);
    } else {
      result[i] = odd1 + Math.max(even2, odd2);
    }
  }

  return result;
}

//sub: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/submissions/1647533044/?envType=daily-question&envId=2025-05-29
//sol: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/solutions/6791228/3373-maximize-the-number-of-target-nodes-a3ji/
