/* 1718. Construct the Lexicographically Largest Valid Sequence
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of
i is exactly i. The distance between two numbers on the sequence, a[i] and a[j],
is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the
given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length)
if in the first position where a and b differ, sequence a has a number greater
than the corresponding number in b. For example, [0,1,9,0] is lexicographically
larger than [0,1,5,6] because the first position they differ is at the third
number, and 9 is greater than 5.


Example 1:
Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the
lexicographically largest valid sequence.

Example 2:
Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]


Constraints:1 <= n <= 20*/

// from i=0 to i=n
// log all number from 2 to n twice
// pair of i must me at distance of i

class Solution {
public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> result(2 * n - 1, 0); // Initialize result array with 0
    vector<bool> used(n + 1, false);  // Track used numbers
    backtrack(0, n, result, used);
    return result;
  }

private:
  bool backtrack(int index, int n, vector<int>& result, vector<bool>& used) {
    if (index == result.size())
      return true; // Successfully filled array

    if (result[index] != 0)
      return backtrack(index + 1, n, result, used); // Skip filled positions

    for (int num = n; num >= 1; --num) {
      if (used[num])
        continue; // Skip already used numbers

      int secondIndex =
          (num > 1) ? index + num : index; // Compute second position
      if (secondIndex < result.size() && result[secondIndex] == 0) {
        result[index] = result[secondIndex] = num;
        used[num] = true;

        if (backtrack(index + 1, n, result, used))
          return true; // Recur for next position

        // Backtrack
        result[index] = result[secondIndex] = 0;
        used[num] = false;
      }
    }
    return false;
  }
};
// Time: O(n^2)
// Space:O(n)
// sub:
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/submissions/1544799307/?envType=daily-question&envId=2025-02-16
// sol:
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/solutions/6428448/1718-construct-the-lexicographically-lar-206c/
