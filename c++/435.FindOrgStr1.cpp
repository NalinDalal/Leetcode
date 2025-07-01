/*3330. Find the Original Typed String I
Alice is attempting to type a specific string on her computer. However, she
tends to be clumsy and may press a key for too long, resulting in a character
being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still
have done this at most once.

You are given a string word, which represents the final output displayed on
Alice's screen.

Return the total number of possible original strings that Alice might have
intended to type.



Example 1:

Input: word = "abbcccc"

Output: 5

Explanation:

The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

Input: word = "abcd"

Output: 1

Explanation:

The only possible string is "abcd".

Example 3:

Input: word = "aaaa"

Output: 4



Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.

Hint 1
Any group of consecutive characters might have been the mistake.
*/

// like find permutation of each letter in the string
// like there are 4 a'-> so either 1 time or 2 time or 3 time or 4 time
// so like in 'abbcccc' -> 'abcccc','abbcc','abbc','abbccc','abbcccc'
// put them in a vector, return length of that vector

// for k times repeatation, there are k-1 cases
// if(k=1) then 0 possibilities
// hence traverse string once
// from l to r i.e. [l,r] chars are same
// while at r+1 is diff
// ans+=(r-l), shift the window from l to r+1
// total combination in [l,r] is r-l
// l doesn't contributes, while from l+1 it does
// for any position i in the string word (where i>0), if word[i−1]=word[i], we
// can increase the answer by 1.

class Solution {

public:
  int possibleStringCount(string word) {
    int n = word.size(), ans = 1;
    for (int i = 1; i < n; ++i) {
      if (word[i - 1] == word[i]) {
        ++ans;
      }
    }
    return ans;
  }
};

// Time: O(n)
// Space: O(1)
// Sub:
// Sol:
// https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6907639/3330-find-the-original-typed-string-i-by-lyxp/
