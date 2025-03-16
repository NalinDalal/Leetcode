/* 2013. Detect Squares
You are given a stream of points on the X-Y plane. Design an algorithm that:

Adds new points from the stream into a data structure. Duplicate points are
allowed and should be treated as different points. Given a query point, counts
the number of ways to choose three points from the data structure such that the
three points and the query point form an axis-aligned square with positive area.
An axis-aligned square is a square whose edges are all the same length and are
either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

DetectSquares() Initializes the object with an empty data structure.
void add(int[] point) Adds a new point point = [x, y] to the data structure.
int count(int[] point) Counts the number of ways to form axis-aligned squares
with point point = [x, y] as described above.


Example 1:


Input
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11,
10]]] Output [null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square
with any points in the data structure. detectSquares.add([11, 2]);    // Adding
duplicate points is allowed. detectSquares.count([11, 10]); // return 2. You can
choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points


Constraints:
point.length == 2
0 <= x, y <= 1000
At most 3000 calls in total will be made to add and count.
*/
#include <iostream>

#include <unordered_map>
#include <vector>
using namespace std;

class DetectSquares {
private:
  unordered_map<int, unordered_map<int, int>> pointCounts;

public:
  DetectSquares() {
    // Initialize any required data structures
  }

  void add(const vector<int>& point) {
    // Add a new point to the data structure
    int x = point[0];
    int y = point[1];
    pointCounts[x][y]++;
  }

  int count(const vector<int>& point) {
    // Count the number of ways to form axis-aligned squares with the given
    // point
    int x = point[0];
    int y = point[1];
    int totalCount = 0;

    // Iterate over all stored points to find squares
    for (auto& [px, pyMap] : pointCounts) {
      if (px == x)
        continue; // Skip if same x-coordinate

      int dx = abs(px - x);

      // Iterate over all y-coordinates in the map
      for (auto& [py, count] : pyMap) {
        if (abs(py - y) == dx) {
          // Calculate the count of squares
          totalCount += count * pyMap[y] * pointCounts[x][py];
        }
      }
    }

    return totalCount;
  }
};
// Time: O(n^2)
// Space: O(n)

int main() {
  DetectSquares* obj = new DetectSquares();
  obj->add(point);
  int param_2 = obj->count(point);
  return 0;
}
// sub: https://leetcode.com/problems/detect-squares/submissions/1575398901/
// sol:
// https://leetcode.com/problems/detect-squares/solutions/6542076/2013-detect-squares-by-nalindalal2004-v3mc/
