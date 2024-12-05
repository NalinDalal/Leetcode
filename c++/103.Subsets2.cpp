/* 90. Subsets II

Given an integer array nums that may contain duplicates, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any
order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// what is power set?
// a set containing all subset of a given set

// intuition: n isze vector, n^2 no of subsets
// first of all insert empty array
// then move from 0 to n-1 and make pair of 0 with each elem, with same thing
// internally, return vector of vector

// for duplicate logic-> sort the input array first

// Approach:
/* Sorting the Input: The input array nums is sorted first to ensure that
duplicates are adjacent, making it easier to skip them during recursion.
Backtracking:
The function backtrack is used to generate all possible subsets. It recursively
adds elements to the current subset and explores further subsets. Duplicates are
skipped by checking if the current element is the same as the previous one
(i.e., nums[i] == nums[i - 1]), and this check ensures we don’t generate the
same subset multiple times. Base Case: Every time the recursion progresses, the
current subset is added to the result.
*/
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> powerSet;
    powerSet.push_back({}); // Insert the empty set

    // Iterate over each element
    for (int num : nums) {
      int n = powerSet.size();
      // For each existing subset, create a new subset by adding the current
      // element
      for (int i = 0; i < n; ++i) {
        vector<int> newSubset = powerSet[i];
        newSubset.push_back(num);
        powerSet.push_back(newSubset);
      }
    }

    return powerSet;
  }

  void backtrack(vector<int> &nums, int start, vector<int> &current,
                 vector<vector<int>> &result) {
    result.push_back(current); // Add the current subset to the result

    // Iterate through the elements starting from 'start' index
    for (int i = start; i < nums.size(); ++i) {
      // Skip duplicates by checking if the current element is the same as the
      // previous one
      if (i > start && nums[i] == nums[i - 1])
        continue;

      // Include the current element and move to the next
      current.push_back(nums[i]);
      backtrack(nums, i + 1, current, result);
      current.pop_back(); // Backtrack and remove the last element
    }
  }

  vector<vector<int>> generatePowerSet(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;

    // Sort the input to handle duplicates
    sort(nums.begin(), nums.end());

    // Start backtracking
    backtrack(nums, 0, current, result);

    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 2}; // Example with duplicates
  vector<vector<int>> result1 = s.generatePowerSet(nums1);

  // Print the power set
  for (const auto &subset : result1) {
    cout << "[";
    for (int i = 0; i < subset.size(); ++i) {
      cout << subset[i] << (i == subset.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
  }

  return 0;
}

/*
Time Complexity: The time complexity is O(2^n), where  n is the number of
elements in nums, since we're generating all subsets. The sorting step takes
O(nlogn), but the backtracking step dominates in terms of the total time
complexity.

Space Complexity: The space complexity is O(2 ^n), due to the storage of all
subsets in the result. */

// 100%
