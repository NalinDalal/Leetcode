/* 152. Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and
return the product.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int max_prod = INT_MIN;
    for (int i = 0; i < n; i++) {
      int prod = 1;
      for (int j = i; j < n; j++) {
        prod = prod * nums[j];
        max_prod = max(max_prod, prod);
      }
    }
    return max_prod;
  }
};
