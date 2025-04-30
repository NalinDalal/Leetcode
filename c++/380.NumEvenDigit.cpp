/* 1295. Find Numbers with Even Number of Digits
Given an array nums of integers, return how many of them contain an even number
of digits.

Example 1:
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.

Example 2:
Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.


Constraints:
1 <= nums.length <= 500
1 <= nums[i] <= 105

Hint 1
How to compute the number of digits of a number ?
Hint 2
Divide the number by 10 again and again to get the number of digits.
*/

#include <string>
class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
      if (cntDigit(num) % 2 == 0)
        ans++;
    }
    return ans;
  }
  int cntDigit(int num) {
    // num.to_string();
    std::string numStr = std::to_string(num);
    return numStr.length();
  }
};
// sub:
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/1621651281/?envType=daily-question&envId=2025-04-30
// optimised:
class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
      if (countDigits(num) % 2 == 0)
        ans++;
    }
    return ans;
  }

private:
  int countDigits(int num) {
    int digits = 0;
    while (num) {
      num /= 10;
      digits++;
    }
    return digits;
  }
};
// sub:
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/submissions/1621654013/?envType=daily-question&envId=2025-04-30
