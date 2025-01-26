// 2127. Maximum Employees to Be Invited to a Meeting

function maximumInvitations(fav: number[]): number {
  const n = fav.length;
  const inDeg: number[] = Array(n).fill(0);
  const depth: number[] = Array(n).fill(1);

  // Step 1: Calculate in-degree for each node
  for (let i = 0; i < n; i++) {
    inDeg[fav[i]]++;
  }

  // Step 2: Add all nodes with in-degree 0 to the queue
  const q: number[] = [];
  for (let i = 0; i < n; i++) {
    if (inDeg[i] === 0) {
      q.push(i);
    }
  }

  // Step 3: Process the nodes with in-degree 0
  while (q.length > 0) {
    const cur = q.shift()!;
    const nxt = fav[cur];
    depth[nxt] = Math.max(depth[nxt], depth[cur] + 1);
    if (--inDeg[nxt] === 0) {
      q.push(nxt);
    }
  }

  // Step 4: Find the maximum cycle length and handle 2-cycles
  let maxCycle = 0;
  let twoCycleSum = 0;
  for (let i = 0; i < n; i++) {
    if (inDeg[i] === 0) continue;

    let len = 0;
    let cur = i;
    while (inDeg[cur] !== 0) {
      inDeg[cur] = 0;
      len++;
      cur = fav[cur];
    }

    if (len === 2) {
      twoCycleSum += depth[i] + depth[fav[i]];
    } else {
      maxCycle = Math.max(maxCycle, len);
    }
  }

  // Step 5: Return the maximum of maxCycle or twoCycleSum
  return Math.max(maxCycle, twoCycleSum);
}

//sub: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/submissions/1521336103/?envType=daily-question&envId=2025-01-26
//sol: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6332665/2127-maximum-employees-to-be-invited-to-p2d1h/
