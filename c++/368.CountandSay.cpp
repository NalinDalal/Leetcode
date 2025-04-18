/* 38. Count and Say
The count-and-say sequence is a sequence of digit strings defined by the
recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing
consecutive identical characters (repeated 2 or more times) with the
concatenation of the character and the number marking the count of the
characters (length of the run). For example, to compress the string "3322251" we
replace "33" with "23", replace "222" with "32", replace "5" with "15" and
replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say
sequence.



Example 1:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"

Example 2:
Input: n = 1
Output: "1"
Explanation:This is the base case.


Constraints: 1 <= n <= 30
Follow up: Could you solve it iteratively? */

// Count-and-Say Sequence?
// It's a sequence of strings where each term is described by the previous term
// using run-length encoding — but instead of encoding by "char and count", you
// do it in the format: “count” + “value”

/* Each countAndSay(n) is:
- Count how many times each digit repeats consecutively in countAndSay(n-1)
- Then say: "number of times" + "digit"*/
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1)
      return "1";

    string prev = countAndSay(n - 1);
    string result = "";
    int count = 1;

    for (int i = 1; i <= prev.size(); i++) {
      if (i < prev.size() && prev[i] == prev[i - 1]) {
        count++;
      } else {
        result += to_string(count) + prev[i - 1];
        count = 1;
      }
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/count-and-say/submissions/1610130356/?envType=daily-question&envId=2025-04-18
// sol:
// https://leetcode.com/problems/count-and-say/solutions/6662271/38-count-and-say-by-nalindalal2004-tqmx/
