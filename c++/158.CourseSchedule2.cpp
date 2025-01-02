/* https://leetcode.com/problems/course-schedule-ii/description/

210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first
take course 1. Return the ordering of courses you should take to finish all
courses. If there are many valid answers, return any of them. If it is
impossible to finish all courses, return an empty array.



Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should
have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should
have finished both courses 1 and 2. Both courses 1 and 2 should be taken after
you finished course 0. So one correct course order is [0,1,2,3]. Another correct
ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]


Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct. */

// what to do:
// 1. create a grpah
// 2. find the topological sort
// 3. return the topological sort

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Create adjacency list and calculate indegree
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for (auto& p : prerequisites) {
      adj[p[1]].push_back(p[0]); // p[1] -> p[0]
      indegree[p[0]]++;
    }

    // Step 2: Initialize a queue with nodes having indegree 0
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    // Step 3: Perform topological sort
    vector<int> order;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      order.push_back(course);

      // Decrease indegree of neighbors
      for (int neighbor : adj[course]) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    // Step 4: Check if the topological sort is valid
    if (order.size() == numCourses) {
      return order;
    }
    return {}; // Return empty if cycle exists
  }
};

// Time: O(V + E), V = numCourses, E = numCourses * (numCourses - 1)
// Space: O(V)
