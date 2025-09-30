/*2221. Find Triangular Sum of an Array
You are given a 0-indexed integer array nums, where nums[i] is a digit between 0
and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums
after the following process terminates:

Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a
new 0-indexed integer array newNums of length n - 1. For each index i, where 0
<= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10,
where % denotes modulo operator. Replace the array nums with newNums. Repeat the
entire process starting from step 1. Return the triangular sum of nums.



Example 1:


Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of
the array. Example 2:

Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that
element itself.


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 9

Hint 1
Try simulating the entire process.
Hint 2
To reduce space, use a temporary array to update nums in every step instead of
creating a new array at each step.
*/

/*given a array named nums, create a new vector named newNums of length n-1
 if nums.size()==1 return nums[0]
 else{
    for(int i=0;i<n-1;i++){
        newNums[i]=(nums[i] + nums[i+1]) % 10
    }
 }
 if(newNums.size()==1)return newNums[0]
 else use recursion to do this process again
*/
/*well this approach was i would say slow so
Instead of building smaller arrays again and again, we can observe that the
final triangular sum is just a weighted sum of the original elements with
binomial coefficients (like Pascal’s triangle).
             */
class Solution {
public:
  int triangularSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> C(n, 0);
    C[0] = 1;

    // build binomial coefficients mod 10
    for (int i = 1; i < n; i++) {
      for (int j = i; j > 0; j--) {
        C[j] = (C[j] + C[j - 1]) % 10;
      }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
      result = (result + C[i] * nums[i]) % 10;
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/find-triangular-sum-of-an-array/submissions/1787019423/?envType=daily-question&envId=2025-09-30
// sol:
// https://leetcode.com/problems/find-triangular-sum-of-an-array/solutions/7235693/2221-find-triangular-sum-of-an-array-by-2cyt7/
