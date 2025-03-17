/*2206. Divide Array Into Equal Pairs

You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.



Example 1:

Input: nums = [3,2,3,2,2,2]
Output: true
Explanation:
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy
all the conditions. Example 2:

Input: nums = [1,2,3,4]
Output: false
Explanation:
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy
every condition.


Constraints:

nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
*/

// divide into n pairs
// each pair has same and equal element

// Approach
/*1. If any element appears an odd number of times, it cannot be paired
completely.
2. We can use a hash map (unordered_map) or a frequency array (if the numbers
are small) to count occurrences.
3. If all elements have even counts, we return true; otherwise, return false.
 */
class Solution {
public:
  bool divideArray(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : nums) {
      freq[num]++;
    }

    // Check if all frequencies are even
    for (auto& [key, count] : freq) {
      if (count % 2 != 0) {
        return false;
      }
    }

    return true;
  }
};

// sub:
// https://leetcode.com/problems/divide-array-into-equal-pairs/submissions/1576397694/?envType=daily-question&envId=2025-03-17

// alt:
class Solution {
public:
  bool divideArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      if (nums[i] != nums[i + 1])
        return false;
    }
    return true;
  }
};
// sub:
// https://leetcode.com/problems/divide-array-into-equal-pairs/submissions/1576401257/?envType=daily-question&envId=2025-03-17
//  sol:
//  https://leetcode.com/problems/divide-array-into-equal-pairs/solutions/6545739/2206-divide-array-into-equal-pairs-by-na-bn4y/
