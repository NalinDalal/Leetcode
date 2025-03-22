/*2685. Count the Number of Complete Components

You are given an integer n. There is an undirected graph with n vertices,
numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i]
= [ai, bi] denotes that there exists an undirected edge connecting vertices ai
and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path
between any two vertices, and no vertex of the subgraph shares an edge with a
vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between
every pair of its vertices.

Example 1:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of
this graph are complete.

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since
there is an edge between every pair of two vertices. On the other hand, the
component containing vertices 3, 4, and 5 is not complete since there is no edge
between vertices 4 and 5. Thus, the number of complete components in this graph
is 1.


Constraints:
1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.

Hint 1: Find the connected components of an undirected graph using depth-first
search (DFS) or breadth-first search (BFS). Hint 2: For each connected
component, count the number of nodes and edges in the component. Hint 3: A
connected component is complete if and only if the number of edges in the
component is equal to m*(m-1)/2, where m is the number of nodes in the
component.
*/

// Use DFS to find all connected componetns
// check if each of components is complete graph or not

// Approach:
/* 1.Use Adjacency list to store graph, and traverse using BFS/DFS.
 2.Check components completeness using `e == m * (m - 1) / 2`; e-no of edges,
 m-no of nodes
 3. count no of complete component.
*/

// Time: O(n)
// Space: O(n)
class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Build adjacency list
    for (auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    int count = 0;

    function<void(int, vector<int>&, int&)> dfs =
        [&](int node, vector<int>& nodes, int& edgeCount) {
          visited[node] = true;
          nodes.push_back(node);
          for (int neighbor : adj[node]) {
            edgeCount++;
            if (!visited[neighbor]) {
              dfs(neighbor, nodes, edgeCount);
            }
          }
        };

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<int> nodes;
        int edgeCount = 0;
        dfs(i, nodes, edgeCount);

        int m = nodes.size();
        if (edgeCount / 2 == m * (m - 1) / 2) {
          count++;
        }
      }
    }
    return count;
  }
};
// sub:
// https://leetcode.com/problems/count-the-number-of-complete-components/submissions/1581851897/?envType=daily-question&envId=2025-03-22
// sol:
// https://leetcode.com/problems/count-the-number-of-complete-components/solutions/6564867/2685-count-the-number-of-complete-compon-h2tp/
