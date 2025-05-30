// 2359. Find Closest Node to Given Two Nodes
/* You are given a directed graph of n nodes numbered from 0 to n - 1, where
each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n,
indicating that there is a directed edge from node i to node edges[i]. If there
is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such
that the maximum between the distance from node1 to that node, and from node2 to
that node is minimized. If there are multiple answers, return the node with the
smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.



Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node
1 to node 2 is 1. The maximum of those two distances is 1. It can be proven that
we cannot get a node with a smaller maximum distance than 1, so we return
node 2. Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node
2 to itself is 0. The maximum of those two distances is 2. It can be proven that
we cannot get a node with a smaller maximum distance than 2, so we return
node 2.


Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n

Hint 1
How can you find the shortest distance from one node to all nodes in the graph?
Hint 2
Use BFS to find the shortest distance from both node1 and node2 to all nodes in
the graph. Then iterate over all nodes, and find the node with the minimum max
distance.

*/

/*find the node reachable from both node1 and node2 such that the maximum
distance from either node to that node is minimized For all nodes reachable from
both node1 and node2, find the node such that:
- max(distance(node1 → x), distance(node2 → x)) is minimized.
- In case of a tie, return the node with the smallest index.
*/

/* Approach:
1. Track distances from node1 to all nodes using DFS or a simple while loop
(since each node has only one outgoing edge).

2. Track distances from node2 similarly.

3. Loop through all nodes:
- If the node is reachable from both node1 and node2:
    - Compute the maximum of both distances.
    - Keep track of the node that has the minimum of those maxima.

4. Return that node index, or -1 if none exists.
*/

class Solution {
public:
  vector<int> getDistances(vector<int>& edges, int start) {
    int n = edges.size();
    vector<int> dist(n, -1);
    int d = 0;
    while (start != -1 && dist[start] == -1) {
      dist[start] = d++;
      start = edges[start];
    }
    return dist;
  }

  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    vector<int> dist1 = getDistances(edges, node1);
    vector<int> dist2 = getDistances(edges, node2);

    int result = -1, minDist = INT_MAX;
    for (int i = 0; i < edges.size(); ++i) {
      if (dist1[i] != -1 && dist2[i] != -1) {
        int maxDist = max(dist1[i], dist2[i]);
        if (maxDist < minDist) {
          minDist = maxDist;
          result = i;
        }
      }
    }
    return result;
  }
};

// sub:
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/submissions/1648545519/?envType=daily-question&envId=2025-05-30
// sol:
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/solutions/6794562/2359-find-closest-node-to-given-two-node-pxgb/
