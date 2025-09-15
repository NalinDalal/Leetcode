/*1935. Maximum Number of Words You Can Type

There is a malfunctioning keyboard where some letter keys do not work. All other
keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing
spaces) and a string brokenLetters of all distinct letter keys that are broken,
return the number of words in text you can fully type using this keyboard.



Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.


Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or
trailing spaces. Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.

Hint 1
Check each word separately if it can be typed.
Hint 2
A word can be typed if all its letters are not broken.

*/

/* initialise ans=0
 breake the `text` into separate words
 push them into a vector
 now for each word in vector, check if any substring from `brokenLetters` is
 part of vector[i] if yes then skip, else ans++

 return ans
*/
class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    // Store broken letters in a set for quick lookup
    unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

    stringstream ss(text);
    string word;
    int ans = 0;

    while (ss >> word) {
      bool canType = true;
      for (char c : word) {
        if (broken.count(c)) { // if word contains a broken letter
          canType = false;
          break;
        }
      }
      if (canType)
        ans++;
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/submissions/1771047245/?envType=daily-question&envId=2025-09-15
// sol:
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/solutions/7190686/1935-maximum-number-of-words-you-can-typ-zy8j/
