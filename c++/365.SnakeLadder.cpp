/* 909. Snakes and Ladders
You are given an n x n integer matrix board where the cells are labeled from 1
to n2 in a Boustrophedon style starting from the bottom left of the board (i.e.
board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do
the following:

Choose a destination square next with a label in the range [curr + 1, min(curr +
6, n2)]. This choice simulates the result of a standard 6-sided die roll: i.e.,
there are always at most 6 destinations, regardless of the size of the board. If
next has a snake or ladder, you must move to the destination of that snake or
ladder. Otherwise, you move to next. The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1.
The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not
the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the
destination to a snake or ladder is the start of another snake or ladder, you do
not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your
destination square is 2. You follow the ladder to square 3, but do not follow
the subsequent ladder to 4. Return the least number of dice rolls required to
reach the square n2. If it is not possible to reach the square, return -1.



Example 1:
Input: board =
[[-1,-1,-1,-1,-1,-1]
,[-1,-1,-1,-1,-1,-1]
,[-1,-1,-1,-1,-1,-1]
,[-1,35,-1,-1,13,-1]
,[-1,-1,-1,-1,-1,-1]
,[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so
return 4.

Example 2:
Input: board =
[[-1,-1]
,[-1,3]]
Output: 1


Constraints:
n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.
*/

/* 1. Flatten the board:
- The board is a 2D N x N grid, but the path follows a serpentine pattern.
- We transform it into a 1D array (mboard) to simplify traversal.

2. Use BFS (Breadth-First Search):
- Each node represents a position on the board.
- From each position, you can move up to 6 steps ahead (like a dice roll).
- Use a queue to explore reachable squares and track the shortest path using a
best array.

3. Handle ladders and snakes:
- If mboard[i] != -1, it means there's a ladder or a snake. Move to that square
instead.*/

// Algo
/* Flatten the 2D board to a 1D list, adjusting row order (left-to-right ↔
right-to-left).

Initialize a queue for BFS and a best[] list to track the minimum number of
steps.

Perform BFS to explore each reachable position.

Return the number of steps once the last cell is reached.

If unreachable, return -1. */
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int N = board.size();
    vector<int> mboard;

    // Flatten the board
    for (int i = N - 1; i >= 0; --i) {
      if ((N - 1 - i) % 2 == 0)
        mboard.insert(mboard.end(), board[i].begin(), board[i].end());
      else
        mboard.insert(mboard.end(), board[i].rbegin(), board[i].rend());
    }

    vector<int> best(N * N, -1);
    queue<int> q;
    q.push(0);
    best[0] = 0;

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int i = 1; i <= 6; ++i) {
        int next = current + i;
        if (next >= N * N)
          continue;

        if (mboard[next] != -1)
          next = mboard[next] - 1;

        if (next == N * N - 1)
          return best[current] + 1;

        if (best[next] == -1) {
          best[next] = best[current] + 1;
          q.push(next);
        }
      }
    }
    return -1;
  }
};

// Time: O(n^2)
// Space: O(n^2)
// Sub:
// https://leetcode.com/problems/snakes-and-ladders/submissions/1609166874/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/snakes-and-ladders/solutions/6658694/909-snakes-and-ladders-by-nalindalal2004-yi7i/
