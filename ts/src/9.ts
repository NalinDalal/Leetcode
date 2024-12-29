// link:
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/?envType=daily-question&envId=2024-12-29
/* 1639. Number of Ways to Form a Target String Given a Dictionary

You are given a list of strings of the same length words and a string target.
Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth
character of the jth string in words if target[i] = words[j][k]. Once you use
the kth character of the jth string of words, you can no longer use the xth
character of any string in words where x <= k. In other words, all characters to
the left of or at index k become unusuable for every string. Repeat the process
until you form the string target. Notice that you can use multiple characters
from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too
large, return it modulo 109 + 7.



Example 1:
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")


Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.
*/

// what to do:
// int count=0
// target[i] = words[j][k]
// x>=k{use only char greater than k index}
// repeat till target forms
// return count

/* approach is an iterative version of DP with optimized space.
# Approach
1. Declare the state matrix dp as a global variable
2. Declare freq[26][1000] = {0} as a member variable
3. Define int f(int i, int j, const vector<string>& words, const string& target)
as a recursive function to compute dp[i][j] by using take & skip argument
4. In numWays count freq by a double-loop
5. the answer is f(n, m, words, target)
6. An iterative DP version is made.
*/
function numWays(words: string[], target: string): number {
  let mod: number = 1e9 + 7;
  let m: number = target.length,
    n = words[0].length;

  //count freq
  let freq: number[][] = Array.from({ length: 26 }, () => Array(1000).fill(0));

  for (let i = 0; i < n; i++) {
    for (const w of words) {
      freq[w.charCodeAt(i) - "a".charCodeAt(0)][i]++;
    }
  }

  let dp: number[] = Array(m + 1).fill(0);
  dp[0] = 1;

  for (let i: number = 0; i < n; i++) {
    //traverse target from back to front to avoid overwriting
    for (let j = m; j >= 1; j--) {
      //let fc:number=freq[target[j-1]-'a'][i]; //avoid overflow
      let fc: number = freq[target.charCodeAt(j - 1) - "a".charCodeAt(0)][i]; //avoid overflow
      dp[j] = (dp[j] + dp[j - 1] * fc) % mod;
    }
  }
  return dp[m];
}
