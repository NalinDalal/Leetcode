/*2379. Minimum Recolors to Get K Consecutive Black Blocks

You are given a 0-indexed string blocks of length n, where blocks[i] is either
'W' or 'B', representing the color of the ith block. The characters 'W' and 'B'
denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive
black blocks.

In one operation, you can recolor a white block such that it becomes a black
block.

Return the minimum number of operations needed such that there is at least one
occurrence of k consecutive black blocks.



Example 1:
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and
4th blocks so that blocks = "BBBBBBBWBW". It can be shown that there is no way
to achieve 7 consecutive black blocks in less than 3 operations. Therefore, we
return 3.

Example 2:
Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.


Constraints:
n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n*/

/* Use a sliding window of size k.
Count the number of 'W' in the current window.
Slide the window across the string, updating the count by removing the leftmost
block and adding the new block. Track the minimum count of 'W' across all
windows.*/

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.length();
    int minOperations = INT_MAX;

    // Iterate through the string with a sliding window of size k
    for (int i = 0; i <= n - k; i++) {
      int whiteCount = 0;

      // Count the number of 'W's in the current window
      for (int j = i; j < i + k; j++) {
        if (blocks[j] == 'W') {
          whiteCount++;
        }
      }

      // Update the minimum number of operations
      minOperations = std::min(minOperations, whiteCount);
    }
    return minOperations;
  }
};

// Time: O(n)
// Space:O(1)
// sub:
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/submissions/1566744105/?envType=daily-question&envId=2025-03-08
// sol:
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/6512261/2379-minimum-recolors-to-get-k-consecuti-u3z6/
