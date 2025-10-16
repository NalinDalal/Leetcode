/*2598. Smallest Missing Non-negative Integer After Operations
You are given a 0-indexed integer array nums and an integer value.

In one operation, you can add or subtract value from any element of nums.

For example, if nums = [1,2,3] and value = 2, you can choose to subtract value
from nums[0] to make nums = [-1,2,3]. The MEX (minimum excluded) of an array is
the smallest missing non-negative integer in it.

For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2.
Return the maximum MEX of nums after applying the mentioned operation any number
of times.



Example 1:
Input: nums = [1,-10,7,13,6,8], value = 5
Output: 4
Explanation: One can achieve this result by applying the following operations:
- Add value to nums[1] twice to make nums = [1,0,7,13,6,8]
- Subtract value from nums[2] once to make nums = [1,0,2,13,6,8]
- Subtract value from nums[3] twice to make nums = [1,0,2,3,6,8]
The MEX of nums is 4. It can be shown that 4 is the maximum MEX we can achieve.

Example 2:
Input: nums = [1,-10,7,13,6,8], value = 7
Output: 2
Explanation: One can achieve this result by applying the following operation:
- subtract value from nums[2] once to make nums = [1,-10,0,13,6,8]
The MEX of nums is 2. It can be shown that 2 is the maximum MEX we can achieve.


Constraints:
1 <= nums.length, value <= 105
-109 <= nums[i] <= 109

Hint 1
Think about using modular arithmetic.
Hint 2
if x = nums[i] (mod value), then we can make nums[i] equal to x after some
number of operations Hint 3 How does finding the frequency of (nums[i] mod
value) help?
*/

/*Approach:
nums[i] can be transformed into any number ≡ nums[i] (mod value).

So what matters is the remainder when nums[i] is divided by value.

>>> Hint 1: Use modular arithmetic.
>>> → Focus on nums[i] % value.

>>> Hint 2:
>>> If x = nums[i] % value, we can make nums[i] become any integer k such that k
% value == x.

>>> Hint 3:
>>> If we know how many numbers have each remainder, we can simulate filling
numbers 0, 1, 2, ... in order.

let `nums={1, 2, 3, 4, 5}`, `value = 3`

Compute all remainders mod 3:
```
nums % 3 = [1, 2, 0, 1, 2]
count = {0: 1, 1: 2, 2: 2}
```

look for the smallest non-negative integer not representable after adjustments.

think:
- We can make one number with remainder `0` become 0.
- Two numbers with remainder `1` become 1 and 4 (1 + 3).
- Two numbers with remainder `2` become 2 and 5 (2 + 3).

We can fill up numbers until one of the remainders runs out.

To find Smallest Integer
smallest m such that `freq[m % value] ≤ m / value`

For each number `m` starting from 0:
    - If we’ve already used up all numbers that have remainder `m % value`
enough times, then `m` can’t be formed.

*/

class Solution {
public:
  int findSmallestInteger(vector<int>& nums, int value) {
    unordered_map<int, int> freq;
    for (int x : nums) {
      int r = ((x % value) + value) % value; // handle negatives
      freq[r]++;
    }

    int m = 0;
    while (true) {
      int r = m % value;
      if (freq[r] == 0)
        return m;
      freq[r]--;
      m++;
    }
  }
};

// sub:
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/submissions/1803119778/?envType=daily-question&envId=2025-10-16
// sol:
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/solutions/7279095/2598-smallest-missing-non-negative-integ-xvdp/
