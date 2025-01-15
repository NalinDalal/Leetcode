/* https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

3403. Find the Lexicographically Largest String From the Box I

You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds
in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has
had the exact same split. All the split words are put into a box. Find the
lexicographically largest string from the box after all the rounds are finished.



Example 1:
Input: word = "dbca", numFriends = 2
Output: "dbc"
Explanation:

All possible splits are:
"d" and "bca".
"db" and "ca".
"dbc" and "a".

Example 2:
Input: word = "gggg", numFriends = 4
Output: "g"
Explanation:

The only possible split is: "g", "g", "g", and "g".



Constraints:
1 <= word.length <= 5 * 103
word consists only of lowercase English letters.
1 <= numFriends <= word.length*/

#include <algorithm>
#include <string>

using namespace std;

/*Approach:
1. Handle Base Cases :
- If numFriends == 1, the entire string can be returned as the result because
all friends can split without any constraints.

2. Find the Largest Character :
- Determine the lexicographically largest character in the string using
max_element. This narrows the search to specific positions.

3. Evaluate Substrings from Each Largest Character :
- Each occurrence of the largest character :
- Calculate maximum allowable length of substring starting at that position
based on the constraints.
- Generate the substring.
- Compare with the current maximum substring and update if it is larger.

4. Return the Result :
- After iterating through all occurrences of the largest character, return the
maximum substring found.
*/
class Solution {
public:
  string answerString(string word, int numFriends) {
    // Find lexicographically largest substring of size n - numFriends + 1 or
    // less starting at every index. if no such substring exists, return empty
    // string.
    // Step 1: Handle base case where all friends can split the string
    int N = word.size();
    if (numFriends == 1) {
      return word;
    }

    // Step 2: Find the lexicographically largest character in the string
    char c = *max_element(word.begin(), word.end());
    string max_string = "";

    // Step 3: Iterate through the positions of the largest character
    for (int pos = 0; pos < N; pos++) {
      if (word[pos] == c) {
        // Step 4: Compute the maximum allowable substring length from this
        // position
        int l_allowed = min((int)(N - pos), N - numFriends + 1);

        // Skip if no valid substring can be formed
        if (l_allowed <= 0) {
          continue;
        }

        // Step 5: Extract the substring and compare with the current maximum
        string s = word.substr(pos, l_allowed);
        if (s > max_string) {
          max_string = s; // Update the maximum string
        }
      }
    }

    // Step 6: Return the result
    return max_string;
  }
};

// Time Complexity: O(n*k)
// Space Complexity: O(n)
// 100%
// sub:
// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/submissions/1509292906/
// sol:
// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/solutions/6283708/3403-find-the-lexicographically-largest-h2y8f/
