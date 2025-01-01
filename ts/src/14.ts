// 207. Course Schedule
function canFinish(numCourses: number, prerequisites: number[][]): boolean {
  // Create an adjacency list for the graph
  const graph: number[][] = Array.from({ length: numCourses }, () => []);
  for (const [a, b] of prerequisites) {
    graph[b].push(a); // Edge from b to a
  }

  // Visited states: 0 = not visited, 1 = visiting, 2 = fully processed
  const visited: number[] = new Array(numCourses).fill(0);

  // Helper function to perform DFS
  const dfs = (course: number): boolean => {
    if (visited[course] === 1) {
      // Cycle detected
      return false;
    }
    if (visited[course] === 2) {
      // Already processed, no cycle
      return true;
    }

    // Mark the course as visiting
    visited[course] = 1;

    // Visit all neighbors
    for (const neighbor of graph[course]) {
      if (!dfs(neighbor)) {
        return false;
      }
    }

    // Mark the course as fully processed
    visited[course] = 2;
    return true;
  };

  // Check all courses for cycles
  for (let i = 0; i < numCourses; ++i) {
    if (!dfs(i)) {
      return false;
    }
  }

  return true;
}

// submission: https://leetcode.com/problems/course-schedule/submissions/1493809018/
