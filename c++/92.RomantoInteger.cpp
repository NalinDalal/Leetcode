/* 13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.



Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].*/

// JS COde:
/*function romanToInt(romanNumeral) {
  // Create a mapping of Roman numerals and their corresponding values
  const romanValues = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
  };

  let result = 0;

  // Loop through the Roman numeral from left to right
  for (let i = 0; i < romanNumeral.length; i++) {
    const currentVal = romanValues[romanNumeral[i]];
    const nextVal = romanValues[romanNumeral[i + 1]];

    // If the current value is less than the next value, subtract it
    if (currentVal < nextVal) {
      result -= currentVal;
    } else {
      result += currentVal;
    }
  }

  return result;
}*/

// C++ Code:

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    // Make a map of roman numerals and their corresponding values
    map<char, int> romanValues = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    // Loop through the roman numeral from left to right
    for (int i = 0; i < s.length(); i++) {
      // Get the current value of roman numerals
      int currentVal = romanValues[s[i]];
      // Get the next value of roman numerals
      int nextVal = romanValues[s[i + 1]];
      // If the current value is less than the next value, subtract it
      if (currentVal < nextVal) {
        result -= currentVal;
      } else {
        result += currentVal;
      }
    }
    return result;
  }
};

// Optimized code:
/*
Avoid Potential Out-of-Bounds Access:
When accessing s[i + 1] in the loop, ensure that i + 1 does not exceed the
string length to prevent undefined behavior.

Use an Array Instead of std::map:
Accessing values from a map is logarithmic in complexity, O(logn), whereas
accessing elements in an array (or unordered_map) is  O(1). Use an array to
store the Roman numeral values.

Remove Redundant Lookups:
Store s[i + 1] in a temporary variable to avoid looking it up multiple times in
the map or array.*/

class Solution2 {
public:
  int romanToInt(string s) {
    // Array for Roman numeral values
    int romanValues[256] = {};
    romanValues['I'] = 1;
    romanValues['V'] = 5;
    romanValues['X'] = 10;
    romanValues['L'] = 50;
    romanValues['C'] = 100;
    romanValues['D'] = 500;
    romanValues['M'] = 1000;

    int result = 0;
    int n = s.length();

    // Loop through the Roman numeral string
    for (int i = 0; i < n; i++) {
      int currentVal = romanValues[s[i]];
      int nextVal =
          (i + 1 < n) ? romanValues[s[i + 1]] : 0; // Safely get next value

      if (currentVal < nextVal) {
        result -= currentVal; // Subtract if current value is less than next
      } else {
        result += currentVal; // Otherwise, add the current value
      }
    }

    return result;
  }
};
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
  Solution sol1;
  Solution sol2;

  string s1 = "III";
  string s2 = "LVIII";
  string s3 = "MCMXCIV";

  cout << "Solution 1:" << endl;
  cout << s1 << " -> " << sol1.romanToInt(s1) << endl;
  cout << s2 << " -> " << sol1.romanToInt(s2) << endl;
  cout << s3 << " -> " << sol1.romanToInt(s3) << endl;

  cout << "Solution 2(83.26%):" << endl;
  cout << s1 << " -> " << sol2.romanToInt(s1) << endl;
  cout << s2 << " -> " << sol2.romanToInt(s2) << endl;
  cout << s3 << " -> " << sol2.romanToInt(s3) << endl;
  return 0;
}
