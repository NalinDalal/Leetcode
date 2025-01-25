/* 2948. Make Lexicographically Smallest Array by Swapping Elements

You are given a 0-indexed array of positive integers nums and a positive integer
limit.

In one operation, you can choose any two indices i and j and swap nums[i] and
nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing
the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position
where a and b differ, array a has an element that is less than the corresponding
element in b. For example, the array [2,10,3] is lexicographically smaller than
the array [10,2,3] because they differ at index 0 and 2 < 10.



Example 1:
Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more
operations. Note that it may be possible to get the same result by doing
different operations.

Example 2:
Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more
operations.

Example 3:
Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can
obtain because we cannot apply the operation on any two indices.


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= limit <= 109*/

// return lexicographically smallest array, ex [2,10,3] is lexicographically
// smaller than the array [10,2,3]
#include <ranges>
class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
    auto sorted = arr;
    sort(begin(sorted), end(sorted));
    auto groups = sorted | views::chunk_by([limit](int x, int y) {
                    return y - x <= limit;
                  });
    vector<vector<int>::iterator> group_iters;
    vector<int> group_heads;
    for (auto group : groups) {
      group_iters.push_back(group.begin());
      group_heads.push_back(group.front());
    }
    for (auto& x : arr) {
      auto it = prev(upper_bound(group_heads.begin(), group_heads.end(), x));
      auto& g_it = group_iters[distance(group_heads.begin(), it)];
      x = *g_it++;
    }
    return arr;
  }
};
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

/* Intuition
The goal is to rearrange an array to make it lexicographically smallest,
considering a limit that groups elements based on their proximity. By leveraging
C++ Ranges, we can efficiently:

1. Sort the array for lexicographical order.
2. Group elements based on the limit condition.
3. Iterate through the original array, replacing elements with the smallest
available value from their respective group. This approach makes sure the output
remains lexicographically smallest while respecting the limit.

Approach
1.`Sort the array` - This prepares elements for grouping based on proximity.
2.`Group elements1 - Use `ranges::chunk b​ y` to form groups where consecutive
elements differ by at most `limit`. 3.`Track group heads` - Maintain pointers to
the smallest unprocessed element in each group. 4.`Replace elements` - For each
element in the original array, find its group, replace it with the smallest
available element, and move the pointer forward.

Complexity 📊
Time Complexity O(nlogn)

Sorting takes O(nlogn).
Grouping and replacing elements are linear operations, O(n).
Space Complexity O(n) Additional space is used for sorted arrays, group
iterators, and group heads.

100% */
// sub:
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/submissions/1519731818/?envType=daily-question&envId=2025-01-25
// sol:
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/solutions/6326559/2948-make-lexicographically-smallest-arr-5scm/
