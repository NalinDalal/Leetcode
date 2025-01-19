/* 973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the
X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance
(i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique
(except for the order that it is in).


Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just
[[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.


Constraints:

1 <= k <= points.length <= 104
-104 <= xi, yi <= 104*/

// i say find dist using formula, sort according to distance return top k
// distance formula is sqrt((x1-x2)^2+(y1-y2)^2)
// then sort according to distance
// return top k elements, apply quick sort

class Solution {
  int euclidean(vector<int>& point) {
    return pow(point[0], 2) + pow(point[1], 2);
  }
  int partition(vector<vector<int>>& points, int low, int high) {
    srand(time(0));
    swap(points[low], points[low + rand() % (high - low)]);
    int pivotDist = euclidean(points[low]);
    bool done{false};

    while (!done) {
      while (euclidean(points[low]) < pivotDist) {
        ++low;
      }
      while (euclidean(points[high]) > pivotDist) {
        --high;
      }

      if (low >= high) {
        done = true;
      } else {
        swap(points[low], points[high]);
        ++low;
        --high;
      }
    }
    return high;
  }

  void quickselect(vector<vector<int>>& points, int low, int high, int k) {
    if (low >= high) {
      return;
    }

    int pivot = partition(points, low, high);

    if (k <= pivot) {
      quickselect(points, low, pivot, k);
    } else {
      quickselect(points, pivot + 1, high, k);
    }
  }

public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n = points.size();
    quickselect(points, 0, n - 1, k);

    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
};
// Time: O(nlogn)
// Space: O(n)
// 98.5%
// sub:
// https://leetcode.com/problems/k-closest-points-to-origin/submissions/1513222505/
// sol:
// https://leetcode.com/problems/k-closest-points-to-origin/solutions/6301080/973-k-closest-points-to-origin985-by-nal-pcb7/
