/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <string>
#include <vector>

using namespace std;

// given combination of digits
// return the corresponding combination of letters

// make a tree with traverse string, at each level add all cobminations
// of letters
// return the collection of leaf nodes

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) {
      return res;
    }

    // Define the mapping of digits to letters
    vector<string> digit_to_letters = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    string current_combination;
    backtrack(digits, digit_to_letters, 0, current_combination, res);
    return res;
  }

private:
  void backtrack(const string& digits, const vector<string>& digit_to_letters,
                 int index, string& current_combination, vector<string>& res) {
    // Base case: if current_combination has the same length as digits, we have
    // a valid combination
    if (index == digits.size()) {
      res.push_back(current_combination);
      return;
    }

    // Get the current digit
    char digit = digits[index];
    // Get the corresponding letters
    string letters = digit_to_letters[digit - '0'];

    // Iterate through each letter and recursively build combinations
    for (char letter : letters) {
      // Choose
      current_combination.push_back(letter);
      // Explore
      backtrack(digits, digit_to_letters, index + 1, current_combination, res);
      // Unchoose (backtrack)
      current_combination.pop_back();
    }
  }
};
// sub:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1531285366/
// optimised:
class Solution1 {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }

    vector<string> digit_to_letters = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> res = {""}; // Start with an empty string

    for (char digit : digits) {
      string letters = digit_to_letters[digit - '0'];
      vector<string> temp;

      for (const string& combination : res) {
        for (char letter : letters) {
          temp.push_back(combination + letter);
        }
      }
      res.swap(temp); // Efficiently swap contents to avoid copying
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1531287217/
// sol:
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/6375024/17-letter-combinations-of-a-phone-number-0sdm/
