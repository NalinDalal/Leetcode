/* https://leetcode.com/problems/course-schedule/description/
* 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first
take course 1. Return true if you can finish all courses. Otherwise, return
false.


Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you
should also have finished course 1. So it is impossible.


Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.*/

// use graph;pair={a,b};edge from b to a suggest a b/f b, so b>a
// problem boils down to detecting cycles in this directed graph. If there is a
// cycle, it is impossible to finish all courses.

// Approach:
/*1. Represent the graph:
- Use an adjacency list to represent the graph.
2. Detect cycles:
- Use a depth-first search (DFS) to detect cycles. Maintain a visited array to
track the state of each node:
    - 0: Not visited.
    - 1: Visiting (currently in the DFS recursion stack).
    - 2: Visited and fully processed.
- If a node in the "visiting" state is encountered during DFS, it indicates a
cycle.
3. Return the result:
- If no cycles are detected, return true. Otherwise, return false.*/

#include <vector>

using namespace std;
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Create an adjacency list for the graph
    vector<vector<int>> graph(numCourses);
    for (const auto& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);
    }

    // Visited states: 0 = not visited, 1 = visiting, 2 = fully processed
    vector<int> visited(numCourses, 0);

    // Helper function to perform DFS
    function<bool(int)> dfs = [&](int course) {
      if (visited[course] == 1) {
        // Cycle detected
        return false;
      }
      if (visited[course] == 2) {
        // Already processed, no cycle
        return true;
      }

      // Mark the course as visiting
      visited[course] = 1;

      // Visit all neighbors
      for (int neighbor : graph[course]) {
        if (!dfs(neighbor)) {
          return false;
        }
      }

      // Mark the course as fully processed
      visited[course] = 2;
      return true;
    };

    // Check all courses for cycles
    for (int i = 0; i < numCourses; ++i) {
      if (!dfs(i)) {
        return false;
      }
    }

    return true;
  }
};

/* # Complexity

- **Time Complexity**:
  - Constructing the graph: $$O(E)$$, where \(E\) is the number of
prerequisites.
  - DFS: $$O(V + E)$$, where \(V\) is the number of courses.
  - Total: $$O(V + E)$$.

- **Space Complexity**:
  - Adjacency list: $$O(E)$$.
  - Visited array and recursion stack: $$O(V)$$.
  - Total: $$O(V + E)$$.
*/
