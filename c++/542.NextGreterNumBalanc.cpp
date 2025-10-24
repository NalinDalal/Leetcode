/*2048. Next Greater Numerically Balanced Number
An integer x is numerically balanced if for every digit d in the number x, there
are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly
greater than n.



Example 1:

Input: n = 1
Output: 22
Explanation:
22 is numerically balanced since:
- The digit 2 occurs 2 times.
It is also the smallest numerically balanced number strictly greater than 1.
Example 2:

Input: n = 1000
Output: 1333
Explanation:
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
Example 3:

Input: n = 3000
Output: 3133
Explanation:
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.


Constraints:

0 <= n <= 106


Hint 1
How far away can the next greater numerically balanced number be from n?
Hint 2
With the given constraints, what is the largest numerically balanced number?
*/
/*int ans;
        //ans > n
        //ans i balanced,
        //ans must have d occurences od digit d
        return ans;

approach:
You can precompute all balanced numbers up to 10^7 for faster performance:
    */

class Solution {
public:
  bool isBalanced(int num) {
    string s = to_string(num);
    vector<int> freq(10, 0);
    for (char c : s)
      freq[c - '0']++;
    for (int d = 0; d < 10; ++d) {
      if (freq[d] > 0 && freq[d] != d)
        return false;
    }
    return true;
  }

  int nextBeautifulNumber(int n) {
    for (int i = n + 1;; ++i) {
      if (isBalanced(i))
        return i;
    }
  }
};
// sub:
// https://leetcode.com/problems/next-greater-numerically-balanced-number/submissions/1809964536/?envType=daily-question&envId=2025-10-24
// sol:
// https://leetcode.com/problems/next-greater-numerically-balanced-number/solutions/7296274/2048-next-greater-numerically-balanced-n-pfei/
