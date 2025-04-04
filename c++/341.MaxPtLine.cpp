/*149. Max Points on a Line
Given an array of points where points[i] = [xi, yi] represents a point on the
X-Y plane, return the maximum number of points that lie on the same straight
line.



Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4


Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/

class Solution {
public:
  // Helper function to compute GCD
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 1)
      return n;

    int max_count = 1; // Minimum, at least one point exists

    for (int i = 0; i < n; i++) {
      unordered_map<string, int> slope_map;
      int duplicate = 1, curr_max = 0;

      for (int j = i + 1; j < n; j++) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];

        if (dx == 0 && dy == 0) {
          duplicate++; // Exact same point
          continue;
        }

        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;

        string slope = to_string(dy) + "/" +
                       to_string(dx); // Unique representation of slope
        slope_map[slope]++;
        curr_max = max(curr_max, slope_map[slope]);
      }

      max_count = max(max_count, curr_max + duplicate);
    }

    return max_count;
  }
};
// Time: O(n^2)
// Space: O(n)
// Sub:
// https://leetcode.com/problems/max-points-on-a-line/submissions/1596178720/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/max-points-on-a-line/solutions/6613216/149-max-points-on-a-line-by-nalindalal20-bjlx/
