/* 1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on
a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.



Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/

/* Hint 1: Connect each pair of points with a weighted edge, the weight being
the manhattan distance between those points. Hint 2: The problem is now the cost
of minimum spanning tree in graph with above edges.*/
// given a set of points in form of an 2d array
// return min cost to connect all points
// cost to connect xi,yi and xj,yj -> abs(xi-x2)+abs(yi-yj)
// do like calculate for 2 points and add to total cost
// check for min cost near a point like nearest point to that point, calculate
// cost, add to ans
/*1. Sort the edges in increasing order of their weights.
2. Iterate in the sorted edges,
        If inclusion of i'th edge leads to a cycle,
            skip this edge.
        else
            include the edge in the MST.*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  // Helper function to find root of node in union-find
  int find(vector<int>& parent, int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent, parent[i]);
  }

  // Helper function to union two nodes in union-find
  void unionNodes(vector<int>& parent, vector<int>& rank, int i, int j) {
    int rootI = find(parent, i);
    int rootJ = find(parent, j);
    if (rootI != rootJ) {
      if (rank[rootI] > rank[rootJ])
        parent[rootJ] = rootI;
      else if (rank[rootI] < rank[rootJ])
        parent[rootI] = rootJ;
      else {
        parent[rootJ] = rootI;
        rank[rootI]++;
      }
    }
  }

public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    // Edge list to store all edges with their weights (Manhattan distances)
    vector<pair<int, pair<int, int>>> edges;

    // Constructing the edge list
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dist =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edges.push_back({dist, {i, j}});
      }
    }

    // Sort edges based on weight (distance)
    sort(edges.begin(), edges.end());

    // Union-Find structures
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i)
      parent[i] = i;

    int minCost = 0;
    int edgesUsed = 0;

    // Kruskal's algorithm to find MST
    for (auto& edge : edges) {
      int weight = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      // Check if including this edge forms a cycle
      if (find(parent, u) != find(parent, v)) {
        unionNodes(parent, rank, u, v);
        minCost += weight;
        edgesUsed++;
        if (edgesUsed == n - 1) // MST has n-1 edges
          break;
      }
    }

    return minCost;
  }
};

// Time: O(n^2)
// Space: O(n)
void printVector(const vector<vector<int>>& points) {
  cout << "[ ";
  for (const auto& p : points) {
    cout << "[" << p[0] << ", " << p[1] << "] ";
  }
  cout << "]" << endl;
}

int main() {
  vector<vector<int>> v1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  int expected1 = 20;

  Solution obj;
  int ans1 = obj.minCostConnectPoints(v1);

  cout << "Test 1:" << endl;
  printVector(v1); // Properly print the input vector
  cout << "Expected: " << expected1 << endl;
  cout << "Ans: " << ans1 << endl;

  if (ans1 == expected1) {
    cout << "TestCase 1 Passed" << endl;
  } else {
    cout << "TestCase 1 Failed" << endl;
  }

  return 0;
}
// sub:
// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1542560644/
// sol:
// https://leetcode.com/problems/min-cost-to-connect-all-points/solutions/6420620/1584-min-cost-to-connect-all-points-by-n-nbzn/
