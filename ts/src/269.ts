//2359. Find Closest Node to Given Two Nodes
function closestMeetingNode(
  edges: number[],
  node1: number,
  node2: number,
): number {
  const n = edges.length;

  function getDistances(start: number): number[] {
    const dist = new Array(n).fill(-1);
    let d = 0;
    while (start !== -1 && dist[start] === -1) {
      dist[start] = d++;
      start = edges[start];
    }
    return dist;
  }

  const dist1 = getDistances(node1);
  const dist2 = getDistances(node2);

  let minDist = Number.MAX_SAFE_INTEGER;
  let result = -1;

  for (let i = 0; i < n; i++) {
    if (dist1[i] !== -1 && dist2[i] !== -1) {
      const maxDist = Math.max(dist1[i], dist2[i]);
      if (maxDist < minDist) {
        minDist = maxDist;
        result = i;
      }
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/submissions/1648549613/
//sol: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/solutions/6794562/2359-find-closest-node-to-given-two-node-pxgb/
