/*3108. Minimum Cost Walk in Weighted Graph
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi]
indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends
with a vertex, and each edge connects the vertex that comes before it and the
vertex that comes after it. It's important to note that a walk may visit the
same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the
bitwise AND of the weights of the edges traversed during the walk. In other
words, if the sequence of edge weights encountered during the walk is w0, w1,
w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where &
denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query,
you need to find the minimum cost of the walk starting at vertex si and ending
at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for
query i.


Example 1:
Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
Output: [1,-1]
Explanation:
To achieve the cost of 1 in the first query, we need to move on the following
edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7). In
the second query, there is no walk between nodes 3 and 4, so the answer is -1.

Example 2:
Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
Output: [0]
Explanation:To achieve the cost of 0 in the first query, we need to move on the
following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).



Constraints:
2 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= ui, vi <= n - 1
ui != vi
0 <= wi <= 105
1 <= query.length <= 105
query[i].length == 2
0 <= si, ti <= n - 1
si != ti

Hint 1: The intended solution uses Disjoint Set Union.
Hint 2: Notice that, if u and v are not connected then the answer is -1,
otherwise we can use all the edges from the connected component where both
belong to.
*/

#include <numeric> // for iota
#include <vector>

using namespace std;

// since need to find minCost of connecting u to v
// he optimal walk includes as many edges as possible.
// we can freely traverse the edges of the component
//  best way to achieve the lowest cost is to visit every edge in the component.
//  use DisJoint Set Union; Union two nodes, we merge their entire groups, as
//  now a path exists between every node in one group and every node in the
//  other. Once the nodes are grouped into connected components, we calculate
//  the total cost for each component as the bitwise AND of all its edge
//  weights.
//
class Solution {
public:
  vector<int> parent;
  vector<int> depth;
  vector<int> minimumCost(int n, vector<vector<int>>& edges,
                          vector<vector<int>>& queries) {
    // Initialize the parent array with -1 as initially each node belongs to
    // its own component
    parent.resize(n, -1);
    depth.resize(n, 0);

    // All values are initially set to the number with only 1s in its binary
    // representation
    vector<unsigned int> componentCost(n, -1);

    // Construct the connected components of the graph
    for (auto& edge : edges) {
      Union(edge[0], edge[1]);
    }

    // Calculate the cost of each component by performing bitwise AND of all
    // edge weights in it
    for (auto& edge : edges) {
      int root = find(edge[0]);
      componentCost[root] &= edge[2];
    }

    vector<int> answer;
    for (auto& query : queries) {
      int start = query[0];
      int end = query[1];

      // If the two nodes are in different connected components, return -1
      if (find(start) != find(end)) {
        answer.push_back(-1);
      } else {
        // Find the root of the edge's component
        int root = find(start);
        // Return the precomputed cost of the component
        answer.push_back(componentCost[root]);
      }
    }
    return answer;
  }

private:
  // Find function to return the root (representative) of a node's component
  int find(int node) {
    // If the node is its own parent, it is the root of the component
    if (parent[node] == -1)
      return node;
    // Otherwise, recursively find the root and apply path compression
    return parent[node] = find(parent[node]);
  }

  // Union function to merge the components of two nodes
  void Union(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    // If the two nodes are already in the same component, do nothing
    if (root1 == root2)
      return;

    // Union by depth: ensure the root of the deeper tree becomes the parent
    if (depth[root1] < depth[root2])
      swap(root1, root2);

    // Merge the two components by making root1 the parent of root2
    parent[root2] = root1;

    // If both components had the same depth, increase the depth of the new
    // root
    if (depth[root1] == depth[root2])
      depth[root1]++;
  }
};
// edges[i] = [ui, vi, wi]-> edge b/w ui,vi woth wt. wi
// wi=bitwise AND of all wt. of edges traverse during walk
// query[i]=[si,ti]->start at si, end at ti, find min cost of walk
// answer array to store min cost of all queries
// use Disjoint Set Union to find connected components, if not connected
// then -1
// Time: O(m+q);m-no of edge,q-no of query
// Space: O(n);n-no of query
// Sub:
// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/submissions/1579680593/?envType=daily-question&envId=2025-03-20
// Sol:
// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/solutions/6557565/3108-minimum-cost-walk-in-weighted-graph-gbwo/

// Approach:
/* Main Function: minimumCost(n, edges, queries)
- Initialize three arrays of size n:
    - parent, with all values set to -1, meaning that each node initially forms
its own connected component.
    - depth, with all values initialized to 0.
    - componentCost, with all values set to the largest integer (2^32 - 1),
which is the neutral value for the AND operation, as it contains only 1s in its
binary representation.
- Construct the connected components of the graph:
    - For each edge = [node1, node2, weight] in edges:
        - Union(node1, node2).
- Calculate the cost of each component:
    - For each edge = [node1, node2, weight] in edges:
        - Find the root of the edge's component: root = find(node1).
        - Update the component cost by performing a bitwise AND:
componentCost[root] &= weight.
- Initialize an array answer to store the answer for each query.
    - For each query = [start, end] in queries:
        - If the two nodes belong to different connected components, i.e.
find(start) != find(end), push -1 into answer.
        - Otherwise:
            - Find the root of their component: root = find(start).
            - Push componentCost[root] into answer.
- Return answer.

find(node) function:
- If parent[node] = -1, node is the representative of its group, so return node.
- Otherwise, return find(parent[node]) and store the result in parent[node]
(path compression).

Union(node1, node2) function:
- Find the root of each node's component: set root1 = find(node1) and root2 =
find(node2).
- If the two nodes already belong to the same component, i.e. root1 == root2,
return.
- Otherwise, if depth[root1] < depth[root2], swap the two roots to ensure that
root1 has greater depth.
- Merge the two groups, by setting parent[root2] = root1.
- If the groups had the same depth, increment the depth of the merged group by 1
(depth[root1]++).
*/
