/* 3342. Find Minimum Time to Reach Last Room II
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents
the minimum time in seconds when you can start moving to that room. You start
from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving
between adjacent rooms takes one second for one move and two seconds for the
next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or
vertically.

Example 1:
Input: moveTime = [[0,4],[4,4]]
Output: 7
Explanation:
The minimum time required is 7 seconds.
At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.

Example 2:
Input: moveTime = [[0,0,0,0],[0,0,0,0]]
Output: 6
Explanation:
The minimum time required is 6 seconds.
At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.

Example 3:
Input: moveTime = [[0,1],[1,2]]
Output: 4



Constraints:
2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109
*/

/* 1st move takes 1 sec
2nd move takes 2 sec
3rd move takes 1 sec

(i,j) coordinates: change by exactly 1 in 4 direction
d[i][j]-> time to reach (i,j) from (0,0)

then from (i,j) to (u,v)= max(d[i][j],moveTime[u][v])+(i+j)mod2+1.

since reaching (n−1,m−1) is guaranteed, we can optimize the algorithm by
checking within the main loop whether the current point is (n−1,m−1). If it is,
we can exit early to avoid unnecessary computations for other cells.
*/

class State {
public:
  int x;
  int y;
  int dis;
  State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};
class Solution {
public:
  const int inf = 0x3f3f3f3f;
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    vector<vector<int>> d(n, vector<int>(m, inf));
    vector<vector<int>> v(n, vector<int>(m, 0));

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    d[0][0] = 0;

    auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };
    priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
    q.push(State(0, 0, 0));

    while (q.size()) {
      State s = q.top();
      q.pop();
      if (v[s.x][s.y]) {
        continue;
      }
      if (s.x == n - 1 && s.y == m - 1) {
        break;
      }
      v[s.x][s.y] = 1;
      for (int i = 0; i < 4; i++) {
        int nx = s.x + dirs[i][0];
        int ny = s.y + dirs[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        int dist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;
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
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/submissions/1628459246/?envType=daily-question&envId=2025-05-08
