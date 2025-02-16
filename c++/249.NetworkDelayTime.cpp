/* 743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given
times, a list of travel times as directed edges times[i] = (ui, vi, wi), where
ui is the source node, vi is the target node, and wi is the time it takes for a
signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for
all the n nodes to receive the signal. If it is impossible for all the n nodes
to receive the signal, return -1.



Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

Hint 1
We visit each node at some time, and if that time is better than the fastest
time we've reached this node, we travel along outgoing edges in sorted order.
Alternatively, we could use Dijkstra's algorithm.*/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
// Intuition
/* Bellmann Ford
1. Store Distances & Iterate Once Over times
    - You initialized dist but only updated it once per edge, which doesn't
guarantee correct shortest paths.

2. Direct Distance Update Without Proper Relaxation
    - The algorithm needs multiple passes (like Bellman-Ford) or a priority
queue (like Dijkstra) to correctly relax edges.

3. Incorrectly Checking Only dist[n] for the Result
    - The answer should be the maximum time taken to reach any node, not just
dist[n].*/
class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    for (int i = 0; i < times.size(); i++) {
      int u = times[i][0];
      int v = times[i][1];
      int w = times[i][2];
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
    if (dist[n] == 0)
      return -1;
    return dist[n];
  }
};

// Approach
/*1. Graph Representation:
    - Convert times into an adjacency list representation (graph[node] =
{neighbor, weight}) for efficient traversal.

2. Priority Queue for Dijkstra's Algorithm:
    - Use a min-heap (priority queue) to always process the nearest node first.
    - Initialize all distances to INT_MAX, except the starting node k (set to
0).

3. Relaxation of Edges:
    - Process the nearest node and update its neighbors' distances if a shorter
path is found.
    - Push updated distances into the priority queue.

4. Find Maximum Distance:
    - After all nodes are processed, find the maximum time taken to reach any
node.

5. Handle Unreachable Nodes:
    - If any node remains at INT_MAX, return -1 (indicating it was unreachable).
*/
class Solution1 {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Create adjacency list
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& edge : times) {
      graph[edge[0]].push_back({edge[1], edge[2]});
    }

    // Min-heap (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
      auto [time, node] = pq.top();
      pq.pop();

      if (time > dist[node])
        continue; // Skip outdated entries

      for (auto& [neighbor, weight] : graph[node]) {
        if (dist[node] + weight < dist[neighbor]) {
          dist[neighbor] = dist[node] + weight;
          pq.push({dist[neighbor], neighbor});
        }
      }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[i] == INT_MAX)
        return -1; // Not all nodes are reachable
      maxTime = max(maxTime, dist[i]);
    }
    return maxTime;
  }
};

// 93%
// sub: https://leetcode.com/problems/network-delay-time/submissions/1544783345/
// sol:
// https://leetcode.com/problems/network-delay-time/solutions/6428388/743-network-delay-time-by-nalindalal2004-nvts/
// Time: O(n^2)
// Space: O(n)
int main() {
  vector<vector<vector<int>>> testCases = {
      {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, // Test Case 1
      {{1, 2, 1}},                       // Test Case 2
      {{1, 2, 1}}                        // Test Case 3
  };

  vector<int> n_values = {4, 2, 2};
  vector<int> k_values = {2, 1, 2};
  vector<int> expected_outputs = {2, 1, -1};

  Solution1 sol;

  for (size_t i = 0; i < testCases.size(); i++) {
    int result = sol.networkDelayTime(testCases[i], n_values[i], k_values[i]);
    cout << "Test Case " << i + 1 << ": ";
    cout << (result == expected_outputs[i] ? "Passed ✅" : "Failed ❌")
         << " (Output: " << result << ", Expected: " << expected_outputs[i]
         << ")\n";
  }

  return 0;
}
