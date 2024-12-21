/* 2872. Maximum Number of K-Divisible Components

There is an undirected tree with n nodes labeled from 0 to n - 1. You are given
the integer n and a 2D integer array edges of length n - 1, where edges[i] =
[ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i]
is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly
empty, from the tree such that the resulting components all have values that are
divisible by k, where the value of a connected component is the sum of the
values of its nodes.

Return the maximum number of components in any valid split.


Example 1:
Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
Output: 2
Explanation: We remove the edge connecting node 1 with 2. The resulting split is
valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3]
= 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] +
values[2] + values[4] = 6. It can be shown that no other valid split has more
than 2 connected components.

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values =
[3,0,6,1,5,2,1], k = 3 Output: 3 Explanation: We remove the edge connecting node
0 with 2, and the edge connecting node 0 with 1. The resulting split is valid
because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] +
values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] +
values[3] + values[4] = 6. It can be shown that no other valid split has more
than 3 connected components.


Constraints:
1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
0 <= values[i] <= 109
1 <= k <= 109
Sum of values is divisible by k.
The input is generated such that edges represents a valid tree.*/

// Intuition:
// We are given a tree with nodes having integer values. We need to find the
// number of subtrees in the tree such that the sum of values in each subtree is
// divisible by 'k'. We can solve this problem using Depth-First Search (DFS) to
// traverse the tree.

// Approach:
/* Initialize a count `cnt` to keep track of the number of k-divisible
components. Build an adjacency list representation of the tree. Start DFS from
the root node (node 0) and traverse the tree. In the DFS function:
- a. Initialize `sum` with the value of the current node.
- b. Traverse through the adjacent nodes and recursively calculate the sum of
values for the subtree rooted at each adjacent node.
- c. Check if `sum` is divisible by `k`. If it is, increment `cnt`
to count the k-divisible component and return 0 to indicate that this subtree is
k-divisible.
- d. Otherwise, return 'sum' as the sum of values for this subtree.

Finally, return 'cnt' as the count of k-divisible components in the tree.*/
class Solution {
public:
  long long dfs(int& ans, vector<int>& values, int node, int prevNode,
                unordered_map<int, list<int>>& adj, int& k) {

    long long sum = values[node];
    for (auto it : adj[node]) {
      if (it == prevNode)
        continue;
      sum += dfs(ans, values, it, node, adj, k);
    }
    if (sum % k == 0) {
      ans++;
      return 0;
    } else
      return (long long)sum;
  }
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                              vector<int>& values, int k) {
    unordered_map<int, list<int>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int cnt = 0;
    dfs(cnt, values, 0, -1, adj, k);
    return cnt;
  }
};

// Time Complexity: O(n) n-no of nodes
// space complexity: O(n)
// 50%
