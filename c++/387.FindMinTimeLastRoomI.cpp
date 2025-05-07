/* 3341. Find Minimum Time to Reach Last Room I
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents
the minimum time in seconds when you can start moving to that room. You start
from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving
between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or
vertically.

Example 1:
Input: moveTime = [[0,4],[4,4]]
Output: 6
Explanation:
The minimum time required is 6 seconds.
At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in one second.

Example 2:
Input: moveTime = [[0,0,0],[0,0,0]]
Output: 3
Explanation:
The minimum time required is 3 seconds.
At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in one second.
At time t == 2, move from room (1, 1) to room (1, 2) in one second.

Example 3:
Input: moveTime = [[0,1],[1,2]]
Output: 3



Constraints:
2 <= n == moveTime.length <= 50
2 <= m == moveTime[i].length <= 50
0 <= moveTime[i][j] <= 109 */

// 2d array size=nxm
// moveTime[i][j] represents the minimum time in seconds when you can
// start moving to that room
// time b/w adjacent room=1
// return min time to reach (n-1,m-1)
// u can't enter a room b/f it's time
// the real time to enter a room is: max(current_time + 1, moveTime[next_room])

// shortest path with egdes having fixed cost=1, can't enter node b/f
// moveTime[i][j]

/* Algorithm:
1. Use a priority queue to always explore the next fastest move.

2. Keep a `dist[i][j]` array: the earliest time we can reach room `(i, j)`.

3. From each room, try all 4 directions:

    - Calculate when you would arrive (current_time + 1)
    - Compare it with the room's `moveTime`, and wait if needed.
    - Only update and continue if you find a faster path to that room.
*/

/*##Problem Overview

        We are given a two -
    dimensional array of size `n × m`,
    and the task is to find the **shortest time required to move from
            position `(0, 0)` to position `(n−1, m−1)`**.

                *From any position `(i, j)`,
    you can move to any of the **four adjacent positions ** : `(i−1, j)`, `(i +
1, j)`, `( i, j−1)`, or `(i, j + 1)`.*Each position `(i, j)` has an associated
**earliest move time ** `moveTime[i][j]`, which means **you cannot enter **that
position **before **that time
            .

        -- -

        ##Grid as a Graph

        We can treat the 2D array as a graph :

    *Each cell `(i, j)` is a **node *
        *.*There are **undirected edges **connecting `(i, j)` to its adjacent
    positions.***Moving between adjacent rooms takes 1 second **.

    -- -

    ##Goal

    Find the **shortest time **it takes to move from the **top
        - left corner ** `(0, 0)` to the **bottom
        - right corner ** `(n−1, m−1)`,
    considering both :

    ***Movement cost(1 second) *
    *between adjacent rooms.***Waiting time **,
    due to the room's earliest move time constraint `moveTime[i][j]`.

        -- -

        ##Algorithm
        - Modified Dijkstra

          We use **Dijkstra's algorithm**, adapted for this problem:

              *Let `dp[i][j]` be the **earliest time **to reach position `(
                  i, j)` from `(0, 0)`.*When moving from `(i, j)` to `(u, v)`,
    the arrival time is :

``` max(dp[i][j] + 1, moveTime[u][v])
```

    Explanation :

    * `dp[i][j] +
    1` is the earliest you can arrive at `(u, v)` assuming a 1 -
    second move.*If `moveTime[u][v]` is later than that,
    you **must wait **before entering.

        -- -

        ##Rest of the Dijkstra Process

            *Use a **min
        - heap priority queue **to always process the node with the **smallest
          current time **.*For each `(i, j)`,
    update the neighbors if a **faster arrival time **is found
        .*Stop when you reach `(n−1, m−1)` — this is your answer.*/

class State {
public:
  int x;
  int y;
  int dis;
  State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int inf = 0x3f3f3f3f;
    int n = moveTime.size(), m = moveTime[0].size();
    vector<vector<int>> d(n, vector<int>(m, inf));
    vector<vector<int>> v(n, vector<int>(m, 0));

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    d[0][0] = 0;

    auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

    priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
    q.push(State(0, 0, 0));

    while (!q.empty()) {
      State s = q.top();
      q.pop();
      if (v[s.x][s.y])
        continue;
      v[s.x][s.y] = 1;

      for (int i = 0; i < 4; i++) {
        int nx = s.x + dirs[i][0];
        int ny = s.y + dirs[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
        if (d[nx][ny] > dist) {
          d[nx][ny] = dist;
          q.push(State(nx, ny, dist));
        }
      }
    }

    return d[n - 1][m - 1];
  }
};

// sub:
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/submissions/1627448024/?envType=daily-question&envId=2025-05-07
