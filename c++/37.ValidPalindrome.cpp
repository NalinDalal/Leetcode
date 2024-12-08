/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

// Approach
/*
 first remove all non-alphanumeric characters.
 what i can deduce is that we need to traverse the string from both side, 2
 pointer, if any place no match return false, else return false

*/

/*
 class Solution {
public:
    bool isPalindrome(string s) {
        std::regex_replace(s, std::regex("\\s+"), "");
        for(int i=0;i<s.length();i++){
            if(s[i]==s[s.length()-i]){
                return true;
            }
        }
        return false;
    }
};


Problem with it->
s = "race a car"
Output=true
Expected=false

well we need to check by different method
see as soon as if checks that 1st iteration is it gives true which causes error

do it like this that if it is not equal return false
else carry on and return true;

Input
s =" "
Output=false
Expected=true
*/

class Solution {
public:
  bool isPalindrome(string s) {
    // std::regex_replace(s, std::regex("\\s+"), "");
    // filter all non-alphanumeric symbols
    std::string filtered;
    for (char c : s) {
      if (std::isalnum(c)) { // Check if the character is alphanumeric
        filtered +=
            std::tolower(c); // Convert to lowercase and add to filtered string
      }
    }

    // s = std::regex_replace(s, std::regex("\\s+"), "");

    int n = filtered.length();

    // empty string
    if (n == 0) {
      return true;
    }

    // non empty string
    for (int i = 0; i < n / 2; i++) {
      if (filtered[i] != filtered[n - 1 - i]) {
        return false; // Found a mismatch, not a palindrome
      }
    }
    return true; // If no mismatches found, it's a palindrome
  }
};
