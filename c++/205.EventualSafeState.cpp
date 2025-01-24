/* https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24
802. Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The
graph is represented by a 0-indexed 2D integer array graph where graph[i] is an
integer array of nodes adjacent to node i, meaning there is an edge from node i
to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node
if every possible path starting from that node leads to a terminal node (or
another safe node).

Return an array containing all the safe nodes of the graph. The answer should be
sorted in ascending order.



Example 1:
Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of
them. Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5
or 6.

Example 2:
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to
node 4.


Constraints:
n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
*/

#include <vector>

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    /*// return all nofes that are safe
    // safe node- every path leads to terminal node
    // terminal node- no outgoing nodes
    // evry path from node leads to terminal node
    // so node with empty pointer is also safe
    vector<int> safe_nodes;
    for (int i = 0; i < graph.size(); i++) {
      if (graph[i].size() == 0) {
        safe_nodes.push_back(i);
      } else {
        // push nodes that are safe
        safe_nodes.push_back(graph[i][0]);
      }
      if (graph[i]->ptr->ptr == NULL) {
        safe_nodes.push_back(i);
            }
    }
    safe_nodes.sort();
    return safe_nodes;*/
    // correct:
    /* Use reverse graph traversal and topological sorting or perform a DFS with
memoization to detect nodes that are eventually safe. Terminal nodes are those
with no outgoing edges (graph[i].size() == 0). For non-terminal nodes, verify
that all paths from the node eventually lead to terminal nodes.*/
    int n = graph.size();
    vector<int> outdegree(n, 0); // Track the outdegree of each node
    vector<vector<int>> reverseGraph(
        n); // Reverse graph to perform topological sorting

    // Build the reverse graph and calculate outdegrees
    for (int i = 0; i < n; i++) {
      for (int neighbor : graph[i]) {
        reverseGraph[neighbor].push_back(i);
      }
      outdegree[i] = graph[i].size();
    }

    // Queue for nodes with zero outdegree (terminal nodes)
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (outdegree[i] == 0) {
        q.push(i);
      }
    }

    // Process the queue
    vector<int> safeNodes;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      safeNodes.push_back(node);

      // Reduce the outdegree of neighbors in the reverse graph
      for (int neighbor : reverseGraph[node]) {
        outdegree[neighbor]--;
        if (outdegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    // Sort the safe nodes before returning
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
  }
};
// sub:
// https://leetcode.com/problems/find-eventual-safe-states/submissions/1518741401/?envType=daily-question&envId=2025-01-24
// optimisation:
class Solution2 {
public:
  bool dfs(int node, vector<int>& visited, vector<int>& pathVisited,
           vector<int>& checked, vector<vector<int>>& graph) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (int nei : graph[node]) {
      if (!visited[nei]) {
        if (dfs(nei, visited, pathVisited, checked, graph)) {
          return true;
        }
      } else if (pathVisited[nei] == 1) {
        return true;
      }
    }
    checked[node] = 1;
    pathVisited[node] = 0;
    return false;
  }
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);
    vector<int> checked(n, 0);
    vector<int> safe;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, visited, pathVisited, checked, graph);
      }
    }

    for (int i = 0; i < n; i++) {
      if (checked[i] == 1)
        safe.push_back(i);
    }
    return safe;
  }
};
// 72%
// sub:
// https://leetcode.com/problems/find-eventual-safe-states/submissions/1518742456/?envType=daily-question&envId=2025-01-24
// sol:
// https://leetcode.com/problems/find-eventual-safe-states/solutions/6322808/802-find-eventual-safe-states72-by-nalin-hl0x/
