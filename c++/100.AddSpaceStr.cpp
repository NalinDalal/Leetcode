/* 2109. Adding Spaces to a String

You are given a 0-indexed string s and a 0-indexed integer array spaces that
describes the indices in the original string where spaces will be added. Each
space should be inserted before the character at the given index.

For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces
before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain
"Enjoy Your Coffee". Return the modified string after the spaces have been
added.


Example 1:
Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation:
The indices 8, 13, and 15 correspond to the underlined characters in
"LeetcodeHelpsMeLearn". We then place spaces before those characters.

Example 2:
Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"
Explanation:
The indices 1, 5, 7, and 9 correspond to the underlined characters in
"icodeinpython". We then place spaces before those characters.

Example 3:
Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
Explanation:
We are also able to place spaces before the first character of the string.


Constraints:
1 <= s.length <= 3 * 105
s consists only of lowercase and uppercase English letters.
1 <= spaces.length <= 3 * 105
0 <= spaces[i] <= s.length - 1
All the values of spaces are strictly increasing. */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parse the arraay of spaces
// sort the array
// Traverse the string and insert spaces at the specified indices while
// maintaining proper offset due to previously inserted spaces.

class Solution {
public:
  string addSpaces(string s, vector<int>& spaces) {
    string result;
    int spaceIndex = 0; // Pointer to track positions in the spaces vector
    int n = spaces.size();

    for (int i = 0; i < s.size(); i++) {
      // Check if the current index matches an index in the spaces array
      if (spaceIndex < n && i == spaces[spaceIndex]) {
        result += " "; // Add a space
        spaceIndex++;  // Move to the next space index
      }
      result += s[i]; // Add the current character
    }

    return result;
  }
};

// Helper function to print a vector
string printVector(const vector<int>& vec) {
  string result = "{";
  for (int i = 0; i < vec.size(); i++) {
    result += to_string(vec[i]);
    if (i != vec.size() - 1)
      result += ", ";
  }
  result += "}";
  return result;
}

int main() {
  Solution s;

  string s1 = "helloworld";
  vector<int> spaces1 = {5};

  string s2 = "ilovecoding";
  vector<int> spaces2 = {1, 5, 8};

  string s3 = "debuggingisfun";
  vector<int> spaces3 = {3, 9};

  cout << "s1: " << s1 << "\nspaces1: " << printVector(spaces1) << "\n";
  cout << s.addSpaces(s1, spaces1) << "\n\n";

  cout << "s2: " << s2 << "\nspaces2: " << printVector(spaces2) << "\n";
  cout << s.addSpaces(s2, spaces2) << "\n\n";

  cout << "s3: " << s3 << "\nspaces3: " << printVector(spaces3) << "\n";
  cout << s.addSpaces(s3, spaces3) << "\n";

  return 0;
}

// Time complexity: $$O(n)$$
// Space complexity: $$O(n)$$
