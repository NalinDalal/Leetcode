/* 1857. Largest Color Value in a Directed Graph
There is a directed graph of n colored nodes and m edges. The nodes are numbered
from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter
representing the color of the ith node in this graph (0-indexed). You are also
given a 2D array edges where edges[j] = [aj, bj] indicates that there is a
directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk
such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The
color value of the path is the number of nodes that are colored the most
frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if
the graph contains a cycle.



Example 1:
Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a"
(red in the above image).

Example 2:
Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.


Constraints:
n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n

Hint 1: Use topological sort.
Hint 2: let dp[u][c] := the maximum count of vertices with color c of any path
starting from vertex u. (by JerryJin2905)
*/

/* Intuition
The problem involves finding the largest color value in a directed graph where
each node has a color, and the color value of a path is the number of times the
most frequent color appears on that path. The twist is that if the graph has a
cycle, no valid path can be used, and we return -1.

Since we are dealing with a graph with colors and paths, the key ideas are:
- Use topological sorting to ensure acyclic traversal.
- Use dynamic programming to track the frequency of each color on the path
ending at each node.
*/

/*  Approach
1. Graph Construction: Build an adjacency list and compute in-degrees for
topological sorting.

2. Initialization:
    - A queue is used to perform topological sorting.
    - `dp[i][j]` will store the maximum number of times color `j` has appeared
on any path ending at node `i`.

3. Topological Processing:
    - For each node in the queue:
        - Increment its color count.
        - Update the color frequencies of its neighbors.
        - Push the neighbor into the queue if its in-degree becomes 0.

4. Cycle Detection: If the number of processed nodes (seen) is less than n, a
cycle exists.
*/

#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n);

    // Build graph and indegree count
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      indegree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (indegree[i] == 0)
        q.push(i);

    vector<array<int, 26>> dp(n);
    for (int i = 0; i < n; i++)
      dp[i].fill(0);

    int seen = 0, ans = 0;

    // Topological traversal
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      seen++;
      int c = colors[u] - 'a';
      dp[u][c]++;
      ans = max(ans, dp[u][c]);

      for (int v : adj[u]) {
        for (int k = 0; k < 26; k++)
          dp[v][k] = max(dp[v][k], dp[u][k]);
        if (--indegree[v] == 0)
          q.push(v);
      }
    }

    // If not all nodes were visited, there is a cycle
    return seen == n ? ans : -1;
  }
};
// sub:
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/submissions/1644625730/?envType=daily-question&envId=2025-05-26
