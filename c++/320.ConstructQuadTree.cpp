/*427. Construct Quad Tree
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a
Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly
four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a
grid of 0's. Notice that you can assign the val to True or False when isLeaf is
False, and both are accepted in the answer. isLeaf: True if the node is a leaf
node on the tree or False if the node has four children. class Node { public
boolean val; public boolean isLeaf; public Node topLeft; public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following
steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True
and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any
value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

You don't need to read this section for solving the problem. This is only if you
want to understand the output format here. The output represents the serialized
format of a Quad-Tree using level order traversal, where null signifies a path
terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference
is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf,
val] and if the value of isLeaf or val is False we represent it as 0.



Example 1:
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing
the Quad-Tree.

Example 2:
Input: grid =
[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output:
[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into
four sub-grids. The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each
has the same value. Explanation is shown in the photo below:



Constraints:
n == grid.length == grid[i].length
n == 2x where 0 <= x <= 6
*/

#include <vector>
using std::vector;
// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

// Intuition:
//  return all nodes in bfs manner
//  Quad tree->4 child nodes
//  assign some val to each node{0 or 1}
//  assign isLeaf to true if node has 4 child
//  steps to construct:
//   1. if grid has same value, assign isLeaf to true;val=value of grid
//   2. grid has diff value, assign isLeaf to false,val-any value, divide
//   grid into 4 subgrid
//   3. do it recursively for each child node

// Approach:
/*1. If all values in the given grid are the same, create a leaf node.

2. If values differ, recursively divide the grid into four equal parts and
construct child nodes.

3. Each node contains:

- val: 1 or 0 (any value when not a leaf).

- isLeaf: true if all values are the same in that region; otherwise, false.

- Four child nodes (topLeft, topRight, bottomLeft, bottomRight).
    */
class Solution {
public:
  Node* construct(vector<vector<int>>& grid) {
    return build(grid, 0, 0, grid.size());
  }

private:
  Node* build(vector<vector<int>>& grid, int row, int col, int size) {
    if (size == 1) {
      return new Node(grid[row][col], true);
    }

    bool isSame = true;
    int firstVal = grid[row][col];

    for (int i = row; i < row + size; ++i) {
      for (int j = col; j < col + size; ++j) {
        if (grid[i][j] != firstVal) {
          isSame = false;
          break;
        }
      }
      if (!isSame)
        break;
    }

    if (isSame) {
      return new Node(firstVal, true);
    }

    int newSize = size / 2;
    Node* topLeft = build(grid, row, col, newSize);
    Node* topRight = build(grid, row, col + newSize, newSize);
    Node* bottomLeft = build(grid, row + newSize, col, newSize);
    Node* bottomRight = build(grid, row + newSize, col + newSize, newSize);

    return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
  }
};
// Time: O(n^2)
// Space: O(n^2)
//  sub:
//  https://leetcode.com/problems/construct-quad-tree/submissions/1583803092/?envType=study-plan-v2&envId=top-interview-150
//  sol:
//  https://leetcode.com/problems/construct-quad-tree/solutions/6571784/427-construct-quad-tree-by-nalindalal200-lkvk/
