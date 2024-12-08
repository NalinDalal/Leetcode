/* 133. Clone Graph

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its
neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed).
For example, the first node with val == 1, the second node with val == 2, and so
on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite
graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the
copy of the given node as a reference to the cloned graph.



Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of
only one node with val = 1 and it does not have any neighbors. Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.


Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given
node.
*/

// Intuition:
/* 1.Graph Representation: Each node contains an integer value (val) and a list
of neighboring nodes (neighbors). We need to create a deep copy of this graph,
which means every node and its connections (neighbors) must be copied.

2.Cloning Process:To clone the graph, we start from the given node, create its
clone, and recursively clone all its neighbors. Use a map (or unordered_map in
C++) to store the original nodes as keys and their corresponding cloned nodes as
values. This helps avoid cycles and ensures that we do not clone the same node
more than once.

3. DFS Traversal: We use DFS to traverse each node and recursively clone the
graph by visiting each node's neighbors.
*/

// Approach:
/*Edge Case: If the input node is nullptr, return nullptr.

Map to track cloned nodes: Use an unordered_map to track nodes that have been
cloned already. This will map each original node to its corresponding clone.

DFS Function: For each node, if it has already been cloned (exists in the map),
return the clone. Otherwise, clone the current node and recursively clone all
its neighbors.

Return the clone: Return the clone of the original input node.
*/

#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  // Map to store visited nodes and their clones
  unordered_map<Node*, Node*> visited;

  // DFS function to clone the graph
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    // If the node has already been cloned, return the clone
    if (visited.find(node) != visited.end()) {
      return visited[node];
    }

    // Create a new node (clone) with the same value as the original node
    Node* clone = new Node(node->val);

    // Store this node in the visited map
    visited[node] = clone;

    // Iterate through the neighbors and clone them
    for (Node* neighbor : node->neighbors) {
      clone->neighbors.push_back(cloneGraph(neighbor));
    }

    return clone;
  }
};

int main() {
  // 1st node: 1 -> [2, 4]
  // 2nd node: 2 -> [1, 3]
  // 3rd node: 3 -> [2, 4]
  // 4th node: 4 -> [1, 3]
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);

  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node1, node3};

  return 0;
}
