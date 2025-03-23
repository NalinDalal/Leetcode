/*1976. Number of Ways to Arrive at Destination
You are in a city that consists of n intersections numbered from 0 to n - 1 with
bi-directional roads between some intersections. The inputs are generated such
that you can reach any intersection from any other intersection and that there
is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui,
vi, timei] means that there is a road between intersections ui and vi that takes
timei minutes to travel. You want to know in how many ways you can travel from
intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest
amount of time. Since the answer may be large, return it modulo 109 + 7.



Example 1:
Input: n = 7, roads =
[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to
intersection 6 is 7 minutes. The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Example 2:
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1,
and it takes 10 minutes.


Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/

// Intuition:
// roads[i]=[ui,vi,timei]-> road b/w ui,vi, takes timei
// reach from 0 to n-1
// so do like enter the vector, check for 0 to n-1
// return no of way to reach from ui to vi in shortest time
// Approach:
// 1. convert road to adjacency list
// 2. use min heap while maintaining dist[] and ways[]
//   - dist[] is shortest dist to each node
//   - ways[] is no of way to reach node
// 3. if shorter path found update dist and reset ways
//   if another found then increase ways
// 4. return ways[n-1]

class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> graph(n); // {neighbor, time}

    // Build adjacency list
    for (const auto& road : roads) {
      int u = road[0], v = road[1], time = road[2];
      graph[u].emplace_back(v, time);
      graph[v].emplace_back(u, time);
    }

    // Min-heap {time, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        pq;
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);

    // Start from node 0
    pq.emplace(0, 0);
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty()) {
      auto [currTime, u] = pq.top();
      pq.pop();

      if (currTime > dist[u])
        continue;

      for (auto [v, time] : graph[u]) {
        long long newTime = currTime + time;

        if (newTime < dist[v]) {
          dist[v] = newTime;
          pq.emplace(newTime, v);
          ways[v] = ways[u]; // Reset paths
        } else if (newTime == dist[v]) {
          ways[v] = (ways[v] + ways[u]) % MOD; // Add ways
        }
      }
    }

    return ways[n - 1];
  }
};
// sub:
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/1583217404/?envType=daily-question&envId=2025-03-23
// sol:
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/solutions/6570029/1976-number-of-ways-to-arrive-at-destina-6190/
