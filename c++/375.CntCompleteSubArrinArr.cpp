/* 2799. Count Complete Subarrays in an Array
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of
distinct elements in the whole array. Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.



Example 1:
Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2],
[3,1,2] and [3,1,2,2].

Example 2:
Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is
complete. The number of subarrays that we can choose is 10.


Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2000
*/

// create all subarray of the given vector
// now check if each subarray has all distinct elements from the original
// subarray
// increase count for each subarray if condition is met
// return count

// approach: use sliding window
/*- Fix the left boundary `left` of the window.

- Use a hash map `cnt` to count occurrences of each element in the current
window.

- Expand the right boundary `right` while the number of different elements in
the window is less than `distinct`.

- Once the number of different elements equals `distinct`, the window `[left,
right)` is a complete subarray.

- Since increasing `right` further will not reduce the number of different
elements, all subarrays starting at `left` and ending from `right` to the end of
the array are valid.

- So, add `n - right + 1` to the result to count all these valid subarrays at
once.

- Each time you move `left`, decrease the count of `nums[left]` in the hash map
by 1.

- If the count becomes 0, remove that element from the hash map.

- Repeat until the left pointer reaches the end.

- Return the total accumulated count of valid complete subarrays.
*/
class Solution {
public:
  int countCompleteSubarrays(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> cnt;
    int n = nums.size();
    int right = 0;
    unordered_set<int> distinct(nums.begin(), nums.end());
    int distinct_count = distinct.size();

    for (int left = 0; left < n; left++) {
      if (left > 0) {
        int remove = nums[left - 1];
        cnt[remove]--;
        if (cnt[remove] == 0) {
          cnt.erase(remove);
        }
      }
      while (right < n && cnt.size() < distinct_count) {
        int add = nums[right];
        cnt[add]++;
        right++;
      }
      if (cnt.size() == distinct_count) {
        res += (n - right + 1);
      }
    }
    return res;
  }
};
// Time: O(n)
// Space: O(n)
// sub:
