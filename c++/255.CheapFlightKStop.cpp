/* 787. Cheapest Flights Within K Stops
There are n cities connected by some number of flights. You are given an array
flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight
from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price
from src to dst with at most k stops. If there is no such route, return -1.


Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src
= 0, dst = 3, k = 1 Output: 700 Explanation: The graph is shown above. The
optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost
100 + 600 = 700. Note that the path through cities [0,1,2,3] is cheaper but is
invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has
cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost
500.


Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <iostream>
#include <vector>

using namespace std;

// start at src, end at dst
// if k==0, check for min k, select that
// hence again check if dst is reachable from new src
// if not move ahead
// else reach dst
// add the cost after each stop
// return minCost with most k
// so do like start at src=flights[0][0]
// go to flight[0][1]
// check if dst==flight[0][1]
// if yes, return minCost+=flight[0][0]
// else repeat steps for flight till dest is reached, add cost of flight
// for(){for(){ take k as steps to be given, like if k=1, so in 2 steps it must
// reach

//  if (flights[i][j] == src && flights[i][j] == dst) {  cout << minCost <<
//  endl;  }
//  else if () {
// check for different flights, which can be connected to dst,
// increase count aacordingly
// call recursively
// findCheapestPrice(n, flights, flights[i][j], dst, k - 1);
//  } else
// can' reach so return -1

// return minCost;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    // Base case: direct flight from src to dst
    if (src == dst)
      return 0;

    // Initialize minCost to -1 indicating no path found yet
    int minCost = -1;

    // Recursive case: explore all flights from src
    for (const auto& flight : flights) {
      int currentSrc = flight[0];
      int currentDst = flight[1];
      int currentCost = flight[2];

      if (currentSrc == src) {
        // Recursive call to find cheapest price to reach currentDst
        int costToCurrentDst =
            findCheapestPrice(n, flights, currentDst, dst, k - 1);

        // Check if valid path found and update minCost accordingly
        if (costToCurrentDst != -1) {
          int totalCost = currentCost + costToCurrentDst;
          if (minCost == -1 || totalCost < minCost) {
            minCost = totalCost;
          }
        }
      }
    }

    return minCost;
  }
};
class Solution1 {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<int> cost(n, INT_MAX); // Initialize cost to all nodes as infinity
    cost[src] = 0;                // Starting point has 0 cost

    for (int i = 0; i <= k; i++) {
      vector<int> tempCost =
          cost; // Create a temporary array for this iteration

      for (const auto& flight : flights) {
        int u = flight[0], v = flight[1], price = flight[2];

        if (cost[u] != INT_MAX && cost[u] + price < tempCost[v]) {
          tempCost[v] = cost[u] + price; // Relax the edge
        }
      }
      cost = tempCost; // Update cost array after processing all flights
    }

    return cost[dst] == INT_MAX ? -1
                                : cost[dst]; // If dst is unreachable, return -1
  }
};
// sub:
// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1548218569/
// 100%
// sol:
// https://leetcode.com/problems/cheapest-flights-within-k-stops/solutions/6442483/787-cheapest-flights-within-k-stops-by-n-jfo7/
