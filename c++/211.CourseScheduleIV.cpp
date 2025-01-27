/* https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27

1462. Course Schedule IV

There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course ai first if you want to take course
bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you
can take course 1. Prerequisites can also be indirect. If course a is a
prerequisite of course b, and course b is a prerequisite of course c, then
course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth
query, you should answer whether course uj is a prerequisite of course vj or
not.

Return a boolean array answer, where answer[j] is the answer to the jth query.



Example 1:
Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you
can take course 0. Course 0 is not a prerequisite of course 1, but the opposite
is true.

Example 2:
Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites, and each course is independent.

Example 3:
Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries =
[[1,0],[1,2]] Output: [true,true]


Constraints:
2 <= numCourses <= 100
0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
prerequisites[i].length == 2
0 <= ai, bi <= numCourses - 1
ai != bi
All the pairs [ai, bi] are unique.
The prerequisites graph has no cycles.
1 <= queries.length <= 104
0 <= ui, vi <= numCourses - 1
ui != vi*/

#include <vector>

// intuition:
/* Use topo sort, i.e. Kahn's algorithm.
For a directed edge (a, b) in G, a is a prerequisite course for b. For any query
(u, v) being in G or not, it is constructed a container rpath[v][u] by using an
array of bitsets to keep the computational results which is really fast.*/

// Approach
/*1. Declare `bitset<100> rpath[100]={0}; vector<char> adj[100]`
2. let `deg[100]={0}` be the indegrees for all vertices.
3. Proceed a loop over e in prerequisites, let (a, b)=e; set
`adj[a].push_back(b);// construct adjacent list
rpath[b][a]=1;      // for query (a, b)
deg[b]++;           // increase indegree for b`
4. Let `q` be the queue; it can be used `std::queue` or C-array with 2 variables
`front` & `back`
5. Add all 0 deg vertices to `q`
6. Proceed BFS as follows
```cpp
while(!q.empty()){
    auto i=q.front();// get i from the front
    q.pop();
    for(int j: adj[i]){ // adjacent vertices
        //all prerequisites for i is also prerequisites for j
        //taking or operation for 100-bit bitset
        rpath[j]|=rpath[i];
        // remove the edge, if j becomes deg 0 push it to q
        if (--deg[j]==0) q.push(j);
    }
}
```
7. All `rpath` is constructed, use a loop to give the answer
`ans[i]=rpath[queries[i][1]][queries[i][0]]`

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    bitset<100> rpath[100] = {0};
    vector<char> adj[100];

    char deg[100] = {0}; // indegree
    for (auto& e : prerequisites) {
      char a = e[0], b = e[1];
      adj[a].push_back(b);
      rpath[b][a] = 1;
      deg[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (deg[i] == 0)
        q.push(i); // deg 0 nodes

    while (!q.empty()) {
      auto i = q.front();
      q.pop();
      for (int j : adj[i]) {
        rpath[j] |= rpath[i];
        if (--deg[j] == 0)
          q.push(j);
      }
    }
    const int m = queries.size();
    vector<bool> ans(m, 0);
    for (int i = 0; i < m; i++)
      ans[i] = rpath[queries[i][1]][queries[i][0]];
    return ans;
  }
};

int main() {
  int numCourses = 2;
  vector<vector<int>> prerequisites = [[ 1, 0 ]];
  vector<vector<int>> queries = [ [ 0, 1 ], [ 1, 0 ] ];
  Solution s;
  s.checkIfPrerequisite(numCourses, prerequisites, queries);
  return 0;
}
// Time: O(n)
// Space: O(n)

// 94%
// sub:
// https://leetcode.com/problems/course-schedule-iv/submissions/1522360718/?envType=daily-question&envId=2025-01-27
// sol:
// https://leetcode.com/problems/course-schedule-iv/solutions/6336475/1462-course-schedule-iv94-by-nalindalal2-0qlu/
