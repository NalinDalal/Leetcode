/* 2375. Construct Smallest Number From DI String

You are given a 0-indexed string pattern of length n consisting of the
characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following
conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the
conditions.



Example 1:
Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the
conditions. Note that "123414321" is not possible because the digit '1' is used
more than once.

Example 2:
Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the
conditions.


Constraints:
1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.

Hint 1: With the constraints, could we generate every possible string?
Hint 2: Yes we can. Now we just need to check if the string meets all the
conditions.
*/

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
  string smallestNumber(string pattern) {
    // if pattern is empty return empty string
    if (pattern.empty()) {
      return "";
    }
    // now check linearly pattern
    // if I is encountered, then nums[i]<nums[i+1]
    // that is check for nums[i-1], add 1 to it and append to nums
    // if D is encountered, then nums[i]>nums[i+1]
    // that is check for nums[i+1], subtract 1 from it and append to nums
    string nums = "";
    for (int i = 0; i < pattern.size(); i++) {
      if (pattern[i] == 'I') {
        nums += to_string(i + 1);
      } else if (pattern[i] == 'D')
        nums += to_string(i);
    }
    return nums;
  }
};
// sub:
//  instead use a stack
class Solution1 {
public:
  string smallestNumber(string pattern) {
    int n = pattern.size();
    string result;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
      // Push number (1-based index)
      st.push(i + 1);

      // When 'I' is encountered or at the end, pop elements from the stack
      if (i == n || pattern[i] == 'I') {
        while (!st.empty()) {
          result += to_string(st.top());
          st.pop();
        }
      }
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/construct-smallest-number-from-di-string/submissions/1546851297/?envType=daily-question&envId=2025-02-18

int main() {
  string pattern1 = "IIIDIDDD";
  string pattern2 = "DDD";
  Solution obj;
  cout << pattern1 << endl;
  cout << obj.smallestNumber(pattern1) << endl;

  cout << endl;
  cout << pattern2 << endl;
  cout << obj.smallestNumber(pattern2) << endl;

  return 0;
}

// time: O(n)
// space: O(n)
// sol:
// https://leetcode.com/problems/construct-smallest-number-from-di-string/solutions/6435434/2375-construct-smallest-number-from-di-s-fvgl/
