/*
 * 15. 3Sum
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter. Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

    */

/*Soln:
 * 2 sum me jese ek ko check krke ye dekh rhe the ki sum se minus krne pr agar
jo element aayega wo carray me h to okay

same yaha pr->phele sort krdo
agar duplicate aaye to chlte rho

aur like ith element pr 2 sum laga do
    * */
// Time-> o(n^2)
// Space->o(n)

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue; // Skip duplicate values

      int target = -nums[i]; // Adjust the target value
      int j = i + 1, k = nums.size() - 1;

      while (j < k) {
        int sum = nums[j] + nums[k];
        if (sum == target) {
          result.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1])
            j++; // Skip duplicate values
          while (j < k && nums[k] == nums[k - 1])
            k--; // Skip duplicate values
          j++;
          k--;
        } else if (sum < target) {
          j++;
        } else {
          k--;
        }
      }
    }

    return result;
  }
};
