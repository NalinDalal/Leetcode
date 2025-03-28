/*373. Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order
and an integer k.

Define a pair (u, v) which consists of one element from the first array and one
element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6] Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length
*/

// intuition:
//  just make pair of elements of nums1, nums2, put it in a vector
//  sort htme based on their sum
//  return k smallest pairs
//  if we make a  of vector<int> and sum of pair
//  then sort based on sum
//  return k smallest pairs

// Approach:
/*1. Use a min-heap (priority queue) to store pairs (`nums1[i]`, `nums2[j]`)
sorted by `sum`.

2. Push the smallest pairs first (starting from (`nums1[0]`, `nums2[0]`)).

3. Extract `k` smallest pairs from the heap while pushing the next potential
pair from `nums1` or `nums2`.

4. Avoid brute force sorting, which would be `O(N1 * N2 log(N1 * N2))`.

    */
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> ans;
    if (nums1.empty() || nums2.empty() || k == 0)
      return ans;

    // Min-heap: stores {sum, index in nums1, index in nums2}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        minHeap;

    // Push the first row of pairs (nums1[i], nums2[0]) into heap
    for (int i = 0; i < nums1.size() && i < k; i++) {
      minHeap.emplace(nums1[i] + nums2[0], i, 0);
    }

    // Extract the k smallest pairs
    while (k-- > 0 && !minHeap.empty()) {
      auto [sum, i, j] = minHeap.top();
      minHeap.pop();
      ans.push_back({nums1[i], nums2[j]});

      // Push the next element in nums2 for the same nums1[i]
      if (j + 1 < nums2.size()) {
        minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
      }
    }

    return ans;
  }
};
// Time: O(n)
// Space: O(n^2)
// sub:
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/submissions/1588853002/?envType=study-plan-v2&envId=top-interview-150
// sol: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/6588451/373-find-k-pairs-with-smallest-sums-by-n-nk6m/
