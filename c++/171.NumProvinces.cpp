/* https://leetcode.com/problems/number-of-provinces/

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is
connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith
city and the jth city are directly connected, and isConnected[i][j] = 0
otherwise.

Return the total number of provinces.



Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  // how many separate groups of connected cities exist
  // use Depth-First Search (DFS)
  // When we encounter an unvisited city, we can start a DFS from that city to
  // mark all cities that are reachable from it. Each time we start a new DFS,
  // we know we've found a new province

  // Approach:
  /*1.Initialization:
- We need a visited vector to keep track of which cities have been explored.
This prevents us from counting the same province multiple times.
- We also need a counter count to keep track of the number of provinces we find.
2. DFS Function:
- The DFS function will take a city (node) as input and explore all its
connected neighbors.
- It marks the current city as visited and then iterates through all possible
connections (neighbors) in the adjacency matrix.
- If a neighbor is connected (i.e., isConnected[node][i] == 1) and has not been
visited, the DFS function is called recursively on that neighbor.
3. Main Logic:
- In the findCircleNum function, we loop through each city in the visited
vector.
- If a city has not been visited, it indicates the start of a new province. We
increment the count and call the DFS function starting from that city to mark
all reachable cities as visited.
4. Return the Count:
- After processing all cities, we return the count, which represents the total
number of provinces. */

  void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
    visited[node] = 1;

    for (int i = 0; i < isConnected[node].size(); i++) {
      if (isConnected[node][i] == 1 && visited[i] == 0) {
        dfs(i, isConnected, visited);
      }
    }
  }

  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int count = 0;

    for (int i = 0; i < visited.size(); i++) {
      if (visited[i] == 0) {
        count++;
        dfs(i, isConnected, visited);
      }
    }

    return count;
  }
};

// Time: O(n^2) ;`n` is the number of nodes (cities)
// Space: O(n)
// 100%
