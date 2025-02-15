/* 2698. Find the Punishment Number of an Integer

Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers
i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous
substrings such that the sum of the integer values of these substrings equals i.


Example 1:

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy
the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to
8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum
equal to 10 + 0 == 10. Hence, the punishment number of 10 is 1 + 81 + 100 = 182
Example 2:

Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy
the conditions in the statement:
- 1 since 1 * 1 = 1.
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0.
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478


Constraints:

1 <= n <= 1000*/

/*return partition no of n
partition no logic:
n^2
sum of digits of n^2=n
sum of all partition no is punishment no
Use a recursive algorithm that splits the number into two parts, generates all
possible partitions of each part recursively, and then combines them in all
possible ways.
*/
class Solution {
public:
  // Recursive function to check if we can partition numStr to sum to target
  bool canPartition(string numStr, int target, int index = 0,
                    int currentSum = 0) {
    if (index == numStr.length())
      return currentSum == target;

    int num = 0;
    for (int i = index; i < numStr.length(); i++) {
      num = num * 10 + (numStr[i] - '0'); // Forming the number
      if (canPartition(numStr, target, i + 1, currentSum + num))
        return true;
    }
    return false;
  }

  // Function to compute the punishment number
  int punishmentNumber(int n) {
    int totalPunishment = 0;
    for (int i = 1; i <= n; i++) {
      int squared = i * i;
      string numStr = to_string(squared);

      // Check if the squared number can be partitioned to sum to i
      if (canPartition(numStr, i)) {
        totalPunishment += squared;
      }
    }
    return totalPunishment;
  }
};

// sub:
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/submissions/1543424589/?envType=daily-question&envId=2025-02-15
// sol:
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/solutions/6423689/2698-find-the-punishment-number-of-an-in-mwou/

// time: O(n^2)
// Space: O(1)
