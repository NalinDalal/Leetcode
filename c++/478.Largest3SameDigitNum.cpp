/*2264. Largest 3-Same-Digit Number in String
You are given a string num representing a large integer. An integer is good if
it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such
integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.


Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit.
Therefore, there are no good integers.


Constraints:

3 <= num.length <= 1000
num only consists of digits.

Hint 1
We can sequentially check if “999”, “888”, “777”, … , “000” exists in num in
that order. The first to be found is the maximum good integer. Hint 2 If we
cannot find any of the above integers, we return an empty string “”.
*/

/*see we want largest 3 digit num in string which has only 1 digit
so there are only 9 possibilites
999,888,777 like that

so let's say we traverse the string fromleft to right
check for 3 places, like i,i+1,i+2

store it in a ans string
when we find another 3 digit which are greater than stored one
replace it

when string traversed fully, returnt he ans string
*/

class Solution {
public:
  string largestGoodInteger(string num) {
    string ans = "";

    for (int i = 0; i + 2 < (int)num.size(); i++) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        string triplet = num.substr(i, 3);
        if (triplet > ans) {
          ans = triplet;
        }
      }
    }

    return ans;
  }
};

// sub:
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1734433115/?envType=daily-question&envId=2025-08-14
// sol:
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/solutions/7077957/2264-largest-3-same-digit-number-in-stri-r0lp/
