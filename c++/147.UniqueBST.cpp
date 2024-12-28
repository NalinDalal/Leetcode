/*
https://leetcode.com/problems/unique-binary-search-trees/description/

96. Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary
search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1


Constraints: 1 <= n <= 19*/

// what can we do?
/* if(n==0) return 0;
count nodes on left and right
if(n==1) return 1;//only 1 nodes
if(n==2) return 2;//only 2 nodes
if(n==3) return 5;//3 nodes can be
    1
     \
      2
       \
        3

    1
     \
      3
     /
    2

      2
     / \
    1   3

        3
       /
      2
     /
    1

        3
       /
      1
       \
        2

count nodes on left and right-> left = 0,right = 2
iterate for 1,2,3,4 we get formula for right nodes
```all nodes - current root
= 4 - 1
= 3```

formula for left nodes
```
current root - 1
= 3 - 1
= 2
```

## Points
```cpp
number of left nodes = current root - 1
number of right nodes = all nodes - current root
````

for n=4->
```
      0,1,2,3 (index = n)
dp = [1,1,2,5]
```

```
root = 1 → left = 0, right = 3
dp = [1,1,2,5]
      ↑     ↑
total = 5
---------------------------------
root = 2 → left = 1, right = 2
dp = [1,1,2,5]
        ↑ ↑
total = 5 + (1 * 2)
= 7
---------------------------------
root = 3 → left = 2, right = 1
dp = [1,1,2,5]
        ↑ ↑
total = 7 + (2 * 1)
= 9
---------------------------------
root = 4 → left = 3, right = 0
dp = [1,1,2,5]
      ↑     ↑
total = 9 + (5 * 1)
= 14
````

```
return 14
````


*/
#include <vector>
using namespace std;
class Solution {
public:
  int numTrees(int n) {
    vector<int> uniqTree(n + 1, 1);

    for (int nodes = 2; nodes <= n; nodes++) {
      int total = 0;
      for (int root = 1; root <= nodes; root++) {
        total += uniqTree[root - 1] * uniqTree[nodes - root];
      }
      uniqTree[nodes] = total;
    }

    return uniqTree[n];
  }
};

// Time: O(n^2)
// Space: O(n)

/*
# Algorithm
## Step 1: Initialize an array to store results
`uniq_tree = [1] * (n + 1)`
- Explanation:
    - Create an array `uniq_tree` of size `n+1` where all elements are
initialized to `1`.
    - `uniq_tree[i]` will eventually store the number of unique Binary Search
Trees (BSTs) that can be formed using `i` nodes.
    - `uniq_tree[0]` and `uniq_tree[1]` are set to 1 because:
        - There is 1 way to arrange 0 nodes (an empty tree).
        - There is 1 way to arrange 1 node (just the node itself).

## Step 2: Loop through each number of nodes from 2 to n
```cpp
for nodes in range(2, n + 1):
````
- Explanation:
    - Iterate through all possible sizes of BSTs from 2 nodes to n nodes. For
each size, calculate the number of unique BSTs that can be formed.

### Step 3: Initialize a variable to calculate the total number of trees
```total = 0```
- Explanation:
    - total keeps track of the cumulative count of unique BSTs for the current
number of nodes.

### Step 4: Loop through each possible root position
for root in range(1, nodes + 1):
Explanation:
Consider every node from 1 to nodes as the potential root of the BST.

### Step 5: Calculate the number of BSTs for the current root
```cpp
total += uniq_tree[root - 1] * uniq_tree[nodes - root]
```
- Explanation:
    - Divide the BST into two parts:
        1. Left subtree: Contains root - 1 nodes (nodes smaller than the root).
        2. Right subtree: Contains nodes - root nodes (nodes larger than the
root).
    - The total number of BSTs for this root is the product of:
        - `uniq_tree[root - 1]` (ways to form the left subtree).
        - `uniq_tree[nodes - root]` (ways to form the right subtree).
    - Add this product to total.

### Step 6: Store the result for the current number of nodes
```cpp
uniq_tree[nodes] = total
```
- Explanation:
    - After considering all possible root positions for the current number of
nodes, store the total number of unique BSTs in uniq_tree[nodes].

### Step 7: Return the result for n nodes
```cpp
return uniq_tree[n]
```*/

/* Sub(100%): t.ly/cE5-u
Sol: t.ly/W3XvT */
