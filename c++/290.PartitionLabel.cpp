/*763. Partition Labels

You are given a string s. We want to partition the string into as many parts as
possible so that each letter appears in at most one part. For example, the
string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as
["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in
order, the resultant string should be s.

Return a list of integers representing the size of these parts.

Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits
s into less parts.

Example 2:
Input: s = "eccbbbbdec"
Output: [10]


Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.*/

// problem requires us to divide a string s into as many parts as possible so
// that each letter appears in at most one part. The output should be a list of
// partition sizes.

// Solution
/* 1. Find Last Occurrence of Each Character:
- Store the last index of each character in s.
2. Traverse the String and Create Partitions:
- Maintain two pointers:
    - start: Marks the beginning of a partition.
    - end: The farthest last occurrence of any character in the current
partition.
- Expand the partition until we reach end, then add the partition size to the
result.*/
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> lastIndex(26, 0);
    vector<int> result;

    // Step 1: Store last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
      lastIndex[s[i] - 'a'] = i;
    }

    // Step 2: Traverse and partition
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
      end = max(end, lastIndex[s[i] - 'a']); // Update the furthest boundary

      if (i == end) { // When we reach the end of the partition
        result.push_back(end - start + 1);
        start = i + 1; // Move to the next partition
      }
    }

    return result;
  }
};
// sub: https://leetcode.com/problems/partition-labels/submissions/1568033789/
// sol:
// https://leetcode.com/problems/partition-labels/solutions/6517178/763-partition-labels-by-nalindalal2004-98is/
