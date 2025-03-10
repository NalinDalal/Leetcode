/* 3306. Count of Substrings Containing Every Vowel and K Consonants II
You are given a string word and a non-negative integer k.
Return the total number of substrings of word that contain every vowel ('a',
'e', 'i', 'o', and 'u') at least once and exactly k consonants.

Example 1:
Input: word = "aeioqq", k = 1
Output: 0
Explanation:
There is no substring with every vowel.

Example 2:
Input: word = "aeiou", k = 0
Output: 1
Explanation:
The only substring with every vowel and zero consonants is word[0..4], which is
"aeiou".

Example 3:
Input: word = "ieaouqqieaouqq", k = 1
Output: 3

Explanation:
The substrings with every vowel and one consonant are:
word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".


Constraints:
5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k<= word.length - 5*/

// first of all we need to have all vowels in the string
// then check for exactly k consonants
// return no of substrings
// use sliding window and binary search
// For each index r, find the maximum l such that both conditions are satisfied
// using binary search.

#include <string>
using namespace std;

/*Hint 1-We can use sliding window and binary search.
Hint 2-For each index r, find the maximum l such that both conditions are
satisfied using binary search.*/

// Approach
/* 🔹 Sliding Window + Two Pointers: We expand the window until conditions are
met, then shrink to find all valid substrings efficiently. 🔹 Frequency Arrays:
Used to track vowels and consonants efficiently. 🔹 Extra Consonants Handling:
We move left when consonants exceed k. 🔹 Counting Extra Left: To count all
substrings ending at right efficiently.
*/
class Solution {
public:
  long long countOfSubstrings(string word, int k) {
    int frequencies[2][128] = {};
    frequencies[0]['a'] = frequencies[0]['e'] = frequencies[0]['i'] =
        frequencies[0]['o'] = frequencies[0]['u'] = 1;

    long long response = 0;
    int currentK = 0, vowels = 0, extraLeft = 0, left = 0;

    for (int right = 0; right < word.length(); right++) {
      char rightChar = word[right];

      if (frequencies[0][rightChar]) {
        if (++frequencies[1][rightChar] == 1)
          vowels++;
      } else {
        currentK++;
      }

      while (currentK > k) {
        char leftChar = word[left++];
        if (frequencies[0][leftChar]) {
          if (--frequencies[1][leftChar] == 0)
            vowels--;
        } else {
          currentK--;
        }
        extraLeft = 0;
      }

      while (vowels == 5 && currentK == k && left < right &&
             frequencies[0][word[left]] && frequencies[1][word[left]] > 1) {
        extraLeft++;
        frequencies[1][word[left++]]--;
      }

      if (currentK == k && vowels == 5) {
        response += (1 + extraLeft);
      }
    }

    return response;
  }
};
// Time: O(n^2)
// Space: O(n)
// sub:
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/submissions/1568941036/?source=submission-ac
// sol:
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/solutions/6520068/3306-count-of-substrings-containing-ever-udsj/
