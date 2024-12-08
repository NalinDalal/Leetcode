/*
Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false
    */

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int n = sizeof(nums) / sizeof(nums[0]);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        return true;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  Solution.containsDuplicate(nums);

  return 0;
}
