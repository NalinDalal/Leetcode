/* 2559. Count Vowel Strings in Ranges

You are given a 0-indexed array of strings words and a 2D array of integers
queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present
in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the
ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.



Example 1:
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa"
and "e". The answer to the query [0,2] is 2 (strings "aba" and "ece"). to query
[1,4] is 3 (strings "ece", "aa", "e"). to query [1,1] is 0. We return [2,3,0].

Example 2:
Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].


Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    // step 1: create the array asked
    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      ans[i] = 0;
    }
    // step 2: create a map to store the vowels
    new unordered_map<char, int> vowels;
    vowels['a'] = 1;
    vowels['e'] = 1;
    vowels['i'] = 1;
    vowels['o'] = 1;
    vowels['u'] = 1;
    // step 3: iterate through the words
    for (int i = 0; i < words.size(); i++) { // words Text
      // step 3.1: iterate through the vowels
        for(int j=0;j<words[il.size();j++){
          if (vowels[words[i][j]] ==
              1) { // step 3.2: iterate through the queries
            for (int k = 0; k < queries.size(); k++) {
              // step 3.2.1: check if the query is satisfied
              if (queries[k][0] <= i && queries[k][1] >= i) {
                ans[k]++;
              }
            }
          }
        }
        return ans;
    }
  }
};

// wrong
// what to do:
// We can use a prefix sum array to precompute the count of "vowel-only" strings
// up to each index. For each query, we then subtract the counts at the
// endpoints to get the result in O(1) time per query.
class Solution1 {
public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    // Step 1: Function to check if a string starts and ends with vowels
    auto isVowelString = [](const string& word) {
      char start = word.front();
      char end = word.back();
      return (start == 'a' || start == 'e' || start == 'i' || start == 'o' ||
              start == 'u') &&
             (end == 'a' || end == 'e' || end == 'i' || end == 'o' ||
              end == 'u');
    };

    // Step 2: Create a prefix sum array
    int n = words.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefixSum[i + 1] = prefixSum[i] + (isVowelString(words[i]) ? 1 : 0);
    }

    // Step 3: Process each query
    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int left = queries[i][0];
      int right = queries[i][1];
      ans[i] = prefixSum[right + 1] - prefixSum[left];
    }

    return ans;
  }
};

// 100%
//  Time: O(n+q), n=sum(words.length), q=queries.length
//  Space: O(n), n=sum(words.length)
