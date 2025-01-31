/* https://leetcode.com/problems/permutations/description/
46. Permutations

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.



Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]


Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <vector>
using std::vector;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    // just return all permutations of nums
    // use backtracking
    // so do like have a temp vector for iteration
    // and check if temp vector is same as nums
    // if not then use it else just return the original
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    backtrack(nums, temp, used, ans);
    return ans;
  }

private:
  void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used,
                 vector<vector<int>>& ans) {
    if (temp.size() == nums.size()) {
      ans.push_back(temp);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i])
        continue;
      used[i] = true;
      temp.push_back(nums[i]);
      backtrack(nums, temp, used, ans);
      temp.pop_back();
      used[i] = false;
    }
  }
};

// Time: O(n)
// Space:O(n)
// sub: https://leetcode.com/problems/permutations/submissions/1526651099/
// sol:
// https://leetcode.com/problems/permutations/solutions/6353246/46-permutations100-by-nalindalal2004-kwg8/
