/* 2471. Minimum Number of Operations to Sort a Binary Tree by Level

You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their
values.

Return the minimum number of operations needed to make the values at each level
sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the
root node.

Example 1:
Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
Output: 3
Explanation:
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 2:
Input: root = [1,3,2,7,6,5,4]
Output: 3
Explanation:
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

Example 3:
Input: root = [1,2,3,4,5,6]
Output: 0
Explanation: Each level is already sorted in increasing order so return 0.


Constraints:
The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^5
All the values of the tree are unique.*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/* Intution:
1. Traverse each level using BFS.
2. Capture the current order of values and their original positions.
3. Determine how many swaps are required to sort the level.
*/

/* Approach:
1. Level Order Traversal (BFS):
- Use a queue to traverse the binary tree level by level.
- For each level, collect node values and their indices.
2. Sort with Index Mapping:
- Pair each value with its original index.
- Sort the values, preserving their original indices.
3. Count Minimum Swaps:
- Determine the number of swaps needed to rearrange the values to match their
sorted order. This involves cycling through misplaced elements and swapping them
to their correct positions.
4. Repeat for All Levels:
- Process all levels independently to calculate the total number of swaps.
*/

class Solution {
private:
  int indexOf(const vector<int>& arr, int ele) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == ele) {
        return i;
      }
    }
    return -1;
  }

  void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  int minSwaps(vector<int>& arr, int N) {
    int ans = 0;
    vector<int> temp = arr;
    sort(temp.begin(), temp.begin() + N);

    for (int i = 0; i < N; i++) {
      if (arr[i] != temp[i]) {
        ans++;
        swap(arr, i, indexOf(arr, temp[i]));
      }
    }
    return ans;
  }

public:
  int minimumOperations(TreeNode* root) {
    if (!root)
      return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
      int size = q.size();
      vector<int> arr;

      for (int i = 0; i < size; i++) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);

        arr.push_back(curr->val);
      }

      count += minSwaps(arr, arr.size());
    }

    return count;
  }
};

// Time: O(nlogn)
//  Traversal of n nodes is O(n).
//  Sorting each level's values dominates and contributes O(klogk) for k nodes
//  in a level. Summing across levels gives O(nlogn).
// Space: O(n)
//  Space for the queue and level-wise node values.

// Optimised:
/* 1. Hash Map for Index Lookup:
- Instead of repeatedly searching for the index of elements, we use pair<int,
int> to keep track of both value and original index.
- Sorting this vector allows us to process cycles in $$O(NlogN)$$.

2. Cycle Detection for Swaps:
- The number of swaps required to sort an array is equivalent to the number of
swaps needed to resolve cycles in the graph of element indices.
- Using a visited array ensures we process each cycle only once.

3. Reduced Complexity:
- The complexity of the minSwaps function is reduced from $$O(N^2)$$ to
$$O(NlogN)$$ due to sorting and linear traversal.*/

class Solution1 {
private:
  int minSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> sortedArr(n);
    for (int i = 0; i < n; i++) {
      sortedArr[i] = {arr[i], i}; // Pair value with its index
    }

    sort(sortedArr.begin(), sortedArr.end()); // Sort by value

    vector<bool> visited(n, false); // To keep track of visited indices
    int swaps = 0;

    for (int i = 0; i < n; i++) {
      // If already visited or in the correct position, skip
      if (visited[i] || sortedArr[i].second == i)
        continue;

      // Compute the size of the cycle
      int cycleSize = 0, j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = sortedArr[j].second; // Move to the index of the next element in the
                                 // sorted array
        cycleSize++;
      }

      if (cycleSize > 1) {
        swaps += (cycleSize - 1); // A cycle of size k requires (k-1) swaps
      }
    }

    return swaps;
  }

public:
  int minimumOperations(TreeNode* root) {
    if (!root)
      return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
      int size = q.size();
      vector<int> arr;

      for (int i = 0; i < size; i++) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);

        arr.push_back(curr->val);
      }

      count += minSwaps(arr); // Optimized swaps calculation
    }

    return count;
  }
};

// Time: O(nlogm)
// Space: O(n)
