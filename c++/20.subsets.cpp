/*
* 78. Subsets
Solved
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
#include <vector>
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper(0, nums, curSet, subsets);
    return subsets;
  }
  void helper(int i, vector<int>& nums, vector<int>& curSet,
              vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
      subsets.push_back(vector<int>(curSet));
      return;
    }

    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper(i + 1, nums, curSet, subsets);
    curSet.pop_back();

    // decision NOT to include nums[i]
    helper(i + 1, nums, curSet, subsets);
  }

  vector<vector<int>> subsetWithDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> curSet;
    vector<vector<int>> subsets;
    helper2(0, nums, curSet, subsets);
    return subsets;
  }

  void helper2(int i, vector<int>& nums, vector<int>& curSet,
               vector<vector<int>>& subsets) {
    if (i >= nums.size()) {
      subsets.push_back(vector<int>(curSet));
      return;
    }
    // decision to include nums[i]
    curSet.push_back(nums[i]);
    helper2(i + 1, nums, curSet, subsets);
    curSet.pop_back();
    // decison NOT to include nums[i]
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
      i++;
    }
    helper2(i + 1, nums, curSet, subsets);
  }
};
