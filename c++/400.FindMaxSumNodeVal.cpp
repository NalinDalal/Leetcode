/* 3068. Find the Maximum Sum of Node Values

There exists an undirected tree with n nodes numbered 0 to n - 1. You are given
a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi]
indicates that there is an edge between nodes ui and vi in the tree. You are
also given a positive integer k, and a 0-indexed array of non-negative integers
nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can
perform the following operation any number of times (including zero) on the
tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as
follows: nums[u] = nums[u] XOR k nums[v] = nums[v] XOR k Return the maximum
possible sum of the values Alice can achieve by performing the operation any
number of times.



Example 1:
Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
Output: 6
Explanation: Alice can achieve the maximum sum of 6 using a single operation:
- Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array
nums becomes: [1,2,1] -> [2,2,2]. The total sum of values is 2 + 2 + 2 = 6. It
can be shown that 6 is the maximum achievable sum of values.

Example 2:
Input: nums = [2,3], k = 7, edges = [[0,1]]
Output: 9
Explanation: Alice can achieve the maximum sum of 9 using a single operation:
- Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3 XOR
7 = 4, and the array nums becomes: [2,3] -> [5,4]. The total sum of values is 5
+ 4 = 9. It can be shown that 9 is the maximum achievable sum of values.

Example 3:
Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
Output: 42
Explanation: The maximum achievable sum is 42 which can be achieved by Alice
performing no operations.


Constraints:
2 <= n == nums.length <= 2 * 104
1 <= k <= 109
0 <= nums[i] <= 109
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
The input is generated such that edges represent a valid tree.

Hint 1: Select any node as the root.

Hint 2: Let dp[x][c] be the maximum sum we can get for the subtree rooted at
node x, where c is a boolean representing whether the edge between node x and
its parent (if any) is selected or not.

Hint 3: dp[x][c] = max(sum(dp[y][cy]) +
v(nums[x], sum(cy) + c)) where cy is 0 or 1. When sum(cy) + c is odd, v(nums[x],
sum(cy) + c) = nums[x] XOR k. When sum(cy) + c is even, v(nums[x], sum(cy) + c)
= nums[x].

Hint 4: There’s also an easier solution - does the parity of the
number of elements where nums[i] XOR k > nums[i] help?
*/

/* Compute gains for each node.

Select an even number of nodes where gain is positive (because each operation
affects 2 nodes at a time).*/

/* Solution:
1. Calculate gain[i] = (nums[i] ^ k) - nums[i].

2. Sum up all nums[i] as base_sum.

3. From all nodes, select the maximum subset with even size of positive-gain
values to XOR.
    - If the count of positive gains is even, take them all.
    - If the count is odd, skip the smallest positive gain (or include the
smallest negative gain to make count even).
*/

/* ## Algorithm

### Main Function: `maximumValueSum(nums, k, edges)`

1. Initialize a 2D memoization array `memo` of size `[n][2]` where `n =
nums.size()`, and set all values to `-1`.
2. Call the helper function `maxSumOfNodes` with the following parameters:
   - `index = 0`
   - `isEven = 1` (start assuming the total number of XOR operations will be
even)
   - `nums =` the input array
   - `k =` the given XOR value
   - `memo =` the initialized memoization array
3. Return the result from the `maxSumOfNodes` function.

---

### Recursive Function: `maxSumOfNodes(index, isEven, nums, k, memo)`

- **Base Case:**
  - If `index == nums.size()`, then:
    - If `isEven == 1` (even number of XOR operations so far), return `0`.
    - Else, return `INT_MIN` to indicate an invalid or suboptimal path.

- **Memoization:**
  - If `memo[index][isEven] != -1`, return the memoized result to avoid
recomputation.

- **Recursive Cases:**
  - `noXorDone`: Do not apply XOR on the current element.
    ```cpp
    noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
    ```

  - `xorDone`: Apply XOR with `k` on the current element.
    ```cpp
    xorDone = (nums[index] ^ k) + maxSumOfNodes(index + 1, 1 - isEven, nums, k,
memo);
    ```

- **Store and Return:**
  - Store the maximum of `noXorDone` and `xorDone` in `memo[index][isEven]`.
  - Return `memo[index][isEven]`.
*/

class Solution {
public:
  const int INF = 1e9;

  long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                          vector<vector<long long>>& memo) {
    if (index == nums.size()) {
      return isEven ? 0 : -INF;
    }

    if (memo[index][isEven] != -1) {
      return memo[index][isEven];
    }

    // Case 1: Don't XOR this node
    long long noXor =
        nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);

    // Case 2: XOR this node
    long long xorDone =
        (nums[index] ^ k) + maxSumOfNodes(index + 1, 1 - isEven, nums, k, memo);

    return memo[index][isEven] = max(noXor, xorDone);
  }

  long long maximumValueSum(vector<int>& nums, int k,
                            vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<long long>> memo(n, vector<long long>(2, -1));
    return maxSumOfNodes(0, 1, nums, k, memo);
  }
};
// sub:
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/submissions/1641975074/?envType=daily-question&envId=2025-05-23
// sol:
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/6772344/3068-find-the-maximum-sum-of-node-values-34kr/
