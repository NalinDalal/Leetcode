/* 2099. Find Subsequence of Length K With the Largest Sum

You are given an integer array nums and an integer k. You want to find a
subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.


Example 1:
Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.

Example 3:
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].


Constraints:
1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length


Hint 1
From a greedy perspective, what k elements should you pick?
Hint 2
Could you sort the array while maintaining the index?
*/

// sort the nums
// then pick the last k elements
// return the subsequence

/*Strategy/Approach
1. Store each number with its index: {num, index}.

2. Sort these pairs by value in descending order.

3. Take the top k elements.

4. Sort those k elements by original index to maintain subsequence order.

5. Extract the values and return.
    */

class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    // Step 1: Pair values with their indices
    vector<pair<int, int>> withIndex;
    for (int i = 0; i < nums.size(); ++i) {
      withIndex.push_back({nums[i], i});
    }

    // Step 2: Sort by value descending
    sort(withIndex.begin(), withIndex.end(),
         [](auto& a, auto& b) { return a.first > b.first; });

    // Step 3: Pick top k and sort by original index
    vector<pair<int, int>> topK(withIndex.begin(), withIndex.begin() + k);
    sort(topK.begin(), topK.end(),
         [](auto& a, auto& b) { return a.second < b.second; });

    // Step 4: Extract values
    vector<int> result;
    for (auto& p : topK) {
      result.push_back(p.first);
    }

    return result;
  }
};
// Time: O(n log n)
// Space: O(n)

// sub:
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/submissions/1679312641/?envType=daily-question&envId=2025-06-28
// sol:
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/solutions/6895734/2099-find-subsequence-of-length-k-with-t-83bh/
