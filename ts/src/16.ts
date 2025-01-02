//210. Course Schedule

function findOrder(numCourses: number, prerequisites: number[][]): number[] {
  // Step 1: Create adjacency list and calculate indegree
  const indegree: number[] = Array(numCourses).fill(0);
  const adj: number[][] = Array.from({ length: numCourses }, () => []);

  for (const [course, prereq] of prerequisites) {
    adj[prereq].push(course); // prereq -> course
    indegree[course]++;
  }

  // Step 2: Initialize a queue with nodes having indegree 0
  const queue: number[] = [];
  for (let i = 0; i < numCourses; i++) {
    if (indegree[i] === 0) {
      queue.push(i);
    }
  }

  // Step 3: Perform topological sort
  const order: number[] = [];
  while (queue.length > 0) {
    const course = queue.shift()!; // Remove and get the first element
    order.push(course);

    // Decrease indegree of neighbors
    for (const neighbor of adj[course]) {
      indegree[neighbor]--;
      if (indegree[neighbor] === 0) {
        queue.push(neighbor);
      }
    }
  }

  // Step 4: Check if the topological sort is valid
  if (order.length === numCourses) {
    return order;
  }
  return []; // Return empty if a cycle exists
}

// submission: https://leetcode.com/problems/course-schedule-ii/submissions/1495270523/
