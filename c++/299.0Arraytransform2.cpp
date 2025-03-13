/*3356. Zero Array Transformation II

You are given an integer array nums of length n and a 2D array queries where
queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for
each index. A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing
the first k queries in sequence, nums becomes a Zero Array. If no such k exists,
return -1.



Example 1:
Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
Output: 2
Explanation:
For i = 0 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [1, 0, 1].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum
value of k is 2.

Example 2:
Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
Output: -1
Explanation:
For i = 0 (l = 1, r = 3, val = 2):
Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
The array will become [4, 1, 0, 0].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
The array will become [3, 0, 0, 0], which is not a Zero Array.


Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5*/

// what are we given:
//[li,ri,vali]-> decrease each element in range [li,ri] by vali
// if after k queries we get a zero array then we return k
// else if not possible then return -1
// nums array is given
// use a difference array to perform range updates efficiently.
// After applying all queries, check if nums is a zero array.

/* Algorithm
- Define a function canFormZeroArray, which takes the parameters nums, queries,
and integer k and returns a boolean value:
    - Initialize:
        - n to the size of nums.
        - sum to 0 to track the cumulative sum of updates added to a given
index.
        - differenceArray as a vector of integers of size n + 1 to apply range
updates
    - Iterate through the first k elements of queries:
        - Initialize start, end, and val to the respective values of the current
query.
        - Increment differenceArray[start] by val to update the start of the
range.
        - Decrement differenceArray[end + 1] by val to update the end of the
range.
    - Iterate through nums. For each index, numIndex:
        - Increment sum by differenceArray[numIndex];
        - If sum is less than nums[numIndex], return false, indicating that a
zero array cannot be formed after the first k queries.
    - Return true, meaning a zero array was formed after k queries.

- Define minZeroArray:
    - Initialize:
        - n to the size of nums.
        - left to 0.
        - right to the size of queries.
    - If a zero array cannot be formed at right, return -1, since that means we
processed all the queries without reaching a zero array.
    - Perform binary search on queries. While left is less than or equal to
right:
        - Initialize middle to half of the current search interval (left +
(right - left) / 2).
        - If canFormZeroArray returns false when we pass middle as the k
parameter, set right to middle - 1.
        - Else, set left to middle + 1.
    - Return left, which is the earliest query that a zero array can be formed.
*/

class Solution {
public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), left = 0, right = queries.size();

    if (!canFormZeroarray(nums, queries, right))
      return -1;

    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (canFormZeroarray(nums, queries, middle)) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    return left;
  }
  bool canFormZeroarray(vector<int>& nums, vector<vector<int>>& queries,
                        int k) {
    int n = nums.size(), sum = 0;
    vector<int> differenceArray(n + 1);

    for (int i = 0; i < k; i++) {
      int start = queries[i][0], end = queries[i][1], val = queries[i][2];
      differenceArray[start] += val;
      differenceArray[end + 1] -= val;
    }

    for (int i = 0; i < nums.size(); i++) {
      sum += differenceArray[i];
      if (sum < nums[i])
        return false;
    }
    return true;
  }
};
// Time: O(nlogn)
// Space: O(n)
// Sub:
// https://leetcode.com/problems/zero-array-transformation-ii/submissions/1572208876/?envType=daily-question&envId=2025-03-13
// sol:
// https://leetcode.com/problems/zero-array-transformation-ii/solutions/6531667/3356-zero-array-transformation-ii-by-nal-0njm/
