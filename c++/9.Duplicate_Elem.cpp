/* 217. Contains Duplicate
* return true if any elements appera more than once
*else return false

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false

My Approach:
sort the array,then
if (ith element is equal to i+1){return true}
else {return false}
    */

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    bool flag = true;

    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        return true;
      }
    }
    return flag;
  }
};
