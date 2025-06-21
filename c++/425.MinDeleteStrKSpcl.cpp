/* 3085. Minimum Deletions to Make String K-Special
You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all
indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes
the absolute value of y.

Return the minimum number of characters you need to delete to make word
k-special.



Example 1:

Input: word = "aabcaba", k = 0

Output: 3

Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1
occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') ==
freq('b') == 2.

Example 2:

Input: word = "dabdcbdcdcd", k = 2

Output: 2

Explanation: We can make word 2-special by deleting 1 occurrence of "a" and 1
occurrence of "d". Therefore, word becomes equal to "bdcbdcdcd" where freq('b')
== 2, freq('c') == 3, and freq('d') == 4.

Example 3:

Input: word = "aaabaaa", k = 2

Output: 1

Explanation: We can make word 2-special by deleting 1 occurrence of "b".
Therefore, word becomes equal to "aaaaaa" where each letter's frequency is now
uniformly 6.



Constraints:

1 <= word.length <= 105
0 <= k <= 105
word consists only of lowercase English letters.


Hint 1
Count the frequency of each letter.

Hint 2
Suppose we select several characters as the final answer, and let x be the
character with the smallest frequency in the answer. It can be shown that out of
the selected characters, the optimal solution will never delete an occurrence of
character x to obtain the answer.

Hint 3
We will fix a character c and assume that it will be the character with the
smallest frequency in the answer. Suppose its frequency is x.

Hint 4
Then, for every other character, we will count the number of occurrences that
will be deleted. Suppose that the current character has y occurrences. If y < x,
we need to delete all of them. if y > x + k, we should delete y - x - k of such
character. Otherwise we don’t need to delete it.
*/

// Delete the minimum number of characters from the string word such that the
// maximum difference in frequency between any two characters is at most k.

/* Approach
1. Count frequency of each character.

2. Try each possible target frequency (from 1 to max frequency), and for each
target:
    - For each character:
        - If its frequency > target + k → delete extra characters.
        - If its frequency < target → no deletion needed.
        - If within [target, target + k] → okay.

3. Sum the deletions and update the global minimum.
*/
class Solution {
public:
  int minimumDeletions(string word, int k) {
    unordered_map<char, int> freq;
    for (char c : word) {
      freq[c]++;
    }

    vector<int> counts;
    for (auto& [ch, count] : freq) {
      counts.push_back(count);
    }

    sort(counts.begin(), counts.end());

    int res = INT_MAX;
    int n = counts.size();

    for (int base = 1; base <= counts.back(); base++) {
      int deletions = 0;
      for (int f : counts) {
        if (f < base) {
          deletions += f;
        } else if (f > base + k) {
          deletions += f - (base + k);
        }
      }
      res = min(res, deletions);
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/submissions/1671041394/?envType=daily-question&envId=2025-06-21
// sol:
// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/solutions/6867131/3085-minimum-deletions-to-make-string-k-toj6a/
