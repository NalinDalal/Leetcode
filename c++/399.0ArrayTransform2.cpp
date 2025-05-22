/* 3362. Zero Array Transformation III
You are given an integer array nums of length n and a 2D array queries where
queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for
each index. A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such
that nums can still be converted to a zero array using the remaining queries. If
it is not possible to convert nums to a zero array, return -1.



Example 1:
Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
Output: 1
Explanation:
After removing queries[2], nums can still be converted to a zero array.
Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.

Example 2:
Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
Output: 2
Explanation:We can remove queries[2] and queries[3].

Example 3:
Input: nums = [1,2,3,4], queries = [[0,3]]
Output: -1
Explanation:nums cannot be converted to a zero array even after using all the
queries.



Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length */

// want to remove the maximum number of queries while still being able to turn
// nums into all zeros using the remaining queries. Each query lets you decrease
// elements in a range [l, r] by at most 1, only once per query.
/* Start with all queries and compute the total "capacity" (how many times each
index can be decremented).

If this capacity is not enough at any index → return -1.

Then try removing queries greedily (e.g., using reverse delete approach or
binary search) while maintaining the condition that the capacity at every index
≥ nums[i].

--
Preprocess: compute a difference array for all queries.

Use binary search to find the maximum number of queries that can be removed.
*/

/* final
1. **Start at index 0 in `nums`**:
   If `nums[0] > 0`, we need at least `nums[0]` queries with `left endpoint ==
0` to reduce it to zero.

2. **Greedy Selection**:
   Choose the `nums[0]` queries with the **largest right endpoints** to maximize
their future range coverage.

3. **Move to index 1 and beyond**:
   Repeat the process for each `nums[i]`. Previously selected queries might not
cover index `i`, so their effect must be "removed" using a **difference array
(`deltaArray`)**.

4. **Track Active Coverage**:
   As you iterate, keep a **priority queue (max-heap)** of right endpoints from
queries whose left endpoint ≤ current index.

5. **Ensure Enough Operations**:
   If current cumulative coverage is less than `nums[i]`, pop from the heap
(i.e. **select new queries**) until the required number of operations is met.

6. **Efficiently Update**:
   Use the heap to dynamically track the most impactful (longest reaching)
queries at each step.

7. **Final Answer**:
   The number of queries that were **never selected** during this process is the
maximum number that can be removed.

*/
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    sort(
        queries.begin(), queries.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    priority_queue<int> heap;
    vector<int> deltaArray(nums.size() + 1, 0);
    int operations = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      operations += deltaArray[i];
      while (j < queries.size() && queries[j][0] == i) {
        heap.push(queries[j][1]);
        ++j;
      }
      while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
        operations += 1;
        deltaArray[heap.top() + 1] -= 1;
        heap.pop();
      }
      if (operations < nums[i]) {
        return -1;
      }
    }
    return heap.size();
  }
};
// sub:
// https://leetcode.com/problems/zero-array-transformation-iii/submissions/1640978324/?envType=daily-question&envId=2025-05-22
