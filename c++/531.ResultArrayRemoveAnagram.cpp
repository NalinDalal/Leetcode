/*2273. Find Resultant Array After Removing Anagrams
You are given a 0-indexed string array words, where words[i] consists of
lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i
- 1] and words[i] are anagrams, and delete words[i] from words. Keep performing
this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the
indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase using all the original letters exactly once. For example, "dacb"
is an anagram of "abdc".



Example 1:

Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following
operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2
and delete words[2]. Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1
and delete words[1]. Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and
delete words[2]. Now words = ["abba","cd"]. We can no longer perform any
operations, so ["abba","cd"] is the final answer. Example 2:

Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations
are performed.


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.

Hint 1
Instead of removing each repeating anagram, try to find all the strings in words
which will not be present in the final answer. Hint 2 For every index i, find
the largest index j < i such that words[j] will be present in the final answer.
Hint 3
Check if words[i] and words[j] are anagrams. If they are, then it can be
confirmed that words[i] will not be present in the final answer.
*/

// find i such that i-1,i index are anagram
// delete words[i]
// repeat until no more anagrams
// return words after all operations
// so do like check if i1 and i are anagrams, if found then delete i move to
// i-1, repeat for next word
class Solution {
public:
  vector<string> removeAnagrams(vector<string>& words) {
    vector<string> res;
    res.push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {
      string prev = res.back();
      string cur = words[i];

      sort(prev.begin(), prev.end());
      sort(cur.begin(), cur.end());

      if (prev != cur) {
        res.push_back(words[i]); // only push if not an anagram of last
      }
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/submissions/1800118079/?envType=daily-question&envId=2025-10-13
// sol:
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/solutions/7271299/2273-find-resultant-array-after-removing-ss76/
