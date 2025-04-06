/* 368. Largest Divisible Subset
 * Given a set of distinct positive integers nums, return the largest subset
answer such that every pair (answer[i], answer[j]) of elements in this subset
satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of
them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
// For every pair (i, j) in the result: answer[i] % answer[j] == 0 or answer[j]
// % answer[i] == 0
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty())
      return {};

    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> dp(n,
                   1); // dp[i] = length of longest divisible subset ending at i
    vector<int> prev(n, -1); // prev[i] = previous index in the subset
    int maxIdx = 0;

    // Build up the dp and prev arrays
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[maxIdx]) {
        maxIdx = i;
      }
    }

    // Reconstruct the subset from dp and prev
    vector<int> result;
    for (int i = maxIdx; i >= 0; i = prev[i]) {
      result.push_back(nums[i]);
      if (prev[i] == -1)
        break;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};
// sub:
// https://leetcode.com/problems/largest-divisible-subset/submissions/1598122898/?envType=daily-question&envId=2025-04-06
// sol:
// https://leetcode.com/problems/largest-divisible-subset/solutions/6620526/368-largest-divisible-subset-by-nalindal-m15d/
