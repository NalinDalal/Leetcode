//1462. Course Schedule IV
function checkIfPrerequisite(
  numCourses: number,
  prerequisites: number[][],
  queries: number[][],
): boolean[] {
  // Initialize an array of bitsets to track reachability paths
  const rpath: Array<bigint> = Array(numCourses).fill(BigInt(0));
  const adj: Array<number[]> = Array(numCourses)
    .fill(null)
    .map(() => []);
  const indegree: number[] = Array(numCourses).fill(0);

  // Build the adjacency list and the initial reachability paths
  for (const [a, b] of prerequisites) {
    adj[a].push(b);
    rpath[b] |= BigInt(1) << BigInt(a); // Mark `a` as a prerequisite for `b`
    indegree[b]++;
  }

  // Perform topological sort using Kahn's algorithm
  const queue: number[] = [];
  for (let i = 0; i < numCourses; i++) {
    if (indegree[i] === 0) queue.push(i);
  }

  while (queue.length > 0) {
    const i = queue.shift()!;
    for (const j of adj[i]) {
      rpath[j] |= rpath[i]; // Merge reachability paths
      if (--indegree[j] === 0) queue.push(j);
    }
  }

  // Process the queries
  const result: boolean[] = [];
  for (const [u, v] of queries) {
    result.push((rpath[v] & (BigInt(1) << BigInt(u))) !== BigInt(0));
  }

  return result;
}
//sub: https://leetcode.com/problems/course-schedule-iv/submissions/1522368629/?envType=daily-question&envId=2025-01-27
//sol: https://leetcode.com/problems/course-schedule-iv/solutions/6336475/1462-course-schedule-iv94-by-nalindalal2-0qlu/
