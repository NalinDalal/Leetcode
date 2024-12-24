/* 3203. Find Minimum Diameter After Merging Two Trees

There exist two undirected trees with n and m nodes, numbered from 0 to n - 1
and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1
and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi]
indicates that there is an edge between nodes ai and bi in the first tree and
edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in
the second tree.

You must connect one node from the first tree with another node from the second
tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes
in the tree.



Example 1:
Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
Output: 3
Explanation:We can obtain a tree of diameter 3 by connecting node 0 from the
first tree with any node from the second tree.

Example 2:
Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 =
[[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]] Output: 5 Explanation:We can obtain
a tree of diameter 5 by connecting node 0 from the first tree with node 0 from
the second tree.


Constraints:
1 <= n, m <= 10^5
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.*/

// Intuition:
/* The goal of the problem is to minimize the diameter of the tree after merging
 * two given trees. The diameter of a tree is defined as the longest path
 * between any two nodes in the tree. To achieve this, we first calculate the
 * diameters of both trees individually and then attempt to merge them in a way
 * that minimizes the diameter of the resulting tree.*/

// Approach:
/* 1. Diameter of Tree: The diameter of a tree is the length of the longest path
between any two nodes. The Double DFS method is commonly used to compute the
diameter of a tree:
    - First DFS: Begin from any arbitrary node (e.g., node 1 or 0) to find the
farthest node A.
    - Second DFS: From node A, perform another DFS to find the farthest node B.
The path from A to B gives us the diameter of the tree.
2. Optimizing the Merge:
- After computing the diameters of both trees, we must find a way to merge the
trees such that the diameter of the resulting tree is minimized.
- The best way to merge the trees is to connect nodes from each tree that are as
far apart as possible, thereby minimizing the increased path length caused by
the merge.
*/

// Approach:
/*1. Tree Diameter: 2 DFS like left leaf, right leaf, find distance b/w them
 * 2. Process Tree: we've both diameter, find: HalfDiameter{Diameter/2},
 * Remaining Part{Diameter-HalfDiameter}
 * 3. Merge Trees: sort half-diameter, connect nodes ;connect the two trees is
 * by adding an edge between them such that the resulting diameter is as small
 * as possible. Diameter=`1 + len + *it` {`len` = distance from farthest node in
 * 1st tree, `*it` =corresponding distance in the second tree.}
 * Diameter=max(HalfDiameter(left),HalfDiameter(right))
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_NODES 200005

template <typename T> void updateMax(T& current, T candidate) {
  current = max(current, candidate);
}

template <typename T> void updateMin(T& current, T candidate) {
  current = min(current, candidate);
}

vector<int> adjacencyList[MAX_NODES];
int depth[MAX_NODES], farthestNodeA, farthestNodeB;

void depthFirstSearch(int currentNode, int parentNode, int& farthestNode) {
  depth[currentNode] = depth[parentNode] + 1;
  if (farthestNode == -1 || depth[currentNode] > depth[farthestNode]) {
    farthestNode = currentNode;
  }
  for (int neighbor : adjacencyList[currentNode]) {
    if (neighbor != parentNode) {
      depthFirstSearch(neighbor, currentNode, farthestNode);
    }
  }
}

int calculateTreeDiameter() {
  farthestNodeA = -1;
  depthFirstSearch(1, 0, farthestNodeA);

  farthestNodeB = -1;
  depthFirstSearch(farthestNodeA, 0, farthestNodeB);

  return depth[farthestNodeB] - 1;
}

class Solution {
public:
  pair<int, int> processTree(const vector<vector<int>>& edges) {
    int nodeCount = edges.size() + 1;
    for (int i = 1; i <= nodeCount; i++) {
      adjacencyList[i].clear();
    }
    for (const auto& edge : edges) {
      int nodeU = edge[0] + 1;
      int nodeV = edge[1] + 1;
      adjacencyList[nodeU].push_back(nodeV);
      adjacencyList[nodeV].push_back(nodeU);
    }
    int diameter = calculateTreeDiameter();
    return {diameter / 2, diameter - diameter / 2};
  }

  int minimumDiameterAfterMerge(vector<vector<int>>& edgesTree1,
                                vector<vector<int>>& edgesTree2) {
    pair<int, int> tree1 = processTree(edgesTree1);
    pair<int, int> tree2 = processTree(edgesTree2);

    int minDiameter =
        max(tree1.first + tree1.second, tree2.first + tree2.second);
    updateMax(minDiameter, max(tree1.first, tree1.second) +
                               max(tree2.first, tree2.second) + 1);

    return minDiameter;
  }
};

/* Time: O(nlogn)   {DFS:O(n)+Sorting:O(nlogn)}
 * Space: O(n)       {AdjacencyList:O(n)} */
