/*594. Longest Harmonious Subsequence
We define a harmonious array as an array where the difference between its
maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious
subsequence among all its possible subsequences.



Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]

Output: 2

Explanation:

The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which
have a length of 2.

Example 3:

Input: nums = [1,1,1,1]

Output: 0

Explanation:

No harmonic subsequence exists.



Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109

*/

/*Approach:
A harmonious subsequence must contain two elements: x and x+1 (or vice versa),
and the difference between the maximum and minimum in the subsequence must be
exactly 1.

So we:

1. Count frequency of each number.

2. For each number x in the map, check if x+1 exists.

3. If it does, we consider count[x] + count[x+1] as a potential answer.

4. Track the maximum of such sums.


*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxLength = 0;

    // Count frequency of each number
    for (int num : nums) {
      freq[num]++;
    }

    // For each key, check if key+1 exists
    for (auto& [num, count] : freq) {
      if (freq.count(num + 1)) {
        maxLength = max(maxLength, count + freq[num + 1]);
      }
    }

    return maxLength;
  }
};
// sub:
// https://leetcode.com/problems/longest-harmonious-subsequence/submissions/1681486903/?envType=daily-question&envId=2025-06-30
// sol:
// https://leetcode.com/problems/longest-harmonious-subsequence/solutions/6903011/594-longest-harmonious-subsequence-by-na-tky7/
int main() {
  vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
  cout << "Output: " << findLHS(nums1) << endl; // 5

  vector<int> nums2 = {1, 2, 3, 4};
  cout << "Output: " << findLHS(nums2) << endl; // 2

  vector<int> nums3 = {1, 1, 1, 1};
  cout << "Output: " << findLHS(nums3) << endl; // 0

  return 0;
}
