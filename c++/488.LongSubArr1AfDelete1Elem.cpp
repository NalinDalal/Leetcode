/*1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the
resulting array. Return 0 if there is no such subarray.



Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers
with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest
subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.


Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.

Hint 1
Maintain a sliding window where there is at most one zero in it.
*/

/*1. start with 2 pointers `l`,`r`. Start at `0` index
 2. track count of `0` b/w `l` and `r` with help of `zeroCnt`
 3. Expand the window by moving `r` right one step at a time.
        - If `nums[r] == 0`, `zeroCnt++`.
 4. while(zeroCnt>1){
        if(nums[l]==0){zeroCnt--;l++;}
 }
 5. after fixing window, update the ans
    subArr length=`(r-l)`
 6. continue till `r` reaches end of Array i.e. `r==nums.length()-1`
    */
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, zeroCnt = 0, ans = 0;

    for (int r = 0; r < n; ++r) {
      if (nums[r] == 0)
        ++zeroCnt;

      // Ensure window has at most one zero
      while (zeroCnt > 1) {
        if (nums[l] == 0)
          --zeroCnt;
        ++l;
      }

      // r - l is (window length) - 1, matching "delete one element"
      ans = max(ans, r - l);
    }
    return ans;
  }
};

// sub:
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1746042570/?envType=daily-question&envId=2025-08-24
// sol:
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/solutions/7114934/1493-longest-subarray-of-1s-after-deleti-guqu/
