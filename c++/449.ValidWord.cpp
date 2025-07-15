/*3136. Valid Word
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.


Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.



Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and
'$'.

Hint 1
Use if-else to check all the conditions.
*/

/*Rejects words under 3 characters

Ensures only letters and digits

Ensures at least one vowel

Ensures at least one consonant
*/

class Solution {
public:
  bool isValid(string word) {
    if (word.length() < 3)
      return false;

    bool hasVowel = false, hasConsonant = false;
    for (char c : word) {
      if (!isalnum(c))
        return false; // only digits and letters

      char lower = tolower(c);
      if (isalpha(c)) {
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' ||
            lower == 'u') {
          hasVowel = true;
        } else {
          hasConsonant = true;
        }
      }
    }
    return hasVowel && hasConsonant;
  }
};
// sub:
// https://leetcode.com/problems/valid-word/submissions/1698423923/?envType=daily-question&envId=2025-07-15
// sol:
// https://leetcode.com/problems/valid-word/solutions/6960738/3136-valid-word-by-nalindalal2004-cdo5/
