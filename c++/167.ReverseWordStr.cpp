/* https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be
separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between
two words. The returned string should only have a single space separating the
words. Do not include any extra spaces.


Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single
space in the reversed string.


Constraints:
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it
in-place with O(1) extra space?*/

// to reverse the order of words,
// trim leading and trailing spaces
// split string into array of words with spaces
// reverse the array
// join the array and return it

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    // Trim leading and trailing spaces
    trim(s);

    // Split string into words
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word)
      words.push_back(word);

    // Reverse the array of words
    reverse(words.begin(), words.end());

    // Join the array and return it
    return join(words.begin(), words.end(), " ");
  }

private:
  void trim(string& s) {
    // Remove leading spaces
    s.erase(s.begin(), find_if(s.begin(), s.end(),
                               [](unsigned char ch) { return !isspace(ch); }));
    // Remove trailing spaces
    s.erase(find_if(s.rbegin(), s.rend(),
                    [](unsigned char ch) { return !isspace(ch); })
                .base(),
            s.end());
  }

  string join(vector<string>::iterator begin, vector<string>::iterator end,
              const string& delim) {
    string result;
    while (begin != end) {
      result += *begin;
      ++begin;
      if (begin != end)
        result += delim;
    }
    return result;
  }
};

// Time: O(n)
// Space: O(1)
