/* 2901. Longest Unequal Adjacent Groups Subsequence II
You are given a string array words, and an array groups, both arrays having
length n.

The hamming distance between two strings of equal length is the number of
positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ...,
n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having
length k, the following holds:

For adjacent indices in the subsequence, their corresponding groups are unequal,
i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k. words[ij] and
words[ij+1] are equal in length, and the hamming distance between them is 1,
where 0 < j + 1 < k, for all indices in the subsequence. Return a string array
containing the words corresponding to the indices (in order) in the selected
subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.



Example 1:

Input: words = ["bab","dab","cab"], groups = [1,2,2]

Output: ["bab","cab"]

Explanation: A subsequence that can be selected is [0,2].

groups[0] != groups[2]
words[0].length == words[2].length, and the hamming distance between them is 1.
So, a valid answer is [words[0],words[2]] = ["bab","cab"].

Another subsequence that can be selected is [0,1].

groups[0] != groups[1]
words[0].length == words[1].length, and the hamming distance between them is 1.
So, another valid answer is [words[0],words[1]] = ["bab","dab"].

It can be shown that the length of the longest subsequence of indices that
satisfies the conditions is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,2,3,4]

Output: ["a","b","c","d"]

Explanation: We can select the subsequence [0,1,2,3].

It satisfies both conditions.

Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].

It has the longest length among all subsequences of indices that satisfy the
conditions.

Hence, it is the only answer.



Constraints:

1 <= n == words.length == groups.length <= 1000
1 <= words[i].length <= 10
1 <= groups[i] <= n
words consists of distinct strings.
words[i] consists of lowercase English letters.
*/

// find all subsequnces
// apply condition, which statisfy append into array
// return the array
// condition: groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k;
//           words[ij] and words[ij+1] are equal in length, and the hamming
//           distance between them is 1, where 0 < j + 1 < k, for all indices in
//           the subsequence.

// Approach:
/*

Let `dp[i]` represent the length of the **longest subsequence** ending at index
`i`, and let `HammingDistance(s, t)` represent the Hamming distance between two
strings `s` and `t`. If index `i` can be added after index `j` in the
subsequence, then it must satisfy `groups[i] ≠ groups[j]` for `j < i`, and
`HammingDistance(words[i], words[j]) = 1`. When these conditions hold, the
length of the **longest subsequence** ending at index `i` is updated as:

```

dp\[i] = max(dp\[i], dp\[j] + 1)

```

We can obtain the dynamic programming recurrence formula as follows:

```

dp\[i] = max(dp\[i], dp\[j] + 1)  if groups\[i] ≠ groups\[j],
HammingDistance(words\[i], words\[j]) = 1

```

For each index `i`, we enumerate the indices before `i` to find the length of
the **longest subsequence** ending at `i`. By performing this for each index, we
can find the length of the **longest subsequence** in `[0, 1, ..., n−1]`. To
facilitate the calculation, we use `prev[i]` to record the index of the previous
index in the **longest subsequence** ending at `i`. Once we identify the ending
index `i` of the **longest subsequence**, we can trace back through the indices
to recover the entire subsequence and add the corresponding strings to an array.
Reversing this array gives us the final answer.



*/

class Solution {
public:
  vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                              vector<int>& groups) {
    int n = groups.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] &&
            groups[i] != groups[j]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[maxIndex]) {
        maxIndex = i;
      }
    }

    vector<string> ans;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
      ans.emplace_back(words[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  bool check(string& s1, string& s2) {
    if (s1.size() != s2.size()) {
      return false;
    }
    int diff = 0;
    for (int i = 0; i < s1.size(); i++) {
      diff += s1[i] != s2[i];
      if (diff > 1) {
        return false;
      }
    }
    return diff == 1;
  }
};
// sub:
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/submissions/1635248155/?envType=daily-question&envId=2025-05-16
