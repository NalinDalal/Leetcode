//743. Network Delay Time
function networkDelayTime(times: number[][], n: number, k: number): number {
  const graph: Map<number, [number, number][]> = new Map();

  // Build adjacency list
  for (const [u, v, w] of times) {
    if (!graph.has(u)) graph.set(u, []);
    graph.get(u)!.push([v, w]);
  }

  // Min-heap (priority queue) using a custom comparator
  const pq: [number, number][] = []; // [time, node]
  pq.push([0, k]);

  const dist: Map<number, number> = new Map();
  dist.set(k, 0);

  while (pq.length > 0) {
    pq.sort((a, b) => a[0] - b[0]); // Sort to get the smallest time first
    const [time, node] = pq.shift()!;

    if (!graph.has(node)) continue;

    for (const [neighbor, weight] of graph.get(node)!) {
      const newTime = time + weight;
      if (!dist.has(neighbor) || newTime < dist.get(neighbor)!) {
        dist.set(neighbor, newTime);
        pq.push([newTime, neighbor]);
      }
    }
  }

  if (dist.size !== n) return -1; // Not all nodes are reachable
  return Math.max(...dist.values());
}
//sub: https://leetcode.com/problems/network-delay-time/submissions/1544792298/
//sol: https://leetcode.com/problems/network-delay-time/solutions/6428388/743-network-delay-time-by-nalindalal2004-nvts/
