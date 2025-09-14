/*966. Vowel Spellchecker
Given a wordlist, we want to implement a spellchecker that converts a query word
into a correct word.

For a given query word, the spell checker handles two categories of spelling
mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive),
then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the
query word with any vowel individually, it matches a word in the wordlist
(case-insensitive), then the query word is returned with the same case as the
match in the wordlist. Example: wordlist = ["YellOw"], query = "yollow": correct
= "YellOw" Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no
match) Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you
should return the same word back. When the query matches a word up to
capitlization, you should return the first such match in the wordlist. When the
query matches a word up to vowel errors, you should return the first such match
in the wordlist. If the query has no matches in the wordlist, you should return
the empty string. Given some queries, return a list of words answer, where
answer[i] is the correct word for query = queries[i].



Example 1:
Input: wordlist = ["KiTe","kite","hare","Hare"], queries =
["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"] Output:
["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]


Example 2:
Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]

Constraints:

1 <= wordlist.length, queries.length <= 5000
1 <= wordlist[i].length, queries[i].length <= 7
wordlist[i] and queries[i] consist only of only English letters.
*/

/*Approach:
1. Exact match (case-sensitive)
Use an unordered_set<string> to store all words.

2. Case-insensitive match
Use an unordered_map<string, string> mapping lowercased word → first word in
wordlist.

3. Vowel error match
Create a helper that converts a word into its vowel-masked version (replace
vowels a,e,i,o,u with a placeholder like *). Example: "YellOw" → "y*ll*w". Store
mapping from masked lowercase word → first word in wordlist.

4. Query resolution order:
- If query is in exact set → return query.
- Else if lowercase query is in case map → return stored word.
- Else if vowel-masked query is in vowel map → return stored word.
- Else → return "".
*/

class Solution {
public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> exact(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    auto toLower = [](const string& s) {
      string res = s;
      for (auto& c : res)
        c = tolower(c);
      return res;
    };

    auto maskVowels = [&](const string& s) {
      string res = s;
      for (int i = 0; i < res.size(); i++) {
        char lower = tolower(res[i]);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' ||
            lower == 'u') {
          res[i] = '*';
        } else {
          res[i] = lower;
        }
      }
      return res;
    };

    // Preprocess
    for (auto& w : wordlist) {
      string lower = toLower(w);
      if (!caseMap.count(lower))
        caseMap[lower] = w;

      string masked = maskVowels(w);
      if (!vowelMap.count(masked))
        vowelMap[masked] = w;
    }

    vector<string> ans;
    for (auto& q : queries) {
      if (exact.count(q)) {
        ans.push_back(q);
        continue;
      }
      string lower = toLower(q);
      if (caseMap.count(lower)) {
        ans.push_back(caseMap[lower]);
        continue;
      }
      string masked = maskVowels(q);
      if (vowelMap.count(masked)) {
        ans.push_back(vowelMap[masked]);
        continue;
      }
      ans.push_back("");
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/vowel-spellchecker/submissions/1770055718/?envType=daily-question&envId=2025-09-14
// sol:
// https://leetcode.com/problems/vowel-spellchecker/solutions/7187589/966-vowel-spellchecker-by-nalindalal2004-m86e/
