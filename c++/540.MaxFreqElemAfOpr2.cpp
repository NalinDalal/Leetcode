/*3347. Maximum Frequency of an Element After Performing Operations II
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each
operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing
the operations.



Example 1:
Input: nums = [1,4,5], k = 1, numOperations = 2
Output: 2

Explanation:
We can achieve a maximum frequency of two by:
Adding 0 to nums[1], after which nums becomes [1, 4, 5].
Adding -1 to nums[2], after which nums becomes [1, 4, 4].

Example 2:
Input: nums = [5,11,20,20], k = 5, numOperations = 1
Output: 2
Explanation:
We can achieve a maximum frequency of two by:
Adding 0 to nums[1].


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
0 <= numOperations <= nums.length


Hint 1
The optimal values to check are nums[i] - k, nums[i], and nums[i] + k.
*/
/*
 */
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    unordered_map<int, int> numCount;
    set<int> modes;

    auto addMode = [&](int value) {
      modes.insert(value);
      if (value - k >= nums.front()) {
        modes.insert(value - k);
      }
      if (value + k <= nums.back()) {
        modes.insert(value + k);
      }
    };

    int lastNumIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != nums[lastNumIndex]) {
        numCount[nums[lastNumIndex]] = i - lastNumIndex;
        ans = max(ans, i - lastNumIndex);
        addMode(nums[lastNumIndex]);
        lastNumIndex = i;
      }
    }

    numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
    ans = max(ans, (int)nums.size() - lastNumIndex);
    addMode(nums[lastNumIndex]);

    auto leftBound = [&](int value) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < value) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return left;
    };

    auto rightBound = [&](int value) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = (left + right + 1) / 2;
        if (nums[mid] > value) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      return left;
    };

    for (int mode : modes) {
      int l = leftBound(mode - k);
      int r = rightBound(mode + k);

      int tempAns;
      if (numCount.count(mode)) {
        tempAns = min(r - l + 1, numCount[mode] + numOperations);
      } else {
        tempAns = min(r - l + 1, numOperations);
      }
      ans = max(ans, tempAns);
    }

    return ans;
  }
};
// sub:https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/submissions/1808277616/?envType=daily-question&envId=2025-10-22
// sol:
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/solutions/7292114/3347-maximum-frequency-of-an-element-aft-vbfk/
