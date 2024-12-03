/* 28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.


Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0,
so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0; // If needle is empty, return 0

    // If needle is longer than haystack, it can't possibly match
    if (needle.size() > haystack.size())
      return -1;

    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
      if (haystack.substr(i, needle.size()) == needle) {
        return i; // Found the first occurrence of needle
      }
    }

    return -1; // Return -1 if needle is not found
  }
};

// instead of using a char by char use substr function;

class Solution1 {

public:
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0; // If needle is empty, return 0

    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
      if (haystack.substr(i, needle.size()) == needle) {
        return i; // Found the first occurrence of needle
      }
    }

    return -1; // Return -1 if needle is not found
  }
};

int main() {
  Solution1 s;
  cout << "Testcase 1:" << endl;
  string haystack1 = "sadbutsad", needle1 = "sad";
  cout << haystack1 << " " << needle1 << endl;
  cout << s.strStr(haystack1, needle1) << endl;

  cout << endl;
  cout << "Testcase 2:" << endl;
  string haystack2 = "leetcode", needle2 = "leeto";
  cout << haystack2 << " " << needle2 << endl;
  cout << s.strStr(haystack2, needle2) << endl;

  return 0;
}

// Either check char by char is needle is part of haystack or not
// but we can actually use substr function to check
// one test case if needle.size() is greater than haystack.size() return -1

// 100%
// Time Complexity: O(n)
// Space Complexity: O(1)
