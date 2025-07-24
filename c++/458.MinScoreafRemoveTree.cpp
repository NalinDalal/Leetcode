/*2322. Minimum Score After Removals on a Tree

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n
- 1 edges.

You are given a 0-indexed integer array nums of length n where nums[i]
represents the value of the ith node. You are also given a 2D integer array
edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge
between nodes ai and bi in the tree.

Remove two distinct edges of the tree to form three connected components. For a
pair of removed edges, the following steps are defined:

Get the XOR of all the values of the nodes for each of the three components
respectively. The difference between the largest XOR value and the smallest XOR
value is the score of the pair. For example, say the three components have the
node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 =
6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR
value is 3. The score is then 8 - 3 = 5. Return the minimum score of any
possible pair of edge removals on the given tree.



Example 1:


Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
Output: 9
Explanation: The diagram above shows a way to make a pair of removals.
- The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^
4 ^ 11 = 10.
- The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
- The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
The score is the difference between the largest and smallest XOR value which is
10 - 1 = 9. It can be shown that no other pair of removals will obtain a smaller
score than 9. Example 2:


Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
Output: 0
Explanation: The diagram above shows a way to make a pair of removals.
- The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 =
0.
- The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 =
0.
- The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 =
0. The score is the difference between the largest and smallest XOR value which
is 0 - 0 = 0. We cannot obtain a smaller score than 0.


Constraints:

n == nums.length
3 <= n <= 1000
1 <= nums[i] <= 108
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.


Hint 1
Consider iterating over the first edge to remove, and then doing some
precalculations on the 2 resulting connected components. Hint 2 Will calculating
the XOR of each subtree help?
*/

/*Summary:
- You have a tree with n nodes and n - 1 edges.

- Each node has a value given in nums[i].

- You need to remove two distinct edges, splitting the tree into 3 connected
components.

- For each component, compute the XOR of the node values.

- Define the score as the difference between the largest and smallest XOR values
among the 3 components.

- Your task: Minimize the score across all valid pairs of removed edges.

tree always has n nodes, n-1 edges and no cycles
remove 1 edge-> 2 tree; 2 edge->3 tree

let `totalXor = XOR of all node values`

for each node compute xor of subtree via dfs traversal

remove an edge, it's child node becomes a new tree; find all pairs of such
removals and compute XORs of the resulting components.

precompute the subtree XORs for all nodes via DFS.;  iterate over all pairs of
edges and simulate their removal using the subtree data.
    */

/*Approach:
1. Build the tree using adjacency list.

2. Run DFS from node `0`:
    - Compute `subtreeXor[node]`: XOR of the subtree rooted at `node`.
    - Store `inTime[node]` and `outTime[node]` to help determine subtree
relationships.

3. For every pair of edges, simulate the removal:
    - Let the child node of the removed edge be the root of the component.
    - Use DFS timings to check if one subtree is inside another.
    - Use `totalXor` and `subtreeXor` to compute the XORs of the 3 components.
    - Calculate the score and update the minimum.

## DFS Pre-processing:
- `subtreeXor[node]` = XOR of the subtree rooted at `node`
- `inTime[node], outTime[node]` = timestamps for entry/exit in DFS traversal
(used to check ancestor-descendant)

```cpp
int time = 0;

void dfs(int node, int parent, vector<vector<int>>& tree,
         vector<int>& nums, vector<int>& subtreeXor,
         vector<int>& inTime, vector<int>& outTime) {

    subtreeXor[node] = nums[node];
    inTime[node] = time++;

    for (int nei : tree[node]) {
        if (nei != parent) {
            dfs(nei, node, tree, nums, subtreeXor, inTime, outTime);
            subtreeXor[node] ^= subtreeXor[nei];
        }
    }

    outTime[node] = time++;
}
```

## Subtree Containment:
```cpp
bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
    return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
}
```


    */
class Solution {
public:
  int time = 0;

  void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& nums,
           vector<int>& subtreeXor, vector<int>& inTime, vector<int>& outTime) {

    subtreeXor[node] = nums[node];
    inTime[node] = time++;

    for (int nei : tree[node]) {
      if (nei != parent) {
        dfs(nei, node, tree, nums, subtreeXor, inTime, outTime);
        subtreeXor[node] ^= subtreeXor[nei];
      }
    }

    outTime[node] = time++;
  }

  bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
    return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
  }

  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> tree(n);
    for (auto& e : edges) {
      tree[e[0]].push_back(e[1]);
      tree[e[1]].push_back(e[0]);
    }

    vector<int> subtreeXor(n), inTime(n), outTime(n);
    dfs(0, -1, tree, nums, subtreeXor, inTime, outTime);

    int totalXor = subtreeXor[0];
    int res = INT_MAX;

    vector<pair<int, int>> directedEdges;
    for (auto& e : edges) {
      // Determine parent-child direction
      if (isAncestor(e[0], e[1], inTime, outTime)) {
        directedEdges.push_back({e[1], e[0]}); // child, parent
      } else {
        directedEdges.push_back({e[0], e[1]});
      }
    }

    int m = directedEdges.size();
    for (int i = 0; i < m; ++i) {
      int a = directedEdges[i].first;
      for (int j = i + 1; j < m; ++j) {
        int b = directedEdges[j].first;

        int x, y, z;
        if (isAncestor(a, b, inTime, outTime)) {
          x = subtreeXor[b];
          y = subtreeXor[a] ^ subtreeXor[b];
          z = totalXor ^ subtreeXor[a];
        } else if (isAncestor(b, a, inTime, outTime)) {
          x = subtreeXor[a];
          y = subtreeXor[b] ^ subtreeXor[a];
          z = totalXor ^ subtreeXor[b];
        } else {
          x = subtreeXor[a];
          y = subtreeXor[b];
          z = totalXor ^ x ^ y;
        }

        int maxVal = max({x, y, z});
        int minVal = min({x, y, z});
        res = min(res, maxVal - minVal);
      }
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/submissions/1709254565/?envType=daily-question&envId=2025-07-24
// sol:
// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/solutions/6997315/2322-minimum-score-after-removals-on-a-t-tkhx/
