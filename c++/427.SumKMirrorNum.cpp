/* 2081. Sum of k-Mirror Numbers
A k-mirror number is a positive integer without leading zeros that reads the
same both forward and backward in base-10 as well as in base-k.

For example, 9 is a 2-mirror number. The representation of 9 in base-10 and
base-2 are 9 and 1001 respectively, which read the same both forward and
backward. On the contrary, 4 is not a 2-mirror number. The representation of 4
in base-2 is 100, which does not read the same both forward and backward. Given
the base k and the number n, return the sum of the n smallest k-mirror numbers.



Example 1:

Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed
as follows: base-10    base-2 1          1 3          11 5          101 7 111 9
1001 Their sum = 1 + 3 + 5 + 7 + 9 = 25. Example 2:

Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are
listed as follows: base-10    base-3 1          1 2          2 4          11 8
22 121        11111 151        12121 212        21212 Their sum = 1 + 2 + 4 + 8
+ 121 + 151 + 212 = 499. Example 3:

Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064,
6597956, 6958596


Constraints:

2 <= k <= 9
1 <= n <= 30


Hint 1
Since we need to reduce search space, instead of checking if every number is a
palindrome in base-10, can we try to "generate" the palindromic numbers? Hint 2
If you are provided with a d digit number, how can you generate a palindrome
with 2*d or 2*d - 1 digit? Hint 3 Try brute-forcing and checking if the
palindrome you generated is a "k-Mirror" number.
*/

// Intuition:
/* Generate base-10 palindromes in increasing order.

Convert each to base-k.

Check if it's a palindrome in base-k.

If yes, it's a k-Mirror number. */

// Algorithm/Solution:
/* iterate from 1 to n, if i is palindrome, k-ary representation also
palindrome, add to
* sum
* after n num, stop-> problem: tle

so let's try genearting num, generate only 1st half say i, rest will be i`
hence search space reduces,
consider both odd, even length; ex: i'=123 so 12321 or 123321

To enumerate values of i, we also incrementally enumerate values of i' .
For the same i ′ , the even-length palindrome will always be greater than the
corresponding odd-length one, so we process them as follows:
- Define the range of i ′ , typically as [10 ^k ,10 ^k+1 ) for some k.
- Incrementally generate odd-length palindromes from i ′  and check if they meet
the requirements.
- Then generate even-length palindromes from i ′ and check if they meet the
requirements.
*/

class Solution {
private:
  int digit[100];

public:
  long long kMirror(int k, int n) {
    auto isPalindrome = [&](long long x) -> bool {
      int length = -1;
      while (x) {
        ++length;
        digit[length] = x % k;
        x /= k;
      }
      for (int i = 0, j = length; i < j; ++i, --j) {
        if (digit[i] != digit[j]) {
          return false;
        }
      }
      return true;
    };

    int left = 1, count = 0;
    long long ans = 0;
    while (count < n) {
      int right = left * 10;
      // op = 0 indicates enumerating odd-length palindromes
      // op = 1 indicates enumerating even-length palindromes
      for (int op = 0; op < 2; ++op) {
        // enumerate i'
        for (int i = left; i < right && count < n; ++i) {
          long long combined = i;
          int x = (op == 0 ? i / 10 : i);
          while (x) {
            combined = combined * 10 + x % 10;
            x /= 10;
          }
          if (isPalindrome(combined)) {
            ++count;
            ans += combined;
          }
        }
      }
      left = right;
    }
    return ans;
  }
};
// Time: O(sqrt(10^10))  // plain fallback
// SPace: O(1)
//  sub:
//  https://leetcode.com/problems/sum-of-k-mirror-numbers/submissions/1674016181/?envType=daily-question&envId=2025-06-23
//  sol:
//  https://leetcode.com/problems/sum-of-k-mirror-numbers/solutions/6877513/2081-sum-of-k-mirror-numbers-by-nalindal-jkn0/
