/* 3375. Minimum Operations to Make Array Values Equal to K
You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly
greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all
nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

Select an integer h that is valid for the current values in nums.
For each index i where nums[i] > h, set nums[i] to h.
Return the minimum number of operations required to make every element in nums
equal to k. If it is impossible to make all elements equal to k, return -1.



Example 1:
Input: nums = [5,2,5,4,5], k = 2
Output: 2
Explanation:
The operations can be performed in order using valid integers 4 and then 2.

Example 2:
Input: nums = [2,1,2], k = 2
Output: -1
Explanation:It is impossible to make all the values equal to 2.

Example 3:
Input: nums = [9,7,5,3], k = 1
Output: 4
Explanation:The operations can be performed using valid integers in the order 7,
5, 3, and 1.



Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100

Hint 1: Handle the case when the array contains an integer less than k
Hint 2: Start by performing operations on the highest integer
Hint 3: You can perform an operation on the highest integer using the
second-highest, an operation on the second-highest using the third-highest, and
so forth. Hint 4: The answer is the number of distinct integers in the array
that are larger than k.
*/

// all value greater than h are same value
// for every value >h, set it to h
/* 1. You can only reduce values.

2. Any value < k can never be increased — so it’s impossible if any nums[i] < k.

3. You want to repeatedly choose a valid h to reduce all larger values in one
step.

4. So the problem becomes:

- Repeatedly reduce values > k to k.

- Only reduce when all values above h are the same — i.e., the “top layer” is
uniform.
*/
/* Approach
1. Edge case check:
    - If any nums[i] < k, return -1 (can't increase).

2. Initialize a counter for operations = 0.
3. While not all elements are k:
    - Identify the maximum value in nums.
    - If max == k, done.
    - Else:
        - Check that all values == max.
        - If so, you can reduce them to the next largest value in nums (or k,
whichever is larger).
        - That’s one valid operation → increment ops.

4. Repeat until all values become k.
*/

class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    unordered_set<int> st;
    for (int x : nums) {
      if (x < k) {
        return -1;
      } else if (x > k) {
        st.insert(x);
      }
    }
    return st.size();
  }
};
// sub:
// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/submissions/1601202362/?envType=daily-question&envId=2025-04-09
