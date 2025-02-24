/* 2467. Most Profitable Path in a Tree

There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node
0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai,
bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers
amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves
towards some leaf node, while Bob moves towards node 0. For every node along
their path, Alice and Bob either spend money to open the gate at that node, or
accept the reward. Note that: If the gate is already open, no price will be
required, nor will there be any cash reward. If Alice and Bob reach the node
simultaneously, they share the price/reward for opening the gate there. In other
words, if the price to open the gate is c, then both Alice and Bob pay c / 2
each. Similarly, if the reward at the gate is c, both of them receive c / 2
each. If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches
node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal
leaf node.



Example 1:


Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
Output: 6
Explanation:
The above diagram represents the given tree. The game goes as follows:
- Alice is initially on node 0, Bob on node 3. They open the gates of their
respective nodes. Alice's net income is now -2.
- Both Alice and Bob move to node 1.
  Since they reach here simultaneously, they open the gate together and share
the reward. Alice's net income becomes -2 + (4 / 2) = 0.
- Alice moves on to node 3. Since Bob already opened its gate, Alice's income
remains unchanged. Bob moves on to node 0, and stops moving.
- Alice moves on to node 4 and opens the gate there. Her net income becomes 0 +
6 = 6. Now, neither Alice nor Bob can make any further moves, and the game ends.
It is not possible for Alice to get a higher net income.
Example 2:


Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
Output: -7280
Explanation:
Alice follows the path 0->1 whereas Bob follows the path 1->0.
Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280.


Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
1 <= bob < n
amount.length == n
amount[i] is an even integer in the range [-104, 104].
*/

//[ai,bi] in edges denotes there is path b/w ai,bi
// amount[i] <0->price to be paid, else price to be rewarded
// as counter increase alice move to adjacent node, bob move to node 0
// if(open) price=0,reward=0
// else income=reward-price
// if both are at same gate then split the reward and price equally
// if leaf node reached alice stops,bob stops at 0 node
// return max net income for alice

// steps:
// 1.Convert edges into an adjacency list to represent the tree.
// 2.Find the path from bob to 0 (so we know which nodes Bob reaches first).
// 3.Use DFS to traverse the tree from node 0 to compute Alice’s maximum profit.

#include <vector>
using std::vector;
class Solution {
public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    int n = edges.size() + 1;
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int a = e[0], b = e[1];
      g[a].emplace_back(b);
      g[b].emplace_back(a);
    }
    vector<int> ts(n, n);
    function<bool(int i, int fa, int t)> dfs1 = [&](int i, int fa,
                                                    int t) -> bool {
      if (i == 0) {
        ts[i] = t;
        return true;
      }
      for (int j : g[i]) {
        if (j != fa && dfs1(j, i, t + 1)) {
          ts[j] = min(ts[j], t + 1);
          return true;
        }
      }
      return false;
    };
    dfs1(bob, -1, 0);
    ts[bob] = 0;
    int ans = INT_MIN;
    function<void(int i, int fa, int t, int v)> dfs2 = [&](int i, int fa, int t,
                                                           int v) {
      if (t == ts[i])
        v += amount[i] >> 1;
      else if (t < ts[i])
        v += amount[i];
      if (g[i].size() == 1 && g[i][0] == fa) {
        ans = max(ans, v);
        return;
      }
      for (int j : g[i])
        if (j != fa)
          dfs2(j, i, t + 1, v);
    };
    dfs2(0, -1, 0, 0);
    return ans;
  }
};

// sub:
// https://leetcode.com/problems/most-profitable-path-in-a-tree/submissions/1553743785/?envType=daily-question&envId=2025-02-24
// sol:
// https://leetcode.com/problems/most-profitable-path-in-a-tree/solutions/6462305/2467-most-profitable-path-in-a-tree-by-n-5zmi/
