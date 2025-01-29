/* https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29
684. Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no
cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n,
with one additional edge added. The added edge has two different vertices chosen
from 1 to n, and was not an edge that already existed. The graph is represented
as an array edges of length n where edges[i] = [ai, bi] indicates that there is
an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n
nodes. If there are multiple answers, return the answer that occurs last in the
input.



Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]


Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
*/

#include <vector>

using namespace std;

// return the edge nodes that can be removed to make the graph a tree

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1), rank(n + 1, 0);

    // Initialize each node's parent to itself
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }

    // Find function with path compression
    function<int(int)> find = [&](int node) {
      if (parent[node] != node) {
        parent[node] = find(parent[node]); // Path compression
      }
      return parent[node];
    };

    // Union function with union by rank
    auto unionSets = [&](int u, int v) {
      int rootU = find(u);
      int rootV = find(v);
      if (rootU == rootV)
        return false; // Cycle detected
      if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
      } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
      } else {
        parent[rootV] = rootU;
        rank[rootU]++;
      }
      return true;
    };

    for (const auto& edge : edges) {
      if (!unionSets(edge[0], edge[1])) {
        return edge; // The redundant edge
      }
    }

    return {}; // This should never be reached
  }
};
// Time: O(nlogn)
// Space:O(n)
// sub:
// https://leetcode.com/problems/redundant-connection/submissions/1524161427/?envType=daily-question&envId=2025-01-29
// sol:
// https://leetcode.com/problems/redundant-connection/solutions/6343501/684-redundant-connection100-by-nalindala-fhkk/
