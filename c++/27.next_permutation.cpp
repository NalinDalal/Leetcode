/*
31. Next Permutation

A permutation of an array of integers is an arrangement of its members into a
sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]. The next permutation
of an array of integers is the next lexicographically greater permutation of its
integer. More formally, if all the permutations of the array are sorted in one
container according to their lexicographical order, then the next permutation of
that array is the permutation that follows it in the sorted container. If such
arrangement is not possible, the array must be rearranged as the lowest possible
order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
have a lexicographical larger rearrangement. Given an array of integers nums,
find the next permutation of nums.

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
*/

// Aproach->
/*
 * find max(k) for kth index is less than k+1 index
 *  if(k==-1) reverse the array(because no such k found)
 *  find max(l) for lth index is greater than kth index
 *  swap both kth and lth index
 *  reverse the array from k+1th index to end
 * */
// Code->
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int k = n - 2;

    // Step 1: Find the largest index k such that nums[k] < nums[k + 1]
    while (k >= 0 && nums[k] >= nums[k + 1]) {
      k--;
    }

    if (k == -1) { // No such k found, the array is in descending order
      std::reverse(
          nums.begin(),
          nums.end()); // Reverse the array to get the lowest possible order
      return;
    }

    // Step 2: Find the largest index l greater than k such that nums[k] <
    // nums[l]
    int l = n - 1;
    while (nums[l] <= nums[k]) {
      l--;
    }

    // Step 3: Swap nums[k] with nums[l]
    std::swap(nums[k], nums[l]);

    // Step 4: Reverse the sequence from nums[k + 1] to the end of the array
    std::reverse(nums.begin() + k + 1, nums.end());
  }
};
