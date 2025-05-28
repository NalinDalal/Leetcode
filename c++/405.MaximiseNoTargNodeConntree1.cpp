/* 3372. Maximize the Number of Target Nodes After Connecting Trees I
There exist two undirected trees with n and m nodes, with distinct labels in
ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m -
1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge
between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates
that there is an edge between nodes ui and vi in the second tree. You are also
given an integer k.

Node u is target to node v if the number of edges on the path from u to v is
less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible
number of nodes target to node i of the first tree if you have to connect one
node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you
will remove the added edge before proceeding to the next query.



Example 1:
Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 =
[[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2 Output: [9,7,9,8,8]
Explanation:
For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 0 from the second tree.
For i = 2, connect node 2 from the first tree to node 4 from the second tree.
For i = 3, connect node 3 from the first tree to node 4 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:
Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
Output: [6,3,3,3,3]
Explanation:
For every i, connect node i of the first tree with any node of the second tree.



Constraints:
2 <= n, m <= 1000
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
0 <= k <= 1000

Hint 1
For each node u in the first tree, find the number of nodes at a distance of at
most k from node u. Hint 2 For each node v in the second tree, find the number
of nodes at a distance of at most k - 1 from node v.
*/

/* According to the problem statement, for the *i*-th query, when we connect the
*i*-th node of the first tree to a node *j* of the second tree, the distances
from node *i* to nodes in the second tree decrease, so more target nodes become
reachable.

We must therefore compute:

- **count₁[i]**: the number of nodes in the first tree within distance ≤ *k* of
node *i*
- **count₂[j]**: the number of nodes in the second tree within distance ≤ *k −
1* of node *j*

Because **count₂[j]** does not depend on the specific query, we can pre-compute
it with a depth-first search (DFS) on the second tree. Afterward, we take the
maximum value over all *j*, denoted:

**maxCount₂** = max<sub>j</sub> **count₂[j]**

For each query *i*, we run a DFS on the first tree to obtain **count₁[i]**, and
then return:

**count₁[i] + maxCount₂**

as the answer.
*/

class Solution {
public:
  int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
    if (k < 0) {
      return 0;
    }
    int res = 1;
    for (int child : children[node]) {
      if (child == parent) {
        continue;
      }
      res += dfs(child, node, children, k - 1);
    }
    return res;
  }

  vector<int> build(const vector<vector<int>>& edges, int k) {
    int n = edges.size() + 1;
    vector<vector<int>> children(n);
    for (const auto& edge : edges) {
      children[edge[0]].push_back(edge[1]);
      children[edge[1]].push_back(edge[0]);
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = dfs(i, -1, children, k);
    }
    return res;
  }

  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<int> count1 = build(edges1, k);
    vector<int> count2 = build(edges2, k - 1);
    int maxCount2 = *max_element(count2.begin(), count2.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = count1[i] + maxCount2;
    }
    return res;
  }
};
// sub:
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/submissions/1647278876/
