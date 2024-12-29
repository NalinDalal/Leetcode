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

/* class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int MOD=1e9+7;
        int T=target.size();
        int N=words.size();
// windex -> 8 to L
// tindex -> 0 to T
// O(L * T) number of inputs
// O(N) is the work per input
// total complexity = 0(L * T * N)
        int count(windex,tindex){
            if(tindex==T)
                return 1;
            if(windex==N)
                return 0;

            int total=0;
            //Take
            for(int i=0;i<N;i++){
                if(words[i][windex]==target[i][windex]){
                    total+=count(windex+1,tindex+1);
                    total%=MOD;
                }
            }
            //No Take
            total+=count(windex+1,tindex);
            total%=MOD;
            return total;
        }
        return count(0,0)%MOD;
    }
};*/

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
class Solution {
public:
  static int numWays(vector<string>& words, string& target) {
    const int mod = 1e9 + 7;
    const int m = target.size(), n = words[0].size();

    // count freq
    int freq[26][1000] = {0};
    for (int i = 0; i < n; i++) {
      for (const auto& w : words)
        freq[w[i] - 'a'][i]++;
    }

    // 1D DP array for optimization
    int dp[1001] = {0};
    dp[0] = 1; // Base case

    for (int i = 0; i < n; i++) {
      // Traverse target from back to front to avoid overwriting
      for (int j = m; j >= 1; j--) {
        long long fc = freq[target[j - 1] - 'a'][i]; // avoid of overflowing
        dp[j] = (dp[j] + dp[j - 1] * fc) % mod;
      }
    }
    return dp[m];
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)-> O(m)
// 98.54%
