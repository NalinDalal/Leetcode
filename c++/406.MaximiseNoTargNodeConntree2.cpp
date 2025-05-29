/* 3373. Maximize the Number of Target Nodes After Connecting Trees II
There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and
[0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m -
1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge
between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates
that there is an edge between nodes ui and vi in the second tree.

Node u is target to node v if the number of edges on the path from u to v is
even. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible
number of nodes that are target to node i of the first tree if you had to
connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you
will remove the added edge before proceeding to the next query.



Example 1:
Input: edges1 = [[0,1],[0,2],[2,3],[2,4]],
edges2 =[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
Output: [8,7,7,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 4 from the second tree.
For i = 2, connect node 2 from the first tree to node 7 from the second tree.
For i = 3, connect node 3 from the first tree to node 0 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:
Input: edges1 = [[0,1],[0,2],[0,3],[0,4]],
edges2 = [[0,1],[1,2],[2,3]]
Output: [3,6,6,6,6]
Explanation:
For every i, connect node i of the first tree with any node of the second tree.




Constraints:
2 <= n, m <= 105
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.

*/

/* 1.Color both trees using DFS — assign each node a parity `0` or `1`.

2. Count the number of nodes in each tree that are `even` or `odd` (based on
depth).

3. For node `i` in tree 1 (color `c1[i]`):

- Connecting to any node `j` in tree 2 (color `c2[j]`) will affect the parity of
all distances.

- If `c1[i] == c2[j]`, the path parity between i and any node in the combined
tree will be preserved.

- If `c1[i] != c2[j]`, all parities flip.

- For each node `i`, choose connection to tree2 such that number of target nodes
is maximized.


*/

class Solution {
public:
  void dfs(int node, int parent, int depth, vector<vector<int>>& graph,
           vector<int>& parity, int& evenCount, int& oddCount) {
    parity[node] = depth % 2;
    if (parity[node] == 0)
      evenCount++;
    else
      oddCount++;
    for (int neighbor : graph[node]) {
      if (neighbor != parent) {
        dfs(neighbor, node, depth + 1, graph, parity, evenCount, oddCount);
      }
    }
  }

  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> graph1(n), graph2(m);
    for (auto& e : edges1) {
      graph1[e[0]].push_back(e[1]);
      graph1[e[1]].push_back(e[0]);
    }
    for (auto& e : edges2) {
      graph2[e[0]].push_back(e[1]);
      graph2[e[1]].push_back(e[0]);
    }

    vector<int> parity1(n), parity2(m);
    int even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;

    // Compute parity and counts for both trees
    dfs(0, -1, 0, graph1, parity1, even1, odd1);
    dfs(0, -1, 0, graph2, parity2, even2, odd2);

    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      if (parity1[i] == 0) {
        // same parity in tree2 -> even2 nodes remain target
        // flipped parity in tree2 -> odd2 nodes become target
        answer[i] = even1 + max(even2, odd2);
      } else {
        answer[i] = odd1 + max(even2, odd2);
      }
    }

    return answer;
  }
};
// sub:
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/submissions/1647532098/?envType=daily-question&envId=2025-05-29
// sol:
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/solutions/6791228/3373-maximize-the-number-of-target-nodes-a3ji/
