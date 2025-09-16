/*2197. Replace Non-Coprime Numbers in Array
You are given an array of integers nums. Perform the following steps:

Find any two adjacent numbers in nums that are non-coprime.
If no such numbers are found, stop the process.
Otherwise, delete the two numbers and replace them with their LCM (Least Common
Multiple). Repeat this process as long as you keep finding two adjacent
non-coprime numbers. Return the final modified array. It can be shown that
replacing adjacent non-coprime numbers in any arbitrary order will lead to the
same result.

The test cases are generated such that the values in the final array are less
than or equal to 108.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the
Greatest Common Divisor of x and y.



Example 1:

Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation:
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
Example 2:

Input: nums = [2,2,1,1,3,3,3]
Output: [2,1,1,3]
Explanation:
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
The test cases are generated such that the values in the final array are less
than or equal to 108.

Hint 1
Notice that the order of merging two numbers into their LCM does not matter so
we can greedily merge elements to its left if possible. Hint 2 If a new value is
formed, we should recursively check if it can be merged with the value to its
left. Hint 3 To simulate the merge efficiently, we can maintain a stack that
stores processed elements. When we iterate through the array, we only compare
with the top of the stack (which is the value to its left).
*/

/*given a array of integers nums
 return a new array by replacing all of adjacent non-coprime with their lcm
 do this recursively

 once the pattern breaks, return the array

 so basically like nums[i] and nums[i+1] are adjacent
 check if they are coprime, if then replace them with their lcm
 check new value with it's left neighbour
 if not then move ahead

 if you got to end of the array, return the array

 to do it efficiently the stack can be used,
 stack stores processed elements, compare with only top of stack
*/

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> st;
    for (int x : nums) {
      st.push_back(x);
      // keep merging while top two are not coprime
      while (st.size() > 1) {
        int a = st.back();
        st.pop_back();
        int b = st.back();
        st.pop_back();
        int g = gcd(a, b);
        if (g == 1) { // coprime, stop merging
          st.push_back(b);
          st.push_back(a);
          break;
        } else {
          long long l = 1LL * a / g * b; // avoid overflow
          st.push_back((int)l);
        }
      }
    }
    return st;
  }
};
// sub:
// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/submissions/1772179439/?envType=daily-question&envId=2025-09-16
// sol:
// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/solutions/7194528/2197-replace-non-coprime-numbers-in-arra-c210/
